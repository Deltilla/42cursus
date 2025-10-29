/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:16 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/29 19:18:44 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

// ============================================================================
// ORTHODOX CANONICAL FORM IMPLEMENTATION (Constructor/Destructor Section)
// ============================================================================

/// Constructor: Initializes all member variables.
BitcoinExchange::BitcoinExchange() {
  // Empty STL containers are automatically initialized via default constructors.
}

/// Copy Constructor: Uses member initializer list for deep container copy.
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : price_data_(other.price_data_), input_data_(other.input_data_) {
  // STL multimap containers provide automatic deep copying.
}

/// Assignment Operator: Implements self-check and container assignment.
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    price_data_ = other.price_data_;
    input_data_ = other.input_data_;
  }
  return *this;
}

/// Destructor: STL containers handle automatic resource deallocation.
BitcoinExchange::~BitcoinExchange() {
  // No manual cleanup needed; STL containers auto-destruct.
}

// ============================================================================
// PRIVATE HELPER METHODS (Validation Section)
// ============================================================================

/// Trims leading and trailing whitespace from input string.
std::string BitcoinExchange::TrimWhitespace(const std::string& str) const {
  size_t start = str.find_first_not_of(" \t\r\n");
  if (start == std::string::npos)
    return "";

  size_t end = str.find_last_not_of(" \t\r\n");
  return str.substr(start, end - start + 1);
}

/// Validates that date string matches YYYY-MM-DD format.
bool BitcoinExchange::IsValidDate(const std::string& date) const {
  if (date.length() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;

  for (size_t i = 0; i < date.length(); ++i) {
    if (i == 4 || i == 7)
      continue;
    if (date[i] < '0' || date[i] > '9')
      return false;
  }
  return true;
}

/// Validates and converts string to double value.
/// Returns false if string is empty, contains non-numeric data, or has garbage.
bool BitcoinExchange::IsValidNumber(const std::string& str,
                                    double& value) const {
  if (str.empty())
    return false;

  std::istringstream iss(str);
  if (!(iss >> value))
    return false;

  // Verify entire string was consumed (reject extra characters).
  std::string remainder;
  if (iss >> remainder)
    return false;

  return true;
}

// ============================================================================
// PRIVATE HELPER METHODS (Parsing Section)
// ============================================================================

/// Parses price CSV line format: "YYYY-MM-DD,value"
/// Returns false for header lines or malformed entries.
bool BitcoinExchange::ParsePriceLine(const std::string& line,
                                     std::string& date, double& price) {
  // Skip header row detection.
  if (line.find("date") != std::string::npos ||
      line.find("value") != std::string::npos) {
    return false;
  }

  size_t delim_pos = line.find(',');
  if (delim_pos == std::string::npos)
    return false;

  date = line.substr(0, delim_pos);
  std::string price_str = line.substr(delim_pos + 1);

  if (!IsValidDate(date))
    return false;

  if (!IsValidNumber(price_str, price))
    return false;

  if (price < 0.0)
    return false;

  return true;
}

/// Parses input transaction line format: "YYYY-MM-DD | quantity"
/// Populates entry struct with validation results or error messages.
void BitcoinExchange::ParseInputLine(const std::string& line,
                                     InputEntry& entry) {
  entry.is_valid = false;
  entry.date = "";
  entry.quantity = 0.0;
  entry.error_message = "";

  // Skip header row detection.
  if (line.find("date") != std::string::npos ||
      line.find("value") != std::string::npos) {
    return;
  }

  // Locate pipe delimiter (mandatory field separator).
  size_t delim_pos = line.find('|');
  if (delim_pos == std::string::npos) {
    entry.error_message = "Error: bad input => " + line;
    return;
  }

  // Extract and trim date and quantity fields.
  std::string date_str = TrimWhitespace(line.substr(0, delim_pos));
  std::string quantity_str =
      TrimWhitespace(line.substr(delim_pos + 1));

  if (date_str.empty()) {
    entry.error_message = "Error: bad input => " + line;
    return;
  }

  if (quantity_str.empty()) {
    entry.error_message = "Error: bad input => " + line;
    return;
  }

  // Validate date format.
  if (!IsValidDate(date_str)) {
    entry.error_message = "Error: bad input => " + line;
    return;
  }

  // Parse and validate quantity numeric value.
  double quantity;
  if (!IsValidNumber(quantity_str, quantity)) {
    entry.error_message = "Error: bad input => " + line;
    return;
  }

  // Validate quantity is non-negative.
  if (quantity < 0.0) {
    entry.date = date_str;
    entry.quantity = quantity;
    entry.error_message = "Error: not a positive number.";
    return;
  }

  // Validate quantity does not exceed INT_MAX.
  if (quantity > 2147483647.0) {
    entry.date = date_str;
    entry.quantity = quantity;
    entry.error_message = "Error: too large a number.";
    return;
  }

  // Entry passed all validations.
  entry.date = date_str;
  entry.quantity = quantity;
  entry.is_valid = true;
}

// ============================================================================
// PRIVATE HELPER METHODS (Search/Format Section)
// ============================================================================

/// Finds price for date using lower_bound interpolation.
/// If exact date exists, returns that price.
/// Otherwise returns price of closest earlier date.
double BitcoinExchange::FindPriceForDate(const std::string& date,
                                         bool& found) const {
  found = false;

  PriceDataMap::const_iterator it = price_data_.lower_bound(date);

  // Exact match case.
  if (it != price_data_.end() && it->first == date) {
    found = true;
    return it->second;
  }

  // Cannot interpolate (no earlier date available).
  if (it == price_data_.begin())
    return 0.0;

  // Use closest earlier date.
  --it;
  found = true;
  return it->second;
}

/// Formats transaction output line: "YYYY-MM-DD => quantity = result"
std::string BitcoinExchange::FormatOutput(const std::string& date,
                                          double quantity,
                                          double price) const {
  std::ostringstream oss;
  oss << date << " => " << quantity << " = " << (quantity * price);
  return oss.str();
}

// ============================================================================
// PUBLIC INTERFACE METHODS
// ============================================================================

/// Loads price data from CSV file; skips malformed lines.
bool BitcoinExchange::LoadPriceData(const std::string& file_path) {
  std::ifstream file(file_path.c_str());

  if (!file.is_open()) {
    std::cerr << "Error: could not open file " << file_path << std::endl;
    return false;
  }

  price_data_.clear();

  std::string line;
  while (std::getline(file, line)) {
    std::string date;
    double price;

    // Skip header and malformed lines.
    if (!ParsePriceLine(line, date, price))
      continue;

    price_data_.insert(std::make_pair(date, price));
  }

  file.close();
  return true;
}

/// Loads input transactions from file; processes all entries (valid/error).
bool BitcoinExchange::LoadInputData(const std::string& file_path) {
  std::ifstream file(file_path.c_str());

  if (!file.is_open()) {
    std::cerr << "Error: could not open file " << file_path << std::endl;
    return false;
  }

  input_data_.clear();

  std::string line;
  int line_index = 0;
  while (std::getline(file, line)) {
    InputEntry entry;

    ParseInputLine(line, entry);
    entry.line_index = line_index;

    // Skip header lines only (entries with no error message and not valid).
    if (entry.error_message.empty() && !entry.is_valid) {
      line_index++;
      continue;
    }

    input_data_.insert(std::make_pair(entry.date, entry));
    line_index++;
  }

  file.close();
  return true;
}

// ============================================================================
// MAIN PROCESSING METHOD
// ============================================================================

/// Processes all transactions; outputs in original input file order.
/// Displays exchange results for valid entries; error messages for invalid.
void BitcoinExchange::ProcessExchange() {
  // Create temporary multimap to reorder entries by original file line index.
  // This ensures output respects input file sequence, not sorted container order.
  std::multimap<int, InputDataMap::iterator> ordered_entries;

  for (InputDataMap::iterator it = input_data_.begin();
       it != input_data_.end(); ++it) {
    ordered_entries.insert(
        std::make_pair(it->second.line_index, it));
  }

  // Process and output entries in their original file order.
  for (std::multimap<int, InputDataMap::iterator>::iterator
           ord_it = ordered_entries.begin();
       ord_it != ordered_entries.end(); ++ord_it) {
    InputDataMap::iterator it = ord_it->second;
    const InputEntry& entry = it->second;

    // Output error message for invalid entries.
    if (!entry.is_valid) {
      std::cout << entry.error_message << std::endl;
      continue;
    }

    // Look up historical price for transaction date.
    bool found = false;
    double price = FindPriceForDate(entry.date, found);

    if (!found) {
      std::cout << "Error: no price for date => " << entry.date
                << std::endl;
      continue;
    }

    // Output successful exchange calculation.
    std::cout << FormatOutput(entry.date, entry.quantity, price)
              << std::endl;
  }
}