//
// Created by henry on 2020/5/12.
//

#ifndef TROIA_POLLER_H
#define TROIA_POLLER_H

#include <troia/base/noncopyable.h>
#include <map>
#include <vector>

namespace troia
{
namespace net
{
    class Channel;

    typedef std::map<int, Channel*> MapChannel;
    typedef std::vector<Channel*> ListChannel;

    class Poller : public noncopyable
    {
    public:
        Poller() = default;
        virtual ~Poller() = default;

    public:
        virtual void poll(ListChannel* channels) = 0;

    protected:
        MapChannel m_channel_map;
    };
}
}



#endif //TROIA_POLLER_H
