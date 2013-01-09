#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>

namespace image {

	static const XRatio = 5;
	static const YRatio = 10;
	
	//Creates a lightweight reprasentation of a Mat
	class Buffer {
		public:
			Buffer() : data(NULL) {};
			explicit Buffer(const cv::Mat& image);
			inline unsigned char at(int y, int x);
			inline void set(int y, int x, unsigned char val);
			int get_width();
			int get_height();
			void resize(int width, int height);
			~Buffer();
		private:
			int width;
			int height;
			unsigned char* data;
	};

	//XXX: newbuffer is assumed to be non-null
	void CellScale(const Buffer& original, Buffer* newbuffer);
};

