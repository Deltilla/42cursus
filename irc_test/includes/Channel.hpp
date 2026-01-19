#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <string>
# include <vector>

class Channel {
  private:
    std::string _name;
    std::vector<int> _members; // Lista simple de fds de clientes

  public:
    Channel(const std::string &name);
    ~Channel();

    const std::string &getName() const;
    void addMember(int fd);
    void removeMember(int fd);
};

#endif
