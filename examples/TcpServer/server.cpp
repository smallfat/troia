//
// Created by henry on 2020/5/31.
//
#include <iostream>
#include "troia/net/EventLoop.h"
#include "troia/net/Acceptor.h"
#include "troia/net/INetAddress.h"


using namespace troia;
using namespace troia::net;


int main(int n, char* args[])
{
    EventLoop el;

    INetAddress addr("127.0.0.1", 3451);
    Acceptor ac(addr, &el);
    ac.set_connection_callback(
            [](int fd, const INetAddress& from){
                std::cout << fd << " from:" << std::endl;
            });

    ac.listen();

    el.loop();

    return 0;
}