#include <bits/stdc++.h>
#include "pokemon.hpp"
using namespace std;

int main(){
    auto r = Poke(1,"fuck",10,10,10,10);
    while(1){
        int n;
        cin >> n;
        r.leveladp(n);
        cout << r << endl;
    }
}