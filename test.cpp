#include <bits/stdc++.h>
#include "socket.hpp"
using namespace std;

int main(int argc, char* argv[]){
    if(argc > 1){
        server s = server();
        s.init();
        s.run();
    }
    else{
        client c = client();
        c.init();
        cout << c.login("123","123");
    }
    // p.maintain();
}