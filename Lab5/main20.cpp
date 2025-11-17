#include "../inputUtils.h"

using namespace std;

int main(){
    int m, n;
    
    cout << "Введите количество строк: " << endl;
    m = getInt();

    cout << "Введите количество столбцов: " << endl;
    n = getInt();

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

    int row = 0;
    for (int i = 0; i < m; i++)
    {
        int tmp = 0;
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j] > tmp){
                tmp = matrix[i][j];
            }
            else{
                break;
            }
        }      

        if(tmp == matrix[i][0]){
            row = i;
            break;
        }
    }   

    int rMatrix[n];

    for (int j = 0; j < n; j++)
    {
        rMatrix[j] = matrix[row][n - 1 - j];
    }      

    for (int j = 0; j < n; j++)
    {
        matrix[row][j] = rMatrix[j];
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

    return 0;
}