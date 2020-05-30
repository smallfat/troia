//
// Created by henry on 2020/5/21.
//

#include "Socket.h"
#include "SocketsOps.h"
#include "troia/net/INetAddress.h"
#include <unistd.h>
#include <memory.h>

using namespace troia;
using namespace troia::net;

Socket::~Socket()
{
    ::close(m_fd);
}

int Socket::listen()
{
    return sockets::listen(m_fd);
}


int Socket::bind(INetAddress& addr)
{
    return sockets::bind(m_fd, addr.get_sock_addr());
}

int Socket::accept(INetAddress* peer)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    int connfd = sockets::accept(m_fd, &addr);
    if (connfd >= 0)
    {
        peer->set_addr(addr);
    }

    return connfd;
}