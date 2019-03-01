#include "FIFO_Strategy.h"

FIFO_Strategy::FIFO_Strategy(std::shared_ptr<Context> c) : ScheduleStrategy(c) {
	//nothing needed here for FIFO
}

void FIFO_Strategy::run() {
	//nothing needed here for FIFO
}

void FIFO_Strategy::schedule() {
	std::shared_ptr<Thread> threadToSchedule = context->ReadyList->back();
	context->ReadyList->pop_back();
	std::shared_ptr<Thread> lastThread = context->scheduler->preempt(threadToSchedule); //move scheduled thread to CPU and save the last thread
	context->scheduler->finishThread(lastThread);
}

void FIFO_Strategy::addThread() {
	//nothing needed here for FIFO
}