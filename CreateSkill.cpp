#include <bits/stdc++.h>
#include "Skill.hpp"
// #include "Property.hpp"
using namespace std;

vector <string> NameList = {
    "A","I","U","E","O",
    "Ra","Ri","Ru","Re","Ro",
    "Sa","Shi","Su","Se","So",
    "Ta","Chi","Tsu","Te","To",
    "Na","Ni","Nu","Ne","No",
    "Ma","Mi","Mu","Me","Mo",
    "Ka","Ki","Ku","Ke","Ko",
    "Ya","Yu","Yo",
    "Ha","Hi","Hu","He","Ho",
    "Wa","Wo",
    "Ga","Gi","Gu","Ge","Go",
    "Za","Ji","Zu","Ze","Zo",
    "Da","Ji","Zu","De","Do",
    "Ba","Bi","Bu","Be","Bo",
    "Pa","Pi","Pu","Pe","Po",
    };

map <string,bool> mp;

int main()
{
    srand(time(NULL));
    freopen("SkillList.txt","w",stdout);
    for(int i = 1; i <= 1000; i++){
        int lenn = rand() % 3 + 2;
        string name;
        do{
            string tem;
            for(int l = 1; l <= lenn; l++)
            {
                tem += NameList[rand()%NameList.size()];
            }
            name = tem;
        }while(mp[name] == 1);
        mp[name] = 1;
        cout << name << "_,_";
        
    }
}