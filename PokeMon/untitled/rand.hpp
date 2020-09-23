#include <time.h>
#include <vector>
class MyRand{
private:
    std::vector <bool> randArray[11];
public:
    MyRand(){
        srand((unsigned)time(NULL));
        for(int i = 0; i <= 10; i++){
            int cntx = 10;
            int cnty = i;
            for(int j = 0; j < 10; j++){
                int r = rand() % cntx;
                if(r < cnty){
                    randArray[i].push_back(1);
                    cnty--;
                    cntx--;
                }
                else{
                    randArray[i].push_back(0);
                    cntx--;
                }

            }
        }
    }
    std::vector <bool> getArray(int n){
        return randArray[n];
    }
};
