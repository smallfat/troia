//
// Created by henry on 2020/5/12.
//

#include "Channel.h"

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

}