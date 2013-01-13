#include"image.h"

namespace image {

	Buffer::Buffer(const cv::Mat& image) : width(image.cols), height(image.rows) {
		data = new unsigned char[width * height];
		for(int y = 0; y < height; y++) {
			for(int x = 0; x < width; x++) {
				this->set(y, x, image.at<unsigned char>(y, x));
			}
		}
	}

	Buffer::~Buffer() {
		delete[] data;
	}

	int Buffer::get_width() const {
		return width;
	}

	int Buffer::get_height() const {
		return height;
	}

	void Buffer::resize(int width, int height) {
		this->width = width;
		this->height = height;
		if(data != NULL) {
			delete[] data;
		}
		data = new unsigned char[width * height];
	}

	unsigned char GetCellValue(int cell_average) {
		cell_average /= 32;
		switch(cell_average) {
			case 7:
				return '#';
			case 6:
				return 'X';
			case 5:
				return 'o';
			case 4:
				return '=';
			case 3:
				return '+';
			case 2:
				return ':';
			case 1:
				return '-';
			case 0:
				return ' ';
		}
	}

	void CellScale(const Buffer& original, Buffer* newbuffer) {
		int new_width = original.get_width() / XRatio;
		int new_height = original.get_height() / YRatio;
		newbuffer->resize(new_width, new_height);
		for(int newy = 0; newy < new_height; newy++) {
			for(int newx = 0; newx < new_width; newx++) {
				int sum = 0;
				int xmax = (newx + 1) * XRatio;
				int ymax = (newy + 1) * YRatio;
				for(int y = newy * YRatio; y < ymax; y++) {
					for(int x = newx * XRatio; x < xmax; x++) {
						sum += original.at(y, x);
					}
				}
				newbuffer->set(newy, newx, GetCellValue(sum / (XRatio * YRatio)));
			}
		}
	}
	
};

