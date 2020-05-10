#include <bits/stdc++.h>
#include "Property.hpp"
using namespace std;

const int ExtraTypeCnt = 11;
const string ExtraDesp[] = {
    "",
    "Make your oppesite Poisoned",
    "Make your oppesite Burnt",
    "Make your oppesite Paralyze",
    "Make your oppesite Rest",
    "Make your oppesite Frozen",
    "Make your oppesite Flinch",
    "Make your oppesite Confusion",
    "Make your oppesite Infatuation",
    "Make your oppesite Bound",
    "Attack 2 to 5 times"
    };

class Skill{
    private:
        string SkillName;
        string Extra;
        int Possibility;
        int SkillPower;
        int SkillPP;
        Property Type;
        int Addition;
    public:
        Skill(string name,int ex, int poss, int power, int pp, Property Type):SkillName(name),Extra(ExtraDesp[ex]),Possibility(poss),SkillPower(power),SkillPP(pp),Type(Type),Addition(ex){}
        int CalDamage(){
            return 1;
        }
};