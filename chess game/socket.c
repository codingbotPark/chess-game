#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <WinSock2.h>
#include <stdio.h>
#include <windows.h>
#include <process.h> // 쓰레드 사용
#include <stdlib.h>


#define SERVER_IP "192.168.56.1"
// 포트번호 선택
#define PORT_NUM 10200

#define LetsChess 100

#pragma comment(lib,"ws2_32")
#include "socket.h"
#include "chess.h"
#include "grapics.h"

//포인터를 쓰는 이유는
void RecvThreadPoint(void* param) //param으로는 ((void*) sock)이 들어온다
{
	SOCKET sock = (SOCKET)param;
	// msg = 메시지를 넣을 버퍼
	char msg[LetsChess] = "";

	// recv는 소켓으로부터 데이터가 들어오면 들어온 데이터의 크기를 반환
	// 즉 소켓으로 데이터가 들어왔는지 체크
	while (1)
	{
		recv(sock, msg, LetsChess, 0);
		
		// 받은 값을 해석
		// 예) 0013이 들어오면 xy 00에 있던 말을 xy 13으로 이동
		// 즉 전에 값을 VOI로 만들고 뒤의 값의 위치로 이동
		chessGrid[msg[2] - 48][msg[3] - 48] = chessGrid[msg[0] - 48][msg[1] - 48];
		chessGrid[msg[0] - 48][msg[1] - 48] = VOI;

		drawCharacter(msg[2] - 48, msg[3] - 48, CHARCOLOR(chessGrid[msg[2] - 48][msg[3] - 48]), retCharPtr(CHARCOLOR(chessGrid[msg[2] - 48][msg[3] - 48])));
		drawCore(msg[0] - 48, msg[1] - 48);

		for (int i = 0; i < LetsChess; i++)
			msg[i] = 0;
	}
}


// sock을 세팅하는 함수
void sockSetting()
{
	WSAStartup(MAKEWORD(2, 2), &wsdata);


	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // TCP = 통신을 할 때 쓰는 프로토콜
	if (sock == -1)
	{
		// -1을 리턴하면 오류, 즉 종료
		printf("-1");
		exit(0);
	}

	// 내가 들어갈 서버의 포트를 넣기
	SOCKADDR_IN servaddr = { 0 };// 소켓주소(구조체 사용)
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
	servaddr.sin_port = htons(PORT_NUM);

	// 통신이 잘 됐는지 확인
	int re = 0;
	re = connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));// 연결 요청
	if (re == -1) { exit(0); } //통신이 잘못 되었을 때
	// 쓰레드 사용!!!
	_beginthread(RecvThreadPoint, 0, (void*)sock);

}