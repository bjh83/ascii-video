#include<string>
#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;

namespace config {
	static const int expected_args = 2;
}

int main(int argc, char* argv[]) {
	if(argc != expected_args) {
		cout << "Please provide the appropriate number of arguments";
		return 0;
	}
	string filename(argv[1]);
	cv::VideoCapture capture(filename);
	cv::Mat frame;
	for(; capture.grab();) {
		capture.retrieve(frame);
		image::Buffer tempbuffer(frame), outbuffer;
		image::CellScale(tempbuffer, &outbuffer);
	}
	return 0;
}

