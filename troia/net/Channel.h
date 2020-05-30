//
// Created by henry on 2020/5/12.
//

#ifndef TROIA_CHANNEL_H
#define TROIA_CHANNEL_H

#include <functional>
#include <troia/base/TimeStamp.h>
#include "troia/base/noncopyable.h"

namespace troia
{
namespace net
{
    typedef std::function<void()> WriteCallback;
    typedef std::function<void()> CloseCallback;
    typedef std::function<void()> ReadCallback;

    class Channel : public noncopyable {
    public:
        Channel(int fd);
        virtual ~Channel();

    public:
        void handle_event();

        void set_events(int events)
        {
            m_events = events;
        }

        inline void set_read_callback(const ReadCallback& callback)
        {
            //todo: std::move semantic should be used
            m_read_callback = callback;
        }

        inline void set_write_callback(const WriteCallback& callback)
        {
            m_write_callback = callback;
        }

        inline void set_close_callback(const CloseCallback& callback)
        {
            m_close_callback = callback;
        }

    private:
        int m_fd;
        int m_events;

        ReadCallback m_read_callback;
        WriteCallback m_write_callback;
        CloseCallback m_close_callback;
    };

}
}


#endif //TROIA_CHANNEL_H
