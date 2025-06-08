#include "stdafx.h"
#include "Ws2tcpip.h"
#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
int notmain(int argc, char* argv[])
{
	WSADATA ws;
	struct sockaddr_in peer;
	SOCKET s;
	int rc;
	char buf[1];
	// «аполн€ем пол€ структуры дл€ использование ее в connect
	peer.sin_family = AF_INET;
	peer.sin_port = htons(7500);
	// порт
	InetPton(AF_INET, L"127.0.0.1", &peer.sin_addr.s_addr);
	//peer.sin_addr.s_addr = inet_addr("127.0.0.1"); // адрес означает, что сервер на той же машине, что и клиент
	// Init
	if (WSAStartup(0x0202, &ws) != 0)
	{
		printf("error");
		exit(1);
	}
	// —оздаем сокет
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET)
	{
		perror("socket call failed");
		exit(1);
	}
	// ”станавливаем соединение с сервером
	rc = connect(s, (struct sockaddr*)&peer,
		sizeof(peer));
	if (rc)
	{
		perror("connect call failed");
		exit(1);
	}
	// ѕосылаем серверу сообщение
	rc = send(s, "1", 1, 0);
	if (rc <= 0)
	{
		perror("send call failed");
		exit(1);
	}
	// получаем ответ
	rc = recv(s, buf, 1, 0);
	if (rc <= 0)
		perror("recv call failed");
	else
		printf("Server answer: %c\n", buf[0]);
	exit(0);
	return 0;
}
