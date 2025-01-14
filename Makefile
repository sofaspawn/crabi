CXX = clang++
CXXFLAGS = -I/usr/include/opencv4
LDFLAGS = `pkg-config --libs opencv4`
TARGET = main

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

