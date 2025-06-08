#include "stdafx.h"
#include "Ws2tcpip.h"
#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>
#include <filesystem>

using namespace std;

int FileSend(SOCKET* sock, const string& file_name) {
	int res = 0;
	fstream file;
	file.open(file_name, ios_base::in | ios_base::binary);

	if (file.is_open() && ifstream(file_name).good()) {
		uintmax_t file_size = filesystem::file_size(file_name) + 1;

		// чтобы данные хранили только наполнение файла и не больше
		// и не было кракозябр в конце
		file.seekg(0, std::ifstream::end);
		int len = file.tellg();
		file.seekg(0, std::ifstream::beg);
		char* bytes = new char[len + 1];
		file.read(bytes, len);
		bytes[len] = '\0';

		res = send(*sock, to_string(file_size).c_str(), 16, 0);
		res = send(*sock, file_name.c_str(), 128, 0);
		res = send(*sock, bytes, len, 0);
		delete[] bytes;
	}
	else res = -1;
	file.close();
	return res;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	WSADATA ws;
	struct sockaddr_in peer;
	SOCKET s;
	int rc;
	char buf[1], fileName[128], fileSize[16];
	// Заполняем поля структуры для использование ее в connect
	peer.sin_family = AF_INET;
	peer.sin_port = htons(7500);
	// порт
	InetPton(AF_INET, L"127.0.0.1", &peer.sin_addr.s_addr); // адрес означает, что сервер на той же машине, что и клиент

	int answer = 1, res = 0;
	string inputFilePath = "";
	do {
		cout << "Введите 1, чтобы выбрать файл для отправки"
			<< "\nВведите 2, чтобы отправить файл на сервер"
			<< "\nВведите 3, чтобы прочитать файл с сервера"
			<< "\nВведите 0, чтобы завершить работу"
			<< "\n";
		cin >> answer;
		switch (answer) {
		case 1:
			cout << "Введите путь до файла: ";
			cin >> inputFilePath;
			break;
		case 2:
			while (inputFilePath == "") {
				cout << "Введите путь до файла: ";
				cin >> inputFilePath;
			}
			cout << "Отправка файла " << inputFilePath << " на сервер..." << "\n";
			// Init
			if (WSAStartup(0x0202, &ws) != 0) printf("Не удалось запустить WSAStartup");
			// Создаем сокет
			else {
				s = socket(AF_INET, SOCK_STREAM, 0);
				if (s == INVALID_SOCKET) perror("Не удалось создать сокет");
				else {
					// Устанавливаем соединение с сервером
					rc = connect(s, (struct sockaddr*)&peer, sizeof(peer));
					if (rc) perror("Не удалось установить соединение с сервером");
					else {
						// Посылаем серверу сообщение
						if (ifstream(inputFilePath).good()) {
							rc = send(s, "2", 1, 0); // сначала код действия
							res = FileSend(&s, inputFilePath);
							if (res <= 0) perror("Не удалось совершить отправку на сервер");
							else cout << "Файл успешно отправлен\n";
						}
						else perror("Файл не найден");
					}
				}
			}
			break;
		case 3:
			cout << "Получение ответа от сервера..." << "\n";
			if (WSAStartup(0x0202, &ws) != 0) printf("Не удалось запустить WSAStartup");
			// Создаем сокет
			else {
				s = socket(AF_INET, SOCK_STREAM, 0);
				if (s == INVALID_SOCKET) perror("Не удалось создать сокет");
				else {
					// Устанавливаем соединение с сервером
					rc = connect(s, (struct sockaddr*)&peer, sizeof(peer));
					if (rc) perror("Не удалось установить соединение с сервером");
					else {
						// получаем ответ
						rc = send(s, "3", 1, 0); // сначала код действия
						if (rc <= 0)
							perror("Не удалось получить файл от сервера");
						else {
							char file_name[128];
							recv(s, file_name, 128, 0);
							char* findstr;
							findstr = strstr(file_name, "Отсутствует файл для чтения");

							if (!findstr) {
								char file_size_str[16];

								recv(s, file_size_str, 16, 0);
								uintmax_t file_size = atoi(file_size_str);

								char* bytes = new char[file_size];
								recv(s, bytes, file_size, 0);

								cout << "Информация о последнем полученном сервером файле:" << endl
									<< "name: " << file_name << endl
									<< "size: " << file_size << endl
									<< "data: " << bytes << endl;
							}
							else cout << file_name << endl;

						}
					}
				}
			}
			break;
		case 0:
			break;
		default:
			cout << "Неизвестная команда, повторите ввод" << endl;
			break;
		}
	} while (answer != 0);

	return 0;
}
