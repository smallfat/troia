//
// Created by henry on 2020/5/12.
//

#include "Channel.h"
#include <poll.h>

using namespace troia;
using namespace net;

Channel::Channel(int fd)
    :m_fd(fd), m_events(0)
{

}

Channel::~Channel()
{

}

void Channel::handle_event()
{

    if ((m_events & POLLHUP) && !(m_events & POLLIN))
    {
        if (m_close_callback)
            m_close_callback();
    }

    if (m_events & (POLLIN | POLLPRI | POLLRDHUP))
    {
        if (m_read_callback)
            m_read_callback();
    }

    if (m_events & POLLOUT)
    {
        if(m_write_callback)
            m_write_callback();
    }

}