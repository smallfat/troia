add_library(troia_net
        EventLoop.cpp
        Channel.cpp
        poller/EpollPoller.cpp
        INetAddress.cpp
        SocketsOps.cpp
        Socket.cpp
        Acceptor.cpp
        )

install(TARGETS troia_net DESTINATION lib)

file(GLOB HEADERS "troia/net/*.h")
install(FILES ${HEADERS} DESTINATION include/troia/net)

file(GLOB HEADERS "troia/base/*.h")
install(FILES ${HEADERS} DESTINATION include/troia/base)