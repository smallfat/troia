//
// Created by henry on 2020/5/7.
//

#ifndef TROIA_EVENTLOOP_H
#define TROIA_EVENTLOOP_H

#include "troia/base/noncopyable.h"
#include "troia/base/Mutex.h"
#include <atomic>
#include <vector>
#include <functional>

namespace troia
{
namespace net
{
    //todo: std::function
    typedef std::function<void()> Functor;

    class EventLoop : public noncopyable
    {
    public:
        EventLoop();
        virtual ~EventLoop();

    public:
        void loop();

    private:
        void exec_pending_functors();

    private:
        bool m_loop;
        std::atomic<bool> m_quit;

        MutexLock m_mutex;
        std::vector<Functor> m_functors_pending;
    };

}
}

#endif //TROIA_EVENTLOOP_H
