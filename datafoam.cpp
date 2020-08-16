#include <bits/stdc++.h>
#include "pokemon.hpp"
using namespace std;

string posname[50] = {"A","I","U","E","O","Sa","Si","Su","Se","So","Ta","Chi","Tsu","Te","To","Ma","Mi","Mu","Me","Mo","Na","Ni","Nu","Ne","No","Ga","Gi","Gu","Ge","Go",
"Ra","Ri","Ru","Re","Ro","Pa","Pi","Pu","Pe","Po","Ba","Bi","Bu","Be","Bo", "Ka", "Ki", "Ku", "Ke", "Ko"};

map<string,bool> mp;

int main(){
    srand(time(NULL));
    freopen("Pokemon.txt","w",stdout);
    for(int i = 0; i < 100; i++){
        string name;
        int namelen = rand()%3 + 2;
        do{
            name = "";
            for(int i = 1; i <= namelen; i++){
                name += posname[rand()%50];
            }
        }while(mp[name]);
        mp[name] = 1;
        int type = i % 4 + 1;
        int atk,def,heal,at;
        int sum = rand()%20 + 10;
        switch(type){
        case 1:
            atk = sum * 0.6;
            def = sum * 0.1;
            heal = sum - atk - def;
            at = 2;
            break;
        case 2:
            atk = sum * 0.3;
            def = sum * 0.1;
            heal = sum - atk - def;
            at = 3;
            break;
        case 3:
            atk = sum * 0.1;
            def = sum * 0.6;
            heal = sum - atk - def;
            at = 3;
            break;
        case 4:
            atk = sum * 0.5;
            def = sum * 0.25;
            heal = sum - atk - def;
            at = 1;
            break;
        } 
        int bias = (rand()%10 > 3?2:rand()%5 + 1);
        cout << "{" << name << "," << type << "," << atk << "," << def << "," << heal << "," << at << "," << bias << "}" <<endl;
    }
}