//WinSock2 헤더파일을 사용하는데 오류를 없애줌
#pragma once




// 소켓을 생성
SOCKET sock;
// 소켓을 담는 버퍼와
WSADATA wsdata;

//포인터를 쓰는 이유는
void RecvThreadPoint(void* param); //param으로는 ((void*) sock)이 들어온다

//int main()
//{
//	char msg[LetsChess] = { 0, };
//	
//
//
//	for (int i = 0; i < LetsChess; i++)
//		msg[i] = 0;
//
//
//	// 프로세스를 꺼지지 않도록
//	while (1) {
//		// 쓰레드는 비동기적으로 일을 수행,
//		// 받는 수 / 송 신을 비동기적으로 하기 위해	
//		scanf("%s", msg);
//		send(sock, msg, sizeof(msg), 0);
//	}
//}


// sock을 세팅하는 함수
void sockSetting();