#ifndef _nettools_H
#define _nettools_H

int netstat();
int ping(const char* host);
int test_port(const char* host, int port);

#endif
