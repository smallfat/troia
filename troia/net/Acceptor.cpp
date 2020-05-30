//
// Created by henry on 2020/5/20.
//

#include "Acceptor.h"
#include "troia/net/SocketsOps.h"
#include "troia/net/INetAddress.h"
#include <unistd.h>

using namespace troia;
using namespace net;


Acceptor::Acceptor(INetAddress& listenAddr)
    : m_socket(sockets::create_non_block_socket(listenAddr.family())),
    m_channel(new Channel(m_socket.fd()))
{
    m_socket.bind(listenAddr);
    m_channel->set_read_callback(
            std::bind(&Acceptor::handle_read, this)
            );
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