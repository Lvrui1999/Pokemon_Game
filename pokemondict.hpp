#include <bits/stdc++.h>
#include "pokemon.hpp"

class Dict{
public:
    std::vector <Pokemon> v;
    int trans(std::string s){
        std::stringstream ss;
        ss << s;
        int ans;
        ss >> ans;
        return ans;
    }
    void init(std::string filename){
        std::ifstream input(filename);
        std::string s;
        while(getline(input,s)){
            std::vector<std::string> tem;
            std::string tt;
            for(auto c : s){
                if(c == '{')
                    continue;
                if(c == '}' || c == ','){
                    tem.push_back(tt);
                    tt.clear();
                }
                else{
                    tem.push_back(tt);
                }
            }
            v.push_back(Pokemon(tem[0],trans(tem[1]),trans(tem[2]),trans(tem[3]),trans(tem[4]),trans(tem[5]),trans(tem[6])));
        }
    }
};