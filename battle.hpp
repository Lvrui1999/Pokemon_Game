#include "pokemon.hpp"
#include "rand.hpp"
class Battle{
private:
    Poke a;
    Poke b;
    MyRand mr; 
public:
    Battle(Poke aa, Poke bb){
        a = aa;
        b = bb;
        mr = MyRand();
    }
    int BattleSimulate(){
        int iv1 = a.getint();
        int iv2 = b.getint();
        int a1 = a.getatk();
        int a2 = b.getatk();
        int d1 = a.getdef();
        int d2 = b.getdef();
        int h1 = a.getheal();
        int h2 = b.getheal();
        int cnt = 0;
        do{
            //暴击
            if(cnt % iv1){
                h2 -= (a1 - d2 > 0? a1 - d2 : 1);
            }
            if(cnt % iv2){
                h1 -= (a2 - d1 > 0? a2 - d1 : 1);
            }
            if(h1 < 0 && h2 < 0){
                return 0;
            }
            if(h1 < 0){
                return -1;
            }
            if(h2 < 0){
                return 1;
            }
        }while(true);
    }
};