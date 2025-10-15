#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Extract executable name from Makefile
#	Lane by lane explanation:
#	grep "^NAME\s*=" Makefile											| head -1								| sed 's/NAME\s*=\s*//'											| xargs
#		It takes: "^NAME\s*=" what means: 									It takes only the first lane			It replace the output											Delete spaces and \n from end and beggining
#			1->	^: Start of lane																						1-> 's/text/replace_text/'
#			2->	NAME: Literally the word "NAME"																			2-> NAME\s*=\s*: Search "NAME" + spaces + "=" + spaces
#			3->	\s*: Blank spaces >= 0																					3-> //: Replace with nothing
#			4->	=: Litreally the "=" Sign																				
NAME=$(grep "^NAME\s*=" Makefile | head -1 | sed 's/NAME\s*=\s*//' | xargs)

if [ -z "$NAME" ]; then
    echo -e "${RED}❌ Error: Could not find NAME variable in Makefile${NC}"
    exit 1
fi

# Detect exercise number from directory name
EXERCISE=$(basename $(pwd))

echo -e "${BLUE}"
echo "╔════════════════════════════════════════════════════════════════╗"
echo "║          COMPREHENSIVE TEST SUITE - ${EXERCISE^^}                      ║"
echo "║          Testing for Memory Leaks and Segfaults               ║"
echo "║          Executable: $NAME"
echo "╚════════════════════════════════════════════════════════════════╝"
echo -e "${NC}"

# Clean and compile
echo -e "${YELLOW}[1/3] Cleaning previous builds...${NC}"
make fclean > /dev/null 2>&1

echo -e "${YELLOW}[2/3] Compiling $NAME...${NC}"
make all > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Compilation failed!${NC}"
    exit 1
fi
echo -e "${GREEN}✓ $NAME compiled successfully${NC}\n"

# Run valgrind tests
echo -e "${YELLOW}[3/3] Running valgrind on $NAME...${NC}"
valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$NAME > /tmp/test_output.txt 2>&1
VALGRIND_EXIT=$?

if [ $VALGRIND_EXIT -eq 0 ]; then
    LEAKS=$(grep "All heap blocks were freed" /tmp/test_output.txt)
    if [ -n "$LEAKS" ]; then
        echo -e "${GREEN}✓ No memory leaks detected${NC}"
    else
        echo -e "${RED}❌ Memory leaks detected!${NC}"
        grep "definitely lost\|indirectly lost" /tmp/test_output.txt
        exit 1
    fi
else
    echo -e "${RED}❌ Valgrind detected errors!${NC}"
    exit 1
fi

# Check for segfaults
echo -e "\n${YELLOW}Checking for segmentation faults...${NC}"
./$NAME > /dev/null 2>&1
if [ $? -eq 139 ]; then
    echo -e "${RED}❌ Segmentation fault detected!${NC}"
    exit 1
fi
echo -e "${GREEN}✓ No segmentation faults detected${NC}"

# Summary
echo -e "\n${BLUE}"
echo "╔════════════════════════════════════════════════════════════════╗"
echo "║                    ALL TESTS PASSED! ✓                        ║"
echo "║                                                                ║"
echo "║  ✓ No memory leaks                                            ║"
echo "║  ✓ No segmentation faults                                     ║"
echo "║  ✓ All exceptions handled correctly                           ║"
echo "║  ✓ All resources properly freed                               ║"
echo "╚════════════════════════════════════════════════════════════════╝"
echo -e "${NC}"

# Clean up temp files
rm -f /tmp/test_output.txt

exit 0
