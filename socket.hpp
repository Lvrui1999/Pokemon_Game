#include <iostream>
#include <string>
#include <vector>
#include <winsock2.h>
#include "pwd.hpp"
using namespace std;
class server{
private:
    std::vector <pair<std::string,sockaddr_in>> online_list;
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
                std::cout << buffer << std::endl;
                std::string tem1,tem2;
                bool x = 0;
                char mode = buffer[0];
                for(int i = 1; i < 1024; i++){
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
                if(mode == 'l'){
                    bool val = sys.match(tem1,tem2);
                    if(val == 1){
                        bool find = 0;
                        for(auto p : online_list){
                            if(tem1 == p.first){
                                find = 1;
                                break;
                            }
                        }
                        if(!find)
                        {
                            online_list.push_back(make_pair(tem1,from));
                            buffer[0] = '1';
                        }
                        else{
                            buffer[0] = '0';
                        }
                    }
                    else{
                        buffer[0] = '0';
                    }
                    sendto(listenSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&from, fromlen);
                }
                else if(mode == 'r'){
                    bool val = sys.regist(tem1,tem2);
                    if(val == 1){
                        buffer[0] = '1';
                    }
                    else{
                        buffer[0] = '0';
                    }
                    sendto(listenSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&from, fromlen);
                }
                else if(mode == 'f'){
                    // cout << tem1 << endl;
                    tem1.append(".txt");
                    tem1 = "./Per/" + tem1;
                    std::ifstream input(tem1);
                    input >> tem2;
                    // cout << tem2;
                    for(int i = 0; i < tem2.size(); i++){
                        buffer[i] = tem2[i];
                    }
                    sendto(listenSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&from, fromlen);
                    // freopen("CON", "r", stdin);
                    input.close();
                }
                else if(mode == 's'){
                    tem1.append(".txt");
                    tem1 = "./Per/" + tem1;
                    std::ofstream output(tem1);
                    output << tem2;
                    // freopen("CON", "w", stdout);
                    output.close();
                }
                else if(mode == 'e'){
                    std::vector <pair<std::string,sockaddr_in>> new_list;
                    // buffer[0] = 'e';
                    // for(int i = 1; i < tem1.size(); i++){
                    //     buffer[i] = tem1[i];
                    // }
                    for(auto p : online_list){
                        if(p.first != tem1){
                            new_list.push_back(p);
                            // sockaddr_in add = p.second;
                            // sendto(listenSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&add, sizeof(add));
                        }
                    }
                    online_list = new_list;
                }
                else if(mode == 'g'){
                    int now = 0;
                    for(auto p : online_list){
                        for(int i = 0; i < p.first.size(); i++){
                            buffer[now] = p.first[i];
                            now++;
                        }
                        buffer[now] = ';';
                        now++;
                    }
                    sendto(listenSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&from, sizeof(from));
                }
                else if(mode == 'a'){
                    std::vector <std::string> v = sys.all();
                    int now = 0;
                    for(auto p : v){
                        for(int i = 0; i < p.size(); i++){
                            buffer[now] = p[i];
                            now++;
                        }
                        buffer[now] = ';';
                        now++;
                    }
                    printf("%s",buffer);
                    sendto(listenSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&from, sizeof(from));
                }
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
        char buffer[1024] = {'l'};
        for(int i = 0; i < s.size(); i++){
            buffer[i + 1] = s[i];
        }
        sendto(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, slen);
        recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, &slen);
        if(buffer[0] == '0')return 0;
        else return 1;
        return 0;
    }
    bool regist(std::string a, std::string b){
        std::string s = a + ':' + b;
        char buffer[1024] = {'r'};
        for(int i = 0; i < s.size(); i++){
            buffer[i + 1] = s[i];
        }
        sendto(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, slen);
        recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, &slen);
        if(buffer[0] == '0')return 0;
        else return 1;
        return 0;
    }
    string getdata(std::string uname){
        char buffer[1024] = {'f'};
        for(int i = 0; i < uname.size(); i++){
            buffer[i + 1] = uname[i];
        }
        sendto(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, slen);
        recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, &slen);
        std::string fu;
        for(int i = 0; i < strlen(buffer); i++){
            fu.push_back(buffer[i]);
        }
        return fu;
    }
    string get_user(){
        char buffer[1024] = {'g'};
        sendto(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, slen);
        recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, &slen);
        std::string fu;
        for(int i = 0; i < strlen(buffer) - 1; i++){
            fu.push_back(buffer[i]);
        }
        return fu;
    }
    void Exit(std::string uname){
        char buffer[1024] = {'e'};
        for(int i = 0; i < uname.size(); i++){
            buffer[i + 1] = uname[i];
        }
        sendto(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, slen);
    }
    void save(std::string s){
        char buffer[1024] = {'s'};
        for(int i = 0; i < s.size(); i++){
            buffer[i + 1] = s[i];
        }
        sendto(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrConServer, slen);
    }
};

