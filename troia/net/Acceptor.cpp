//
// Created by henry on 2020/5/20.
//

#include "Acceptor.h"
#include "troia/net/SocketsOps.h"
#include "troia/net/INetAddress.h"
#include "EventLoop.h"
#include <unistd.h>
#include <poll.h>

using namespace troia;
using namespace net;


Acceptor::Acceptor(INetAddress& listenAddr, EventLoop *loop)
    : m_socket(sockets::create_non_block_socket(listenAddr.family())),
      m_channel(new Channel(m_socket.fd(), pctNew)),
      m_loop(loop)
{
    m_socket.bind(listenAddr);
    m_channel->set_read_callback(
            std::bind(&Acceptor::handle_read, this)
            );
    m_channel->set_events(POLLIN | POLLPRI);
    m_loop->updateChannel(m_channel);
}

Acceptor::~Acceptor()
{
}

void Acceptor::listen()
{
    m_socket.listen();
}

void Acceptor::handle_read()
{
    INetAddress peer;
    int cfd = m_socket.accept(&peer);
    if (cfd > 0)
    {
        if (m_connection_callback)
        {
            m_connection_callback(cfd, peer);
        }
        else
        {
            ::close(cfd);
        }
    }
}

void Acceptor::set_connection_callback(ConnectionCallback cb)
{
    m_connection_callback = cb;
}