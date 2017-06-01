
INCLUDE=-I/usr/include
LDFLAGS=-L/usr/lib/x86_64-linux-gnu/ \
		-lopencv_core -lopencv_highgui -lopencv_imgproc

main:videoToPicture.cpp
	$(CXX) -o $@ $^ $(INCLUDE) $(LDFLAGS) -std=c++14

clean:
	rm -rf main
