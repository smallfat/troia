//
// Created by henry on 2020/5/20.
//

#ifndef TROIA_ACCEPTOR_H
#define TROIA_ACCEPTOR_H

#include "troia/base/noncopyable.h"
#include "troia/net/Channel.h"
#include "troia/net/Socket.h"

namespace troia
{
namespace net
{
    class INetAddress;

    typedef std::function<void (int fd, const INetAddress&)> ConnectionCallback;

    class Acceptor : public noncopyable {
    public:
        Acceptor(INetAddress& listenAddr);
        virtual ~Acceptor();

    public:
        void listen();

        void handle_read();

        void set_connection_callback(ConnectionCallback cb);

    protected:


    private:
        Channel *m_channel;
        Socket m_socket;

        ConnectionCallback m_connection_callback;
    };
}
}



#endif //TROIA_ACCEPTOR_H
