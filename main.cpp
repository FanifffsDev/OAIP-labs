#include <iostream>
#include <random>
#include "inputUtils.h"

using namespace std;

int main(){
    int n;

    srand(time(nullptr));

    cout << "Введите количество участников: ";
    n = getIntInRange(3, 100);
  

    int* scores = new int[n];

    for (int i = 0; i < n; i++)
    {
        scores[i] = rand() % 50;

        cout << "[\033[32m" << i + 1 << "\033[0m]" << " Участник : \033[33m" << scores[i] << "\033[0m пончиков" << endl;
    }

    int index[3] = {0, 0, 0};
    int score[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == 0){
                if(score[0] < scores[j]){
                    score[0] = scores[j];
                    index[0] = j;
                }
            }
            else{
                if(score[i] < scores[j] && scores[j] <= score[i-1] && j != index[i-1]){
                    score[i] = scores[j];
                    index[i] = j;
                }
            }
        }       
    }
    
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << " место: " << " Участник номер \033[32m" << index[i] + 1<< "\033[0m съел \033[33m" << score[i] << "\033[0m пончиков!" << endl;
    }
    
    return 0; 
}