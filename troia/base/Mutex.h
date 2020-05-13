//
// Created by henry on 2020/5/8.
//

#ifndef TROIA_MUTEX_H
#define TROIA_MUTEX_H

#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "troia/base/noncopyable.h"


#define gettid() syscall(SYS_gettid)

namespace troia
{


    class MutexLock : noncopyable
    {
    public:
        MutexLock()
            : m_master(0)
        {
            pthread_mutex_init(&m_mutex, NULL);
        }

        virtual ~MutexLock()
        {
            pthread_mutex_destroy(&m_mutex);
        }

    public:
        void lock()
        {
            pthread_mutex_lock(&m_mutex);
            set_master();
        }

        void unlock()
        {
            pthread_mutex_unlock(&m_mutex);
            reset_master();
        }


    private:
        void set_master()
        {
            m_master = gettid();
        }

        void reset_master()
        {
            m_master = pid_t(0);
        }

    private:
        pthread_mutex_t m_mutex;
        pid_t m_master;
    };

    //RAII implementation
    class MutexLockGuard : noncopyable
    {
    public:
        explicit MutexLockGuard(MutexLock& locker)
            : m_lock(locker)
        {
            m_lock.lock();
        }

        virtual ~MutexLockGuard()
        {
            m_lock.unlock();
        }

    public:

    protected:
    private:
        MutexLock& m_lock;
    };
}

#endif //TROIA_MUTEX_H
