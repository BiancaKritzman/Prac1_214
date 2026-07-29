CXX=g++
CFLAGS=-I. -Wall
TARGET=TestOrganism
OBJS= Pipeline.o Transformation.o TransformationRegistry.o  

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)
    
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
    
clean:
	rm -f $(TARGET) $(OBJS)
    