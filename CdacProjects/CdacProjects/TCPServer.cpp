#include<iostream>
#include<WinSock2.h>

using namespace std;

int main()
{
	WSADATA Winsockdata;
	int iWsaStartup;
	int iWsaCleanup;


	SOCKET TCPServerSocket;
	int iCloseSocket;

	struct sockaddr_in TCPServerAdd;
	struct sockaddr_in TCPClientAdd;
	int iTCPClientAdd = sizeof(TCPClientAdd);

	int iBind;
	int iListen;

	SOCKET sAcceptSocket;

	int iSend;
	char SenderBuffer[512] = "hello from server!";
	int iSenderBuffer = strlen(SenderBuffer);

	int iRecv;
	char RecvBuffer[512];
	int iRecvBuffer = strlen(RecvBuffer) + 1;

	//initialise wsastartup
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &Winsockdata);
	if (iWsaStartup != 0)
	{
		cerr << "Wsa Startup failed" << endl;
	}
	else
		cout << "Wsa Startup successfull" << endl;

	//filling the server details
	TCPServerAdd.sin_family = AF_INET;
	TCPServerAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
	TCPServerAdd.sin_port = htons(8000);

	//socket creation
	TCPServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (TCPServerSocket == INVALID_SOCKET)
	{
		cerr << "socket creation failed due to error :" << WSAGetLastError() << endl;
	}
	else
		cout << "socket creation successfull" << endl;

	//binding socket
	iBind = bind(TCPServerSocket, (SOCKADDR*)&TCPServerAdd,sizeof(TCPServerAdd));
	if (iBind == SOCKET_ERROR)
	{
		cerr << "binding filed due to error :" << WSAGetLastError() << endl;
	}
	else
		cout << "binding successfull" << endl;
	
	//listen function
	iListen = listen(TCPServerSocket, SOMAXCONN);
	if (iListen == SOCKET_ERROR)
	{
		cerr << "listen function failed due to error: " << WSAGetLastError() << endl;
	}
	else
		cout << "listen function successfull" << endl;
	
	//connect
	sAcceptSocket = accept(TCPServerSocket,(SOCKADDR*)&TCPClientAdd,&iTCPClientAdd);
	if (sAcceptSocket == INVALID_SOCKET)
		cerr << "accept failed due to error: " << WSAGetLastError() << endl;
	else
		cout << "accept successfull" << endl;

	//sending data
	iSend = send(TCPServerSocket,SenderBuffer, iSenderBuffer, 0);
	return 0;
}