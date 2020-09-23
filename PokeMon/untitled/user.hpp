#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include "pokemon.hpp"
#include "pokemondict.hpp"


class user
{
private:
    std::string username;
    /* data */
public:
    void aw(){win++;}
    void al(){lose++;}
    std::vector <Poke> list;
    int win;
    int lose;
    void init(int cnt){
        win = 0;
        lose = 0;
        list.clear();
        Dict pd = Dict();
        std::string ss = "D:/XD/Pokemon_Game/data/Pokemon.txt";
        pd.init(ss);
//        std::cout << pd.v[0].getone().get_string() <<std::endl;
        srand(time(NULL));
        for(int i = 0; i < cnt; i++){
            list.push_back(pd.v[rand()%pd.v.size()].getone());
        }
    }
    void make_name(std::string name){
        username = name;
    }
    std::string get_name(){
        return username;
    }
    std::string trans(int val){
        stringstream ss;
        ss << val;
        std::string s;
        ss >> s;
        return s;
    }
    std::string get_string(){
//        std::cout << list.size() << endl;
        std::string tem;
        tem = username + ":";
        tem += trans(win) + '/' + trans(lose) + '/';
        for(auto p : list){
            tem += p.get_string();
        }
        return tem;  
    }
    void in_string(std::string data){
        list.clear();
        std::cout << data << std::endl;
        std::string name;
        int now = 0;
        int l = data.size();
        int cc = 0;
        int val = 0;
        for(int i = 0; i < l; i++){
            if(data[i] == '/'){
                cc++;
                if(cc == 1){
                    win = val;
                    val = 0;
                }
                if(cc == 2)
                {
                    lose = val;
                    now = i + 1;
                    break;
                }
                continue;
            }
            val *= 10;
            val += data[i] - '0';
        }
//        make_name(name);
        name.clear();
        for(int i = now; i < l; i++){
            if(data[i] == ';'){
                list.push_back(Poke(name));
                name.clear();
            }
            else{
                name += data[i];
            }
        }
    }
};

