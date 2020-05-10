#include <bits/stdc++.h>
#include "Skill.hpp"
#include "Property.hpp"
using namespace std;

class Pokemon{
    private:
        string name;
        vector <Property> type;
        vector <pair<Skill,int>> SkillTable;
};