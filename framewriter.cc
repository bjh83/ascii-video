#include"framewriter.h"

FrameWriter::FrameWriter() {
	initscr();
}

FrameWriter::~FrameWriter() {
	 endwin();
}

inline void FrameWriter::operator<<(const image::Buffer& frame) {
	for(int y = 0; y < frame.get_height(); y++) {
		for(int x = 0; x < frame.get_width(); x++) {
			move(y, x);
			addch(frame.at(y, x));
		}
	}
}

inline void FrameWriter::render() {
	refresh();
}

