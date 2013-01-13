#ifndef FRAMEWRITER_H
#define FRAMEWRITER_H
#include<curses.h>
#include"image.h"

class FrameWriter {
	public:
		FrameWriter();
		~FrameWriter();
		inline void operator<<(const image::Buffer& frame) {
			for(int y = 0; y < frame.get_height(); y++) {
				for(int x = 0; x < frame.get_width(); x++) {
					move(y, x);
					addch(frame.at(y, x));
				}
			}
		}
		inline void render() {
			refresh();
		}
};
#endif

