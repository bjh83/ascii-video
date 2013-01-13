#include<curses.h>
#include"image.h"

class FrameWriter {
	public:
		FrameWriter();
		~FrameWriter();
		inline void operator<<(const image::Buffer& frame);
		inline void render();
}

