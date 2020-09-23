#include "socket.hpp"

int main(){
    server s = server();
    s.init();
    s.run();
}