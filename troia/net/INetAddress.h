//
// Created by henry on 2020/5/22.
//

#ifndef TROIA_INETADDRESS_H
#define TROIA_INETADDRESS_H

#include <netinet/in.h>
#include <troia/base/noncopyable.h>
#include <string>

namespace troia
{
namespace net
{
    class INetAddress : public noncopyable
    {
    public:
        //explicit INetAddress(uint16_t port = 0, bool loopbackOnly = false, bool ipv6 = false);
        INetAddress() {}

        explicit INetAddress(const struct sockaddr_in& addr)
                : m_addr(addr)
        { }

        explicit INetAddress(const struct sockaddr_in6& addr)
                : m_addr6(addr)
        { }

        explicit INetAddress(std::string ip, uint16_t port);

        virtual ~INetAddress() {}

    public:
        sa_family_t family() const
        {
            return m_addr.sin_family;
        }

        void set_addr(const sockaddr_in& addr)
        {
            m_addr = addr;
        }

        const sockaddr* get_sock_addr();

    private:
        union
        {
            struct sockaddr_in m_addr;
            struct sockaddr_in6 m_addr6;
        };

    };
}
}


#endif //TROIA_INETADDRESS_H
