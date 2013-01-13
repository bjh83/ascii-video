#include<string>
#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include"image.h"
#include"framewriter.h"

using namespace std;

namespace config {
	static const int expected_args = 2;
}

int main(int argc, char* argv[]) {
	if(argc != config::expected_args) {
		cout << "Please provide the appropriate number of arguments";
		return 0;
	}
	string filename(argv[1]);
	cv::VideoCapture capture(filename);
	FrameWriter writer;
	for(; capture.grab();) {
		cv::Mat rgb_frame, gray_frame;
		capture.retrieve(rgb_frame);
		cv::cvtColor(rgb_frame, gray_frame, CV_RGB2GRAY);
		image::Buffer tempbuffer(gray_frame), outbuffer; //Convert to image::Buffer
		image::CellScale(tempbuffer, &outbuffer); //Convert to apropriately scaled buffer
		writer << outbuffer;
	}
	return 0;
}

