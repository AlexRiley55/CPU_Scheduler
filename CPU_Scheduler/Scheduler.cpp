#include "Scheduler.h"


Scheduler::Scheduler(){

}

Scheduler::Scheduler(std::shared_ptr<CPU> c, std::shared_ptr<ScheduleStrategy> s){
	cpu = c;
	strat = s;
}


Scheduler::~Scheduler(){

}

void Scheduler::run() {

}

void Scheduler::addNewThread(std::shared_ptr<Thread>) {

}

void Scheduler::readyThread(std::shared_ptr<Thread>) { //move a specific thread from Blocked List to Ready List

}

void Scheduler::blockThread(std::shared_ptr<Thread>) { //move a specific thread from Ready List to Blocked List

}

std::shared_ptr<Thread> Scheduler::preempt(std::shared_ptr<Thread>) { //preempt the current thread on the CPU

}

void Scheduler::finishThread(std::shared_ptr<Thread>) { //move a specific thread from Ready List to Finished List

}