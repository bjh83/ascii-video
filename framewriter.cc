#include"framewriter.h"

FrameWriter::FrameWriter() {
	initscr();
}

FrameWriter::~FrameWriter() {
	 endwin();
}

