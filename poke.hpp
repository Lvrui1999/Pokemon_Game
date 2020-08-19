#include <bits/stdc++.h>
using namespace std;

class Poke{
private:
    int type;
    string name;
    int level;
    int exp;
    int atk;
    int def;
    int heal;
    int attinterval;
public:
    Poke(int type, string name, int atk, int def, int heal, int at,int level = 1, int exp = 0):type(type),name(name),atk(atk),def(def),heal(heal),attinterval(at),level(level),exp(exp){}
    void leveladp(int expget){
        if(level == 15){
            return;
        }
        exp += expget;
        if(exp >= level * 20 && level < 15){
            exp -= level * 20;
            level++;
            if(level == 15){
                exp = 0;
            }
            update();
            return;
        }
    }
    void update(){
        // 各个精灵差异
        // int add = 20;
        switch (type){
        case 1:
            atk += 12;
            def += 2;
            heal += 6;
            // attinterval += 5;
            break;
        case 2:
            atk += 6;
            def += 2;
            heal += 12;
            // attinterval += 2;
            break;
        case 3:
            atk += 2;
            def += 12;
            heal += 6;
            // attinterval += 2;
            break;
        case 4:
            atk += 8;
            def += 4;
            heal += 4;
            // attinterval += 5;
            break;
        }
    }
    int getint(){
        return this->attinterval;
    }
    int getheal(){
        return this->heal;
    }
    int getdef(){
        return this->def;
    }
    int getatk(){
        return this->atk;
    }
    friend ostream &operator <<(ostream &output, const Poke x){
        output << x.atk << " " << x.def << " "  << x.level << " " << x.exp << " " << x.heal << " " << x.type;
        return output;
    }
    std::string trans(int x){
        std::stringstream ss;
        ss << x;
        std::string ans;
        ss >> ans;
        return ans;
    }
    std::string get_string(){
        string tem;
        tem += tran(type) << ",";
        tem += name << ",";
        tem += trans(atk) << ",";
        tem += trans(def) << ",";
        tem += trans(heal) << ",";
        tem += trans(attinterval) << ",";
        tem += trans(level) << ",";
        tem += trans(exp) << ";";
        return tem;
        // tem += trans(atk) << ",";
    }
};