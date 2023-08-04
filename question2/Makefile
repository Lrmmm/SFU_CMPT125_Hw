CXX = g++
CXXFLAGS = -std=c++11 -Wall

# test1 ======================================
TARGET_Test1 = test1
SRCS_Test1 = Colour.cpp DisplayBackground.cpp EasyBMP.cpp Triangle.cpp triangleTest.cpp 
OBJS1 = $(SRCS_Test1:.cpp=.o)

t1:$(TARGET_Test1)
	rm -f $(OBJS1)

$(TARGET_Test1):$(OBJS1)
	$(CXX) $(CXXFLAGS) -o $@ $^


# test2 ======================================
TARGET_Test2 = test2
SRCS_Test2 = Colour.cpp DisplayBackground.cpp EasyBMP.cpp Triangle.cpp anotherTest.cpp Gasket.cpp
OBJS2 = $(SRCS_Test2:.cpp=.o)

t2:$(TARGET_Test2)
	rm -f $(OBJS2)

$(TARGET_Test2):$(OBJS2)
	$(CXX) $(CXXFLAGS) -o $@ $^

# test3 ======================================
TARGET_Test3 = test3
SRCS_Test3 = Colour.cpp DisplayBackground.cpp EasyBMP.cpp Triangle.cpp Gasket.cpp  gasketTest.cpp
OBJS3 = $(SRCS_Test3:.cpp=.o)

t3:$(TARGET_Test3)
	rm -f $(OBJS3)

$(TARGET_Test3):$(OBJS3)
	$(CXX) $(CXXFLAGS) -o $@ $^



# common opreations ==========================
%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -f $(TARGET_Test1) $(TARGET_Test2) $(TARGET_Test3) $(OBJS1) $(OBJS2) $(OBJS3)

del:
	rm -f log*
	rm -f *.bmp

