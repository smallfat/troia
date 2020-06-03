//
// Created by henry on 2020/5/7.
//

#include <iostream>
#include "EventLoop.h"
#include "troia/net/poller/EpollPoller.h"
#include "troia/net/Channel.h"

using namespace troia;
using namespace troia::net;



EventLoop::EventLoop()
    : m_loop(false),
    m_quit(false),
    m_pooler(new EpollPoller())
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

    while(!m_quit)
    {
        //i/o
        m_pooler->poll(&m_active_channels);

        for (Channel* c : m_active_channels)
        {
            c->handle_event();
        }


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

void EventLoop::updateChannel(Channel* channel)
{
    m_pooler->updateChannel(channel);
}
