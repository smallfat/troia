//
// Created by henry on 2020/5/12.
//

#include "Channel.h"
#include <poll.h>

using namespace troia;
using namespace net;

Channel::Channel(int fd, int index)
    : m_fd(fd), m_events(0), m_recv_events(0), m_index(index)
{
}

Channel::~Channel()
{
}

void Channel::handle_event()
{

    if ((m_recv_events & POLLHUP) && !(m_recv_events & POLLIN))
    {
        if (m_close_callback)
            m_close_callback();
    }

    if (m_recv_events & (POLLIN | POLLPRI | POLLRDHUP))
    {
        if (m_read_callback)
            m_read_callback();
    }

    if (m_recv_events & POLLOUT)
    {
        if(m_write_callback)
            m_write_callback();
    }

}