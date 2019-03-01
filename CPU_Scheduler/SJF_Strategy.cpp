#include "SJF_Strategy.h"

SJF_Strategy::SJF_Strategy(std::shared_ptr<Context> c) : ScheduleStrategy(c) {
    //nothing needed here for SJF
}

void SJF_Strategy::run() {
    //nothing needed here for SJF
}

void SJF_Strategy::schedule() {
    std::shared_ptr<Thread> threadToSchedule;
    for (std::list<std::shared_ptr<Thread>>::iterator it = context->ReadyList->begin(); it != context->ReadyList->end(); ++it){
        if (compareBurstTime(*it, threadToSchedule)){
            threadToSchedule = *it;
        }
    }
    context->ReadyList->remove(threadToSchedule);
    std::shared_ptr<Thread> lastThread = context->scheduler->preempt(threadToSchedule); //move scheduled thread to CPU and save the last thread
    context->scheduler->finishThread(lastThread);
}

void SJF_Strategy::addThread() {
    //nothing needed here for SJF
}

bool SJF_Strategy::compareBurstTime(std::shared_ptr<Thread> threadA, std::shared_ptr<Thread> threadB){
    return threadA->burstTime.front() < threadB->burstTime.front();
}
