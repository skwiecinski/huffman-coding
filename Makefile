CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17 -O2

TARGET = huffman_app

SRC_DIR = src

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Compilation succeeded. Run: ./$(TARGET)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)
	@echo "Cleaned."

.PHONY: all clean