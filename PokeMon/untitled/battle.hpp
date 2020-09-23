#include "pokemon.hpp"
#include "rand.hpp"
class Battle{
private:
    MyRand ma = MyRand();
    MyRand mb = MyRand();
    MyRand sa = MyRand();
    MyRand sb = MyRand();
public:
    Poke a;
    Poke b;
    Battle(){}
    Battle(Poke aa, Poke bb){
        a = aa;
        b = bb;
    }
    int val(bool side,int cnt){
        if(side){
            bool sha = sb.getArray(1)[cnt];
            int atk = a.getatk() * (ma.getArray(2)[cnt] ? 2 : 1);
            int def = b.getdef();
            if(ma.getArray(2)[cnt])std::cout << "BaoJi" << std::endl;
            if(sha){
                std::cout << "ShanBi" << std::endl;
                return 0;
            }
            else return atk > def?atk-def:1;
        }
        else{
            bool sha = sa.getArray(1)[cnt];
            int atk = b.getatk() * (mb.getArray(2)[cnt] ? 2 : 1);
            int def = b.getdef();
            if(mb.getArray(2)[cnt])std::cout << "BaoJi" << std::endl;
            if(sha){
                std::cout << "ShanBi" << std::endl;
                return 0;
            }
            else return atk > def?atk-def:1;
        }
    }
};
