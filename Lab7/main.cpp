#include "../inputUtils.h"
#include "main.h"
#include <cstring>

using namespace std;

int main(){

    bool shouldExit = false;
    while (!shouldExit)
    {
        try{
            system("clear");
            cout << "1 - Задача 1" << endl;
            cout << "2 - Задача 2" << endl;
            cout << "3 - Закрыть программу" <<  endl;
            cout << "Выберете вариант из списка сверху: ";

            int choice = getInt();

            switch(choice){
                case 1:
                    task1();
                    break;

                case 2:
                    task2();
                    break;

                case 3:
                    shouldExit = true;
                    break;

                default:
                    break;
            }
        }
        catch(...){
            cout << "что-то пошло не так...\n";
        }
        
    }
    return 0;
}

void task1(){
    system("clear");
    cout << "Проверить, все ли строки матрицы упорядочены по убыванию. Если нет, найти первую неупорядоченную строку и упорядочить.\n\n";

    int rows, cols;
    
    cout << "Введите количество строк: ";
    rows = getInt();
    cout << "Введите количество столбцов: ";
    cols = getInt();
    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Введите элемент " << i + 1 << "/" << j + 1 << endl;
            matrix[i][j] = getInt();
        }      
    }
   
    printMatrix(matrix, rows, cols);
    
    bool allSorted = true;
    int firstUnsortedRow = -1;
    
    for (int i = 0; i < rows; i++) {
        if (!isRowDown(matrix[i], cols)) {
            allSorted = false;
            firstUnsortedRow = i;
            break;
        }
    }
    
    if (allSorted) {
        cout << "Все строки упорядочены по убыванию!" << endl;
    } else {
        cout << "Не все строки упорядочены по убыванию." << endl;
        cout << "Первая неупорядоченная строка: " << firstUnsortedRow + 1 << endl;
        
        bubbleSort(matrix[firstUnsortedRow], cols);
        
        cout << "\nМатрица после сортировки строки:\n";
        printMatrix(matrix, rows, cols);
    }
    
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    cout << "\nНажмите Enter для продолжения...";
    cin.get();
}

bool isRowDown(int* row, int cols) {
    for (int j = 0; j < cols - 1; j++) {
        if (row[j] < row[j + 1]) {
            return false;
        }
    }
    return true;
}

void bubbleSort(int* row, int cols) {
    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (row[j] < row[j + 1]) {
                int temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        cout << "[";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "]";
        cout << endl;
    }
}

void task2(){
    const int MAX_SIZE = 1000;
    char text[MAX_SIZE];

    system("clear");
    cout << "Ввести текст. Подсчитать, сколько слов в тексте начинается на букву а (слова разделены пробелом).\n\n";
    
    cout << "Введите текст: ";
    cin.getline(text, MAX_SIZE);
    
    int count = 0;
    
    char *word = strtok(text, " ");
    
    while (word != NULL) {
        if (word[0] == 'a' || word[0] == 'A') { 
            count++;
        }
        word = strtok(NULL, " ");
    }
    
    cout << "\nКоличество слов, начинающихся на букву 'а': " << count << endl;
    
    cout << "\nНажмите Enter для продолжения...";
    cin.get();
}