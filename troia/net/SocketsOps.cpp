//
// Created by henry on 2020/5/21.
//

#include "SocketsOps.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <endian.h>
#include <unistd.h>

using namespace troia;
using namespace net;

struct sockaddr* sockets::sockaddr_cast(const struct sockaddr_in* addr)
{
    return static_cast<struct sockaddr*>((void*)addr);
}


    int sockets::create_non_block_socket(sa_family_t family)
    {
        return ::socket(family, SOCK_STREAM | SOCK_CLOEXEC | SOCK_NONBLOCK, IPPROTO_TCP);
    }

    int sockets::bind(int fd, const struct sockaddr* addr)
    {
        return ::bind(fd, addr, static_cast<socklen_t>(sizeof(struct sockaddr_in6)));
    }

    int sockets::listen(int fd)
    {
        return ::listen(fd, SOMAXCONN);
    }

    bool sockets::from_ip_port(const char* ip, uint16_t port, struct sockaddr_in* addr)
    {
        addr->sin_family = AF_INET;
        addr->sin_port = htobe16(port);
        if (::inet_pton(AF_INET, ip, &addr->sin_addr) <=0)
            return false;

        return true;
    }

    int sockets::accept(int fd, struct sockaddr_in* addr)
    {
        socklen_t len = static_cast<socklen_t>(sizeof *addr);

        int connfd = ::accept4(fd, sockaddr_cast(addr),
                &len, SOCK_NONBLOCK | SOCK_CLOEXEC);


        return connfd;
    }

