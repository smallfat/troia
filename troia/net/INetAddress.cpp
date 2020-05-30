//
// Created by henry on 2020/5/22.
//

#include "INetAddress.h"
#include <string>
#include <memory.h>
#include "troia/net/SocketsOps.h"

using namespace troia;
using namespace net;

INetAddress::INetAddress(std::string ip, uint16_t port)
{
    memset(&m_addr, 0, sizeof(m_addr));
    sockets::from_ip_port(ip.c_str(), port, &m_addr);
}

const sockaddr* INetAddress::get_sock_addr()
{
    return sockets::sockaddr_cast(&m_addr);
}