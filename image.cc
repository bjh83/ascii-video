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

	inline unsigned char Buffer::at(int y, int x) {
		return data[x + y * width];
	}

	inline void Buffer::set(int y, int x, unsigned char pixel) {
		data[x + y * width] = pixel;
	}

	int Buffer::get_width() {
		return width;
	}

	int Buffer::get_height() {
		return height;
	}

	void Buffer::resize(int width, int height) : width(width), height(height) {
		if(data != NULL) {
			delete[] data;
		}
		data = new unsigned char[width * height];
	}

	void CellScale(const Buffer& original, Buffer* newbuffer) {
		int new_width = original.get_width() / XRatio;
		int new_height = original.get_height() / YRatio;
		newbuffer.resize(width, height);
		for(int newy = 0; newy < new_height; newy++) {
			for(int newx = 0; newx < new_width; newx++) {
				int sum = 0;
				xmax = (newx + 1) * XRatio;
				ymax = (newy + 1) * YRatio;
				for(int y = newy * YRatio; y < ymax; y++) {
					for(int x = newx * XRatio; x < xmax; x++) {
						sum += original.at(y, x);
					}
				}
				newbuffer.set(newy, newx, GetCellValue(sum / (XRatio * YRatio)));
			}
		}
	}

	unsigned char GetCellValue(int cell_average) {
		cell_average /= 8;
		switch cell_average {
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
};

