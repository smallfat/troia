//
// Created by henry on 2020/5/12.
//

#ifndef TROIA_EPOLLPOLLER_H
#define TROIA_EPOLLPOLLER_H

#include <troia/net/Poller.h>

struct epoll_event;

namespace troia
{
namespace net
{
    typedef std::vector<epoll_event> EventList;

    class EpollPoller : public Poller
    {
    public:
        EpollPoller();
        virtual ~EpollPoller();

    public:
        void poll(ListChannel* channels);

    private:
        void fill_channels(int events_num, ListChannel* channels);

    private:
        int m_epoll_fd;
        EventList m_events;

        static const int m_events_size = 16;
    };
}
}


#endif //TROIA_EPOLLPOLLER_H
