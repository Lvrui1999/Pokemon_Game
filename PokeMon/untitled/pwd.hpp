#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Pwd{
private:
    std::string storepath = "./pwd/password.txt";
    std::vector <std::string> username;
    std::vector <std::string> password;
public:
    void init(){
        std::ifstream input(storepath);
        // input.open(storepath,std::ios::in);
        std::string s;
        while(getline(input,s)){
            std::string uname,pword;
            bool x = 0;
            for(auto c : s){
                if(c == ':'){
                    x = 1;
                    continue;
                }
                if(x){
                    pword.push_back(c);
                }
                else{
                    uname.push_back(c);
                }
            }
            username.push_back(uname);
            password.push_back(pword);
        }
        input.close();
    }
    bool match(std::string uname, std::string pword){
        for(int i = 0; i < username.size(); i++){
            if(username[i] == uname){
                if(password[i] == pword){
                    return true;
                }
                return false;
            }
        }
    }
    bool regist(std::string uname, std::string pword){
        for(int i = 0; i < username.size(); i++){
            if(username[i] == uname){
                return 0;
            }
        }
        username.push_back(uname);
        password.push_back(pword);
        maintain();
        return 1;
    }
    void maintain(){
        std::ofstream output(storepath);
        for(int i = 0; i < username.size(); i++){
            output << username[i] << ":" << password[i] << std::endl;
        }
        output.close();
    }
    
};
