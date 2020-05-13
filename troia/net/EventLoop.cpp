//
// Created by henry on 2020/5/7.
//

#include <iostream>
#include "EventLoop.h"

using namespace troia;
using namespace troia::net;

EventLoop::EventLoop()
{
    std::cout << "event loop" << std::endl;
}

EventLoop::~EventLoop()
{
    std::cout << "event loop destructor" << std::endl;
}

void EventLoop::loop()
{
    m_loop = true;
    m_quit = false;

    while(m_quit)
    {
        //i/o


        //pending callbacks
        exec_pending_functors();
    }
}

void EventLoop::exec_pending_functors()
{
    std::vector<Functor> callbacks;

    {
        MutexLockGuard guard(m_mutex);
        callbacks.swap(m_functors_pending);
    }

    for (const Functor& f : callbacks)
    {
        f();
    }
}


