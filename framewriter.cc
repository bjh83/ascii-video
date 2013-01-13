#include"framewriter.h"

FrameWriter::FrameWriter(int frames_per_second) : functor(mutex, cond, 1000 / frames_per_second), thread(functor) {
	initscr();
}

FrameWriter::~FrameWriter() {
	 endwin();
	 functor.kill();
	 thread.interrupt();
	 thread.join();
}

