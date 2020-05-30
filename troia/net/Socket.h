//
// Created by henry on 2020/5/21.
//

#ifndef TROIA_SOCKET_H
#define TROIA_SOCKET_H

#include "troia/base/noncopyable.h"

namespace troia
{
namespace net
{
    class INetAddress;

    class Socket : public troia::noncopyable
    {
    public:
        explicit Socket(int fd)
        : m_fd(fd)
        { }

        virtual ~Socket();

    public:
        int listen();
        int bind(INetAddress& local_addr);
        int fd()
        {
            return m_fd;
        }

        int accept(INetAddress* addr);

    private:
        const int m_fd;

    };
}
}



#endif //TROIA_SOCKET_H
