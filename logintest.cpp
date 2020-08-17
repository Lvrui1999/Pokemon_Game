#include <bits/stdc++.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib") 
using namespace std;

class Server{

};

int main(int argc, char* argv[]){
    if(strcmp(argv[argc - 1],"-s")==0){
        WORD sockVersion = MAKEWORD(2, 2);  	
        WSADATA wsaData;   	
        if (WSAStartup(sockVersion, &wsaData) != 0) //WSAStartup返回0表示设置初始化成功
            return 0; 
        
        /*创建套接字*/
        //AF_INET表示IPv4，SOCK_STREAM数据传输方式，IPPROTO_TCP传输协议;
        SOCKET listenSocket = socket(AF_INET,SOCK_DGRAM, 0);
        if (listenSocket == INVALID_SOCKET)
        {
            printf("Create Fail");
            WSACleanup();
            return 0;
        }
        sockaddr_in addrListen;
        addrListen.sin_family = AF_INET;     //指定IP格式
        addrListen.sin_port = htons(8888);   //绑定端口号
        addrListen.sin_addr.S_un.S_addr = INADDR_ANY;  //表示任何IP   service.sin_addr.s_addr = inet_addr("127.0.0.1");
        if (bind(listenSocket, (SOCKADDR*)&addrListen, sizeof(addrListen)) == SOCKET_ERROR)  //(SOCKADDR*)
        {
            printf("Bind Fail");
            closesocket(listenSocket);
            return 0;
        }
        if (listen(listenSocket, 5) == SOCKET_ERROR)
        {
            printf("Listen Fail");
            closesocket(listenSocket); 
            return 0;
        }
        SOCKET revSocket;  //对应此时所建立连接的套接字的句柄
        sockaddr_in remoteAddr;   //接收连接到服务器上的地址信息
        int remoteAddrLen = sizeof(remoteAddr);	
        printf("Waiting...\n");
        /*等待客户端请求，服务器接收请求*/
        revSocket = accept(listenSocket, (SOCKADDR*)&remoteAddr, &remoteAddrLen);  //等待客户端接入，直到有客户端连接上来为止
        if (revSocket == INVALID_SOCKET)
        {
            printf("Client Send but Recv Fail\n",WSAGetLastError());
            closesocket(listenSocket);
            WSACleanup();
            return 0;
        }
        else
        {
            printf("Connect Success %s \n", inet_ntoa(remoteAddr.sin_addr));
        }
        // char *sendData = new char[100];
        /*通过建立的连接进行通信*/
        while(1){
            char revData[255] = "";
            int res = recv(revSocket, revData, 255, 0);
            if (strcmp(revData,"End") == 0){
                printf("Connection closed\n");
                break;
            }
            if (res > 0)
            {
                printf("Bytes received: %d\n", res);
                printf("Data Recv: %s\n", revData);
            }
            else if (strcmp(revData,"End") == 0){
                printf("Connection closed\n");
                break;
            }
            else
                printf("recv failed: %d\n", WSAGetLastError());
            if(strcmp(revData,"End") == 0)break;
        }
        // while (cin>>sendData)
        // {
        //     //cout << strlen(sendData) << endl;
        //     if (strcmp(sendData, "q") == 0)
        //     {
        //         printf("Server stop send！\n");
        //         break;
        //     }		
        //     //发送数据
        //     send(revSocket, sendData, strlen(sendData), 0);
        // }
    }
    else{   
        WORD sockVerson = MAKEWORD(2, 2);
        WSADATA wsaData;
        if (WSAStartup(sockVerson, &wsaData) != 0)
            return 0;
        
        //建立客户端socket
        SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (clientSocket == INVALID_SOCKET)
        {
            printf("Create Fail");
            WSACleanup();
            return 0;
        }
        sockaddr_in addrConServer;
        addrConServer.sin_family = AF_INET;
        addrConServer.sin_port = htons(8888);
        addrConServer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        if (connect(clientSocket, (SOCKADDR*)&addrConServer, sizeof(addrConServer)) == SOCKET_ERROR)
        {
            printf("Connect Fail！\n");
            closesocket(clientSocket);
            WSACleanup();
            return 0;
        }
        else 
            printf("Connect Success!\n");
        while(1){
            char sendBuf[255];
            gets(sendBuf);
            
            int sendRes = send(clientSocket, sendBuf, (int)strlen(sendBuf), 0);
            if (sendRes == SOCKET_ERROR)
            {
                printf("Send Error %d\n", WSAGetLastError());
                closesocket(clientSocket);
                WSACleanup();
                return 0;
            }
            else
                printf("Send Success!\n");
            if(strcmp(sendBuf,"End") == 0)break;
        }
        //接收服务端数据
        /*通过建立的连接进行通信*/
        // int res;
        // do
        // {	
        //     char revSerData[100] = "";
        //     res = recv(clientSocket, revSerData, sizeof(revSerData), 0);
        //     if (res > 0)
        //     {
        //         printf("Bytes received: %d\n", res);
        //         printf("Data recv: %s\n", revSerData);
        //     }
        //     else if (res == 0)
        //         printf("Connection closed\n");
        //     else
        //         printf("recv failed: %d\n", WSAGetLastError());
        // } while (res > 0);
        closesocket(clientSocket);
        WSACleanup();
    }                                                           
    // close(l);
}