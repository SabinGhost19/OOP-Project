// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include "TCPClient.h"
#include "Utils.h"
#include <cstdio>

int main() {
	sock_init();

	TCPClient* client = new TCPClient();
	client->connect("127.0.0.1", 12345);


	int read_bytes;
	char send_buffer[1024];

	for (;;) {
		scanf("%s", send_buffer);
		client->send(send_buffer, strlen(send_buffer));

	}
}