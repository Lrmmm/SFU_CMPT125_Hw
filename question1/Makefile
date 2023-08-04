CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = test

SRCS = LinkedList.cpp Stack.cpp test.cpp
OBJS = $(SRCS:.cpp=.o)

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $^

clean:
	rm -f $(OBJS) $(TARGET)