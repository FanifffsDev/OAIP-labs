#include <iostream>

using namespace std;

int getIntValue(){
    int a;
    while(scanf("%d", &a) != 1){
        while(getchar() != '\n') {}
        cout << "this is not a number" << endl;
        a = 0;
    }

    return a;
}