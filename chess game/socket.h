//WinSock2 ��������� ����ϴµ� ������ ������
#pragma once




// ������ ����
SOCKET sock;
// ������ ��� ���ۿ�
WSADATA wsdata;

//�����͸� ���� ������
void RecvThreadPoint(void* param); //param���δ� ((void*) sock)�� ���´�

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
//	// ���μ����� ������ �ʵ���
//	while (1) {
//		// ������� �񵿱������� ���� ����,
//		// �޴� �� / �� ���� �񵿱������� �ϱ� ����	
//		scanf("%s", msg);
//		send(sock, msg, sizeof(msg), 0);
//	}
//}


// sock�� �����ϴ� �Լ�
void sockSetting();