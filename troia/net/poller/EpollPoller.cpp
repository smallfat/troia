//
// Created by henry on 2020/5/12.
//

#include "EpollPoller.h"
#include <sys/epoll.h>
#include <unistd.h>
#include "troia/net/Channel.h"

using namespace troia;
using namespace net;

EpollPoller::EpollPoller()
    : m_events(16)
{

}

EpollPoller::~EpollPoller()
{

}

bool EpollPoller::init()
{
    m_epoll_fd = ::epoll_create1(EPOLL_CLOEXEC);
    if (m_epoll_fd < 0)
    {
        return false;
    }

    return true;
}

void EpollPoller::uninit()
{
    ::close(m_epoll_fd);
}

void EpollPoller::poll(ListChannel* channels)
{
    int events_num = ::epoll_wait(m_epoll_fd,
                                  &*m_events.begin(),
                                  static_cast<int>(m_events.size()),
                                  500);
    if (events_num > 0)
    {
        fill_channels(events_num, channels);
    }
}

void EpollPoller::fill_channels(int events_num, ListChannel* channels)
{
    for (int i = 0; i < events_num; ++i)
    {
        Channel* c = static_cast<Channel*>(m_events[i].data.ptr);
        c->set_events(m_events[i].events);
        channels->push_back(c);
    }
}