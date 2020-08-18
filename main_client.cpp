#include <bits/stdc++.h>
#include "socket.hpp"
#include "poke.hpp"
using namespace std;

int main(){
    client c = client();
    vector <Poke> v;
    c.init();
    while(1){
        cout << "Login(1) or Register(2)" << endl;
        int t;
        cin >> t;
        if(t == 1){
            while(1){
                cout << "Input username:";
                string uname;
                cin >> uname;
                cout << "Input password:";
                string pword;
                cin >> pword;
                if(c.login(uname,pword)){
                    v = c.getpoke(uname); //Todo!!!!!!!!!
                    break;
                }
                else{
                    cout << "Wrong password or username" << endl;
                    int x;
                    cin >> x;
                    system("cls");
                }
            }
            break;
        }
        else if(t == 2){
            cout << "Input username:";
            string uname;
            cin >> uname;
            cout << "Input password:";
            string pword;
            cin >> pword; 
            c.regist(uname,pword);
            v = init();
            break;
        }
        else{
            system("cls");
        } 
    } 
}