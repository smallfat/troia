//
// Created by henry on 2020/5/31.
//
#include "troia/net/EventLoop.h"

using namespace troia;
using namespace troia::net;

int main(int n, char* args[])
{
    EventLoop el;
    el.loop();

    return 0;
}