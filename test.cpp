#include <iostream>
using namespace std;
int main(){
    int i = 1001;
    while(i >= 0){
        cout << i << endl;
        i += 100000;
    }
    return 0;
}