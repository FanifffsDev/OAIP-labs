#include "inputUtils.h"
#include "arrayUtils.h"
#include <random>

using namespace std;

int main(){
    int m, n;
    
    cout << "Введите количество строк: " << endl;
    m = getInt();

    cout << "Введите количество столбцов: " << endl;
    n = getInt();

    srand(time(nullptr));

    int** matrix = new int*[m];
    int** resMatrix = new int*[m];

    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
        resMatrix[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = -30 + rand() % 60;
        }      
        printIntArray(matrix[i], n);
    }

    cout << endl;

    int * tmpRow = new int[m];
    int * rowIndexes = new int[m];

    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j] > 0 && matrix[i][j] % 2 == 0){
                sum += matrix[i][j];
            }
        }    
        rowIndexes[i] = i;
        tmpRow[i] = sum;  
    }

    printIntArray(rowIndexes, m);
    printIntArray(tmpRow, m);

    cout << endl;

    int tmp = 0;
    int tmpIndex = 0;

    for (int i = 0; i < m - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < m - i - 1; j++) {
            if (tmpRow[j] > tmpRow[j + 1]) {            
                tmp = tmpRow[j];
                tmpIndex = rowIndexes[j];

                tmpRow[j] = tmpRow[j + 1];
                tmpRow[j + 1] = tmp;

                rowIndexes[j] = rowIndexes[j + 1];
                rowIndexes[j + 1] = tmpIndex;
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }
    

    printIntArray(rowIndexes, m);
    //printIntArray(tmpRow, m);

    for (int i = 0; i < m; i++) {
        int originalIndex = rowIndexes[i];
        for (int j = 0; j < n; j++) {
            resMatrix[i][j] = matrix[originalIndex][j];
        }
    }

    cout << endl;
    for (int i = 0; i < m; i++) {
        printIntArray(resMatrix[i], n);
        
    }
    

    for (int i = 0; i < m; ++i) {
        delete [] matrix[i];
        delete[] resMatrix[i];
    }

    delete [] matrix;

    delete[] resMatrix;
    delete [] tmpRow;
    delete [] rowIndexes;
}