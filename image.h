#ifndef IMAGE_H
#define IMAGE_H
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>

namespace image {

	static const int XRatio = 1;
	static const int YRatio = 2;
	
	//Creates a lightweight reprasentation of a Mat
	class Buffer {
		public:
			Buffer() : data(NULL) {};
			explicit Buffer(const cv::Mat& image);

			inline unsigned char at(int y, int x) const {
				return data[x + y * width];
			}

			inline void set(int y, int x, unsigned char val) {
				data[x + y * width] = val;
			}

			int get_width() const;
			int get_height() const;
			int get_scale_factor(int term_width, int term_height) const;
			void resize(int width, int height);
			~Buffer();
		private:
			int width;
			int height;
			unsigned char* data;
	};

	//XXX: newbuffer is assumed to be non-null
	void CellScale(const Buffer& original, Buffer* newbuffer, int term_width, int term_height);
};
#endif

