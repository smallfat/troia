//
// Created by henry on 2020/5/7.
//

#ifndef TROIA_NONCOPYABLE_H
#define TROIA_NONCOPYABLE_H

namespace troia
{
    class noncopyable
    {
    protected:
        noncopyable() = default;
        virtual ~noncopyable() = default;

    public:
        noncopyable(const noncopyable& r) = delete;
        void operator=(const noncopyable& r) = delete;
    };
}

#endif //TROIA_NONCOPYABLE_H
