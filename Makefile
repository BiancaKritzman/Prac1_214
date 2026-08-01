CXX=g++ -std=c++11
CFLAGS=-I. -Wall
TARGET=engine
OBJS= Pipeline.o Transformation.o TransformationRegistry.o \
      Connector.o PostgresConnector.o RestApiConnector.o CsvConnector.o \
      ConnectorFactory.o PostgresFactory.o RestApiFactory.o CsvFactory.o \
      RunCheckpoint.o CheckpointManager.o main.o

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)