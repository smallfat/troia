cmake_minimum_required(VERSION 3.10)
project(troia)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR})

add_library(troia
        troia/net/EventLoop.h
        troia/base/noncopyable.h
        troia/net/EventLoop.cpp
        troia/base/Mutex.h
        troia/net/Channel.cpp
        troia/net/Channel.h
        troia/base/TimeStamp.h
        troia/base/copyable.h
        troia/net/Poller.h
        troia/net/poller/EpollPoller.cpp
        troia/net/poller/EpollPoller.h
        troia/net/INetAddress.cpp
        troia/net/INetAddress.h
        troia/net/SocketsOps.cpp
        troia/net/SocketsOps.h
        troia/net/Socket.cpp
        troia/net/Socket.h
        troia/net/Acceptor.cpp
        troia/net/Acceptor.h
        )