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
    : m_events(m_events_size),
      m_epoll_fd(::epoll_create1(EPOLL_CLOEXEC))
{

}

EpollPoller::~EpollPoller()
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