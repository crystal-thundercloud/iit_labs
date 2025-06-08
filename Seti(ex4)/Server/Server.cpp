#include "stdafx.h"
#include "Ws2tcpip.h"
#include "winsock2.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>
#include <filesystem>

using namespace std;

struct fileInfo {
	string file_name;
	uintmax_t file_size;
	char* file_data;
};

fileInfo FileGet(SOCKET* sock) {
	char file_size_str[16];
	char file_path[128];

	recv(*sock, file_size_str, 16, 0);
	uintmax_t file_size = atoi(file_size_str);

	recv(*sock, file_path, 128, 0);

	char* bytes = new char[file_size];

	fstream file;
	char* p;
	char* idk;
	char* fileName = file_path;
	p = strtok_s(file_path, "\\", &idk);
	while (p != NULL) {
		fileName = p;
		p = strtok_s(NULL, "\\", &idk);
	}
	file.open(fileName, ios_base::out | ios_base::binary);
	cout << "name: " << fileName << endl;
	cout << "size: " << file_size << endl;

	if (file.is_open()) {
		recv(*sock, bytes, file_size, 0);
		cout << "data: " << bytes << endl;
		file.write(bytes, file_size);
	}


	fileInfo fi;
	fi.file_name = fileName;
	fi.file_size = file_size;
	fi.file_data = bytes;

	file.close();
	
	return fi;
}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	WSADATA ws;
	struct sockaddr_in local;
	SOCKET s, s1;
	int rc;
	char buf[1];
	local.sin_family = AF_INET;
	local.sin_port = htons(7500); // порт, который прослушивает сервер
	local.sin_addr.s_addr = htonl(INADDR_ANY);

	fileInfo res;
	res.file_name = "Отсутствует файл для чтения";
	res.file_size = 0;
	res.file_data = new char[1];
	// Init
	if (WSAStartup(0x0202, &ws) != 0) printf("Не удалось запустить WSAStartup");
	else {
		// Создаѐм сокет
		s = socket(AF_INET, SOCK_STREAM, 0);
		if (s < 0) perror("Не удалось создать сокет");
		else {
			// Привязываем адрес интерфейса и номер порта к прослушивающему сокету
			rc = bind(s, (struct sockaddr*)&local, sizeof(local));
			if (rc < 0) perror("Не удалось привязать адреса к сокету");
			else {
				// прослушивание порта
				rc = listen(s, 5);
				if (rc) perror("Не удалось запустить прослушивание порта");
				else {
					cout << "Соединение установлено" << endl
						<< "Ожидание запроса от клиента..." << endl;
					
					do {
						// прием соединения, ожидающего во входной очереди
						s1 = accept(s, NULL, NULL);
						if (s1 < 0) perror("Не удалось принять соединение");
						else {
							rc = recv(s1, buf, 1, 0);
							switch (buf[0]) {
							case '2':
								cout << "Получение файла от клиента..." << endl;
								res = FileGet(&s1);
								cout << "Файл успешно получен" << endl;
								break;
							case '3':
								cout << "Получен запрос на чтение файла от клиента" << endl
									<< "Вывод последнего полученного файла..." << endl;
									send(s1, res.file_name.c_str(), 128, 0);
								if (res.file_name != "Отсутствует файл для чтения") {
									send(s1, to_string(res.file_size).c_str(), 16, 0);
									send(s1, res.file_data, (res.file_size < 1) ? 1 : res.file_size, 0);
									cout << "Вывод файла завершён" << endl;
								}
								else cout << res.file_name << endl;
								break;
							default:
								break;
							}
							cout << "Ожидание запроса от клиента..." << endl;
						}

					} while (rc > 0);
				}
			}
		}
	}
	return 0;
}