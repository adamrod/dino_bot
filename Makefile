CXX = clang++
CXXFLAGS = -g -lXtst -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lX11 -I /usr/include/opencv4
TARGET = dino_bot


$(TARGET): main.o xinterface.o imagemanipulator.o jumplogic.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o xinterface.o imagemanipulator.o jumplogic.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

screengrabber.o: xinterface.cpp
	$(CXX) $(CXXFLAGS) -c xinterface.cpp

imagemanipulator.o: imagemanipulator.cpp
	$(CXX) $(CXXFLAGS) -c imagemanipulator.cpp

jumplogic.o: jumplogic.cpp
	$(CXX) $(CXXFLAGS) -c jumplogic.cpp

clean:
	rm -f ./*.o
	rm -f ./$(TARGET)
