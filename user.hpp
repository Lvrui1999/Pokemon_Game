#include <bits/stdc++.h>
#include "pokemon.hpp"
#include "pokemondict.hpp"

class user
{
private:
    std::string username;
    std::vector <Poke> list;
    /* data */
public:
    void init(){
        Dict pd = Dict();
        srand(time(NULL));
        for(int i = 0; i < 3; i++){
            list.push_back(pd.v[rand()%pd.v.size()].getone());
        }
    }
    void make_name(std::string name){
        username = name;
    }
    std::string get_string(){
        std::string tem;
        tem += username + ":";
        for(auto p : list){
            tem += p.get_string();
        }
        return tem;
    }
    void in_string(std::string){
        
    }
};

