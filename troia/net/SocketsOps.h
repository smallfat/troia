//
// Created by henry on 2020/5/21.
//

#ifndef TROIA_SOCKETSOPS_H
#define TROIA_SOCKETSOPS_H

#include <arpa/inet.h>

namespace troia
{
namespace net
{
namespace sockets
{

int create_non_block_socket(sa_family_t family);

int bind(int fd, const struct sockaddr* addr);

int listen(int fd);

bool from_ip_port(const char* ip, uint16_t port, struct sockaddr_in* addr);

int accept(int fd, struct sockaddr_in* addr);

struct sockaddr* sockaddr_cast(const struct sockaddr_in* addr);
}
}
}



#endif //TROIA_SOCKETSOPS_H
