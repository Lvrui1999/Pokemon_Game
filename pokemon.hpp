#include <iostream>
#include <string>
#include "poke.hpp"
#pragma once
class Pokemon{
private:
    std::string name;
    int type;
    int atk;
    int def;
    int heal;
    int at;
    int bias;
public:
    Pokemon(string name, int type, int atk, int def, int heal, int at, int bias = 2):name(name),type(type),atk(atk),def(def),heal(heal),at(at),bias(bias){

    }
    Poke getone(){
        int Atk = atk + rand()%bias * (rand() % 2 == 0? -1 : 1);
        int Def = def + rand()%bias * (rand() % 2 == 0? -1 : 1);
        int Heal = heal + rand()%bias * (rand() % 2 == 0? -1 : 1);
        return Poke(type,name,Atk,Def,Heal,at);
    }
};
