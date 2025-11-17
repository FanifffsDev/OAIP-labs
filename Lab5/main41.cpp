#include "../inputUtils.h"
#include "../arrayUtils.h"

using namespace std;

int main(){
    int m = 3, n = 3;

    int matrix[m][n];
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Введите элемент " << i + 1 << "/" << j + 1 << endl;
            matrix[i][j] = getInt();
        }      
    }

    for (int i = 0; i < m; i++)
    {
        cout << "[ ";
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";       
        }      
        cout << "]" << endl;
    }

    cout <<  endl;

    int count = 0;
    int tmpArray[18];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(matrix[i][j] < 0){
                tmpArray[count] = matrix[i][j];
                count++;
            }
        }      
    }   

    if(count == 0){
        std::cout << "нет отрицательных элементов.";
        return -1;
    }

    int rArray[count];

    for (int i = 0; i < count; i++)
    {
        rArray[i] = tmpArray[i];
    }       

    
    printIntArray(rArray, count);

    return 0;
}