#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <WinSock2.h>
#include <stdio.h>
#include <windows.h>
#include <process.h> // ������ ���
#include <stdlib.h>


#define SERVER_IP "192.168.56.1"
// ��Ʈ��ȣ ����
#define PORT_NUM 10200

#define LetsChess 100

#pragma comment(lib,"ws2_32")
#include "socket.h"
#include "chess.h"
#include "grapics.h"

//�����͸� ���� ������
void RecvThreadPoint(void* param) //param���δ� ((void*) sock)�� ���´�
{
	SOCKET sock = (SOCKET)param;
	// msg = �޽����� ���� ����
	char msg[LetsChess] = "";

	// recv�� �������κ��� �����Ͱ� ������ ���� �������� ũ�⸦ ��ȯ
	// �� �������� �����Ͱ� ���Դ��� üũ
	while (1)
	{
		recv(sock, msg, LetsChess, 0);
		
		// ���� ���� �ؼ�
		// ��) 0013�� ������ xy 00�� �ִ� ���� xy 13���� �̵�
		// �� ���� ���� VOI�� ����� ���� ���� ��ġ�� �̵�
		chessGrid[msg[2] - 48][msg[3] - 48] = chessGrid[msg[0] - 48][msg[1] - 48];
		chessGrid[msg[0] - 48][msg[1] - 48] = VOI;

		drawCharacter(msg[2] - 48, msg[3] - 48, CHARCOLOR(chessGrid[msg[2] - 48][msg[3] - 48]), retCharPtr(CHARCOLOR(chessGrid[msg[2] - 48][msg[3] - 48])));
		drawCore(msg[0] - 48, msg[1] - 48);

		for (int i = 0; i < LetsChess; i++)
			msg[i] = 0;
	}
}


// sock�� �����ϴ� �Լ�
void sockSetting()
{
	WSAStartup(MAKEWORD(2, 2), &wsdata);


	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // TCP = ����� �� �� ���� ��������
	if (sock == -1)
	{
		// -1�� �����ϸ� ����, �� ����
		printf("-1");
		exit(0);
	}

	// ���� �� ������ ��Ʈ�� �ֱ�
	SOCKADDR_IN servaddr = { 0 };// �����ּ�(����ü ���)
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
	servaddr.sin_port = htons(PORT_NUM);

	// ����� �� �ƴ��� Ȯ��
	int re = 0;
	re = connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));// ���� ��û
	if (re == -1) { exit(0); } //����� �߸� �Ǿ��� ��
	// ������ ���!!!
	_beginthread(RecvThreadPoint, 0, (void*)sock);

}