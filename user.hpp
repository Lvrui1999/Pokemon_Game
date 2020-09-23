#include <iostream>
#include <string>
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
        tem = username + ":";
        for(auto p : list){
            tem += p.get_string();
        }
        return tem;  
    }
    void in_string(std::string data){
        std::string name;
        int now = 0;
        int l = data.size();
        for(int i = 0; i < l; i++){
            if(data[i] == ':'){
                now = i + 1;
                break;
            }
            name += data[i];
        }
        make_name(name);
        name.clear();
        for(int i = now; i < l; i++){
            if(data[i] == ';'){
                list.push_back(Poke(name));
                name.clear();
            }
            else{
                name.append(data[i]);
            }
        }
    }
};

