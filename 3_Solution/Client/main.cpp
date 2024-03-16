// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include "APPClient.h"
#include <cstdio>

int main() {

	int read_bytes;
	char send_buffer[1024];

	for (;;) {
		scanf("%s", send_buffer);
		APPClient::getInstance()->getTcpClient()->send(send_buffer, strlen(send_buffer));
	}
}