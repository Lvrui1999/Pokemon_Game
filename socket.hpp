#include <bits/stdc++.h>
#include <winsock2.h>
#include "pwd.hpp"
class server{
private:
    SOCKET listenSocket;
    sockaddr_in addrListen;
    sockaddr_in from;
    Pwd sys;
    int fromlen = sizeof(from);
public:
    int init(){
        sys = Pwd();
        sys.init();
        WORD sockVersion = MAKEWORD(2, 2);  	
        WSADATA wsaData;   	
        if (WSAStartup(sockVersion, &wsaData) != 0)
            return -1; 
        listenSocket = socket(AF_INET, SOCK_DGRAM, 0);
        if (listenSocket == INVALID_SOCKET)
        {
            WSACleanup();
            return -1;
        }
        addrListen.sin_family = AF_INET;     //指定IP格式
        addrListen.sin_port = htons(8888);   //绑定端口号
        addrListen.sin_addr.S_un.S_addr = INADDR_ANY;  //表示任何IP   service.sin_addr.s_addr = inet_addr("127.0.0.1");
        if (bind(listenSocket, (SOCKADDR*)&addrListen, sizeof(addrListen)) == SOCKET_ERROR)  //(SOCKADDR*)
        {
            closesocket(listenSocket);
            return 0;
        }
        return 0;
    }
    void run(){
        while(1){
            char buffer[1024];
            if (recvfrom(listenSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&from, &fromlen) != SOCKET_ERROR)//阻塞接受客户端的请求  
            {  
                std::cout << "Recv" << std::endl;
                std::string tem1,tem2;
                bool x = 0;
                for(int i = 0; i < 1024; i++){
                    if(buffer[i] == 0)break;
                    if(buffer[i] == ':'){
                        x = 1;
                        continue;
                    }
                    if(!x){
                        tem1.push_back(buffer[i]);
                    }
                    else{
                        tem2.push_back(buffer[i]);
                    }
                }
                bool val = sys.match(tem1,tem2);
                if(val == 1){
                    buffer[0] = '1';
                }
                else{
                    buffer[0] = '0';
                }
                sendto(listenSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&from, fromlen);
            } 
        }
        return;
    }
};

class client{
private:
    SOCKET clientSocket;
    sockaddr_in addrConServer;
    int slen = sizeof(addrConServer);
public:
    int init(){
        WORD sockVerson = MAKEWORD(2, 2);
        WSADATA wsaData;
        if (WSAStartup(sockVerson, &wsaData) != 0)
            return -1;
        //建立客户端socket
        clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
        if (clientSocket == INVALID_SOCKET)
        {
            // printf("Create Fail");
            WSACleanup();
            return -1;
        }
        addrConServer.sin_family = AF_INET;
        addrConServer.sin_port = htons(8888);
        addrConServer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        return 0;
    }
    bool login(std::string a, std::string b){
        std::string s = a + ':' + b;
        char buffer[1024] = {0};
        for(int i = 0; i < s.size(); i++){
            buffer[i] = s[i];
        }
        sendto(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, slen);
        recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, &slen);
        if(buffer[0] == '0')return 0;
        else return 1;
        return 0;
    }
};

