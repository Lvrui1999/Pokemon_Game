#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "pokemon.hpp"
#pragma once
class Dict{
public:
    Dict(){}
    std::vector <Pokemon> v;
    int trans(std::string s){
        std::stringstream ss;
        ss << s;
        int ans;
        ss >> ans;
        return ans;
    }
    void init(std::string filename){
        std::ifstream fs(filename);
//        char ss[300] = filename;
//        std::cout << 1 << std::endl;
        std::string s;
        while(fs >> s){
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
                    tt.push_back(c);
                }
            }
//            std::cout << tem[0] << " " << tem[1] << " " << tem[2] << " " << tem[3] << " ";
            v.push_back(Pokemon(tem[0],trans(tem[1]),trans(tem[2]),trans(tem[3]),trans(tem[4]),trans(tem[5]),trans(tem[6])));
//            cout << tem[0] << ",";
        }
    }
};
