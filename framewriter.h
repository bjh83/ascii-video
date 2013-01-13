#ifndef FRAMEWRITER_H
#define FRAMEWRITER_H
#include<curses.h>
#include<boost/thread/thread.hpp>
#include<boost/thread/mutex.hpp>
#include<boost/thread/condition_variable.hpp>
#include<boost/thread/locks.hpp>
#include<boost/date_time/posix_time/posix_time.hpp>
#include"image.h"

class FrameRateFunctor {
	public:
		FrameRateFunctor(boost::mutex& lock, boost::condition_variable& cond_var, int wait_time) : mutex(lock), 
			cond(cond_var), wait_time(wait_time), alive(true) {};

		~FrameRateFunctor() {};

		inline void operator()() {
			while(alive) {
				boost::this_thread::sleep(wait_time);
				boost::lock_guard<boost::mutex> lock(mutex);
				cond.notify_all();
			}
		};

		inline void kill() {
			alive = false;
		}

	private:
		bool alive;
		boost::posix_time::milliseconds wait_time;
		boost::mutex& mutex;
		boost::condition_variable& cond;
};

class FrameWriter {
	public:
		FrameWriter(int wait_time);
		~FrameWriter();

		inline void operator<<(const image::Buffer& frame) {
			for(int y = 0; y < frame.get_height(); y++) {
				for(int x = 0; x < frame.get_width(); x++) {
					move(y, x);
					addch(frame.at(y, x));
				}
			}
			boost::unique_lock<boost::mutex> lock(mutex);
			cond.wait(lock);
			refresh();
		}

	private:
		FrameRateFunctor functor;
		boost::mutex mutex;
		boost::condition_variable cond;
		boost::thread thread;
};

#endif

