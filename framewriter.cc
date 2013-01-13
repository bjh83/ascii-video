#include"framewriter.h"

FrameWriter::FrameWriter(int wait_time) : functor(mutex, cond, wait_time), thread(functor) {
	initscr();
}

FrameWriter::~FrameWriter() {
	 endwin();
	 functor.kill();
	 thread.interrupt();
	 thread.join();
}

