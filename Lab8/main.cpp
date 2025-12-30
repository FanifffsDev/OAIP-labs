#include "../inputUtils.h"
#include <iostream>
#include <string.h>
#include <locale.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <wchar.h>
#include <codecvt>
#include <fstream>

using namespace std;

struct Book {
    int regNumber;
    char author[50];
    char title[100];
    int year;
    char publisher[50];
    int pages;
};

Book library[100];
Book temp;
int bookCount = 0;

void inputBook();
void sortBooks();
void searchBook();
void editBook();
void deleteBook();
void displayBooks();
void loadBooks();
void saveFile();
void loadFile();
int menu();
string truncate(const string &str, int width);
int displayWidth(string s);
string pad( string s, int width);

int main() {
    setlocale(LC_ALL, "rus");
    system("clear");

    while(1) {
        switch(menu()) {
            case 1: inputBook(); break;
            case 2: loadFile(); break;
            case 3: saveFile(); break;
            case 4: sortBooks(); break;
            case 5: searchBook(); break;
            case 6: editBook(); break;
            case 7: deleteBook(); break;
            case 8: displayBooks(); break;
            case 9: loadBooks(); break;              
            case 99:
                cout << "\nВыход из программы...\n";
                return 0;
            default: 
                cout << "\nНеверный выбор! Попробуйте снова.\n";
        }
    }
    return 0;
}

int menu() {
    int choice;
    cout << "\n========== Библиотека ==========\n";
    cout << "1. Добавить книгу\n";
    cout << "2. Загрузить из файла\n";
    cout << "3. Сохранить в файл\n";
    cout << "4. Сортировка книг\n";
    cout << "5. Поиск книги\n";
    cout << "6. Изменение книги\n";
    cout << "7. Удаление книги\n";
    cout << "8. Вывод на экран всех книг\n";
    cout << "9. Рандомные книги\n";
    cout << "99. Выход\n";
    cout << "================================\n";
    cout << "Всего книг в библиотеке: " << bookCount << "\n";
    cout << "Ваш выбор: ";
    choice = getInt();
    return choice;
}

void inputBook() {
    if(bookCount < 100) {
        cout << "\n--- Ввод новой книги (запись №" << bookCount + 1 << ") ---\n";
        
        cout << "Введите регистрационный номер: ";
        library[bookCount].regNumber = getInt();
        
        cout << "Введите автора: ";
        cin.getline(library[bookCount].author, 50);
        
        cout << "Введите название книги: ";
        cin.getline(library[bookCount].title, 100);
        
        cout << "Введите год издания: ";
        library[bookCount].year = getInt();
        
        cout << "Введите издательство: ";
        cin.getline(library[bookCount].publisher, 50);
        
        cout << "Введите количество страниц: ";
        library[bookCount].pages = getInt();
        
        bookCount++;
        cout << "\nКнига успешно добавлена!\n";
    } else {
        cout << "\nБиблиотека заполнена! Максимум 100 книг.\n";
    }
}

void sortBooks() {
    if(bookCount == 0) {
        cout << "\nНет книг для сортировки!\n";
        return;
    }
    
    for(int i = 0; i < bookCount - 1; i++) {
        for(int j = 0; j < bookCount - i - 1; j++) {
            if(strcmp(library[j].author, library[j + 1].author) > 0) {
                Book tmp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = tmp;
            }
        }
    }
    
    cout << "\nМассив отсортирован по автору!\n";
}

void searchBook() {
    if(bookCount == 0) {
        cout << "\nБиблиотека пуста!\n";
        return;
    }
    
    int searchType;
    cout << "\n--- Поиск книги ---\n";
    cout << "1. По автору\n";
    cout << "2. По названию\n";
    cout << "3. По регистрационному номеру\n";
    cout << "Выберите тип поиска: ";
    searchType = getInt();
    
    bool found = false;
    
    if(searchType == 1) {
        char searchAuthor[50];
        cout << "Введите автора: ";
        cin.getline(searchAuthor, 50);
        
        cout << "\n--- Результаты поиска ---\n";
        for(int i = 0; i < bookCount; i++) {
            if(strstr(library[i].author, searchAuthor) != NULL) {
                cout << "\nКнига №" << i + 1 << ":\n";
                cout << "Рег. номер: " << library[i].regNumber << endl;
                cout << "Автор: " << library[i].author << endl;
                cout << "Название: " << library[i].title << endl;
                cout << "Год издания: " << library[i].year << endl;
                cout << "Издательство: " << library[i].publisher << endl;
                cout << "Страниц: " << library[i].pages << endl;
                cout << "------------------------\n";
                found = true;
            }
        }
    } else if(searchType == 2) {
        char searchTitle[100];
        cout << "Введите название: ";
        cin.getline(searchTitle, 100);
        
        cout << "\n--- Результаты поиска ---\n";
        for(int i = 0; i < bookCount; i++) {
            if(strstr(library[i].title, searchTitle) != NULL) {
                cout << "\nКнига №" << i + 1 << ":\n";
                cout << "Рег. номер: " << library[i].regNumber << endl;
                cout << "Автор: " << library[i].author << endl;
                cout << "Название: " << library[i].title << endl;
                cout << "Год издания: " << library[i].year << endl;
                cout << "Издательство: " << library[i].publisher << endl;
                cout << "Страниц: " << library[i].pages << endl;
                cout << "------------------------\n";
                found = true;
            }
        }
    } else if(searchType == 3) {
        int searchRegNum;
        cout << "Введите регистрационный номер: ";
        searchRegNum = getInt();
        
        cout << "\n--- Результаты поиска ---\n";
        for(int i = 0; i < bookCount; i++) {
            if(library[i].regNumber == searchRegNum) {
                cout << "\nКнига №" << i + 1 << ":\n";
                cout << "Рег. номер: " << library[i].regNumber << endl;
                cout << "Автор: " << library[i].author << endl;
                cout << "Название: " << library[i].title << endl;
                cout << "Год издания: " << library[i].year << endl;
                cout << "Издательство: " << library[i].publisher << endl;
                cout << "Страниц: " << library[i].pages << endl;
                cout << "------------------------\n";
                found = true;
                break;
            }
        }
    }
    
    if(!found) {
        cout << "\nКниги не найдены!\n";
    }
}

void editBook() {
    if(bookCount == 0) {
        cout << "\nБиблиотека пуста!\n";
        return;
    }
    
    int bookNum;
    cout << "\nВведите номер книги для редактирования (1-" << bookCount << "): ";
    bookNum = getInt();
    
    if(bookNum < 1 || bookNum > bookCount) {
        cout << "\nНеверный номер книги!\n";
        return;
    }
    
    int index = bookNum - 1;
    int choice;
    
    do {
        cout << "\n--- Редактирование книги №" << bookNum << " ---\n";
        cout << "1. Изменить регистрационный номер\n";
        cout << "2. Изменить автора\n";
        cout << "3. Изменить название\n";
        cout << "4. Изменить год издания\n";
        cout << "5. Изменить издательство\n";
        cout << "6. Изменить количество страниц\n";
        cout << "7. Вернуться в главное меню\n";
        cout << "Выберите поле для изменения: ";
        choice = getInt();
        
        switch(choice) {
            case 1:
                cout << "Новый регистрационный номер: ";
                library[index].regNumber = getInt();
                cout << "Изменено!\n";
                break;
            case 2:
                cout << "Новый автор: ";
                cin.getline(library[index].author, 50);
                cout << "Изменено!\n";
                break;
            case 3:
                cout << "Новое название: ";
                cin.getline(library[index].title, 100);
                cout << "Изменено!\n";
                break;
            case 4:
                cout << "Новый год издания: ";
                library[index].year = getInt();
                cout << "Изменено!\n";
                break;
            case 5:
                cout << "Новое издательство: ";
                cin.getline(library[index].publisher, 50);
                cout << "Изменено!\n";
                break;
            case 6:
                cout << "Новое количество страниц: ";
                library[index].pages = getInt();
                cout << "Изменено!\n";
                break;
            case 7:
                return;
            default:
                cout << "Неверный выбор!\n";
        }
    } while(choice != 7);
}

void deleteBook() {
    if(bookCount == 0) {
        cout << "\nБиблиотека пуста!\n";
        return;
    }
    
    int bookNum;
    cout << "\nВведите номер книги для удаления (1-" << bookCount << "): ";
    cout << "\nДля удаления всех книг введите 0: ";
    bookNum = getInt();
    
    if(bookNum == 0) {
        for(int i = 0; i < 100; i++) {
            library[i] = temp;
        }
        bookCount = 0;
        cout << "\nВсе книги удалены!\n";
    } else if(bookNum >= 1 && bookNum <= bookCount) {
        for(int i = bookNum - 1; i < bookCount - 1; i++) {
            library[i] = library[i + 1];
        }
        bookCount--;
        cout << "\nКнига удалена!\n";
    } else {
        cout << "\nНеверный номер книги!\n";
    }
}

void displayBooks() {
    if (bookCount == 0) {
        cout << "\nБиблиотека пуста!\n";
        return;
    }

    cout << "\n========== СПИСОК КНИГ ==========\n";

    const int w_id = 5;
    const int w_reg = 12;
    const int w_author = 20;
    const int w_title = 30;
    const int w_year = 6;
    const int w_pub = 26;
    const int w_pages = 8;

    cout
        << pad("#", w_id) << " "
        << pad("Рег. номер", w_reg) << " "
        << pad("Автор", w_author) << " "
        << pad("Название", w_title) << " "
        << pad("Год", w_year) << " "
        << pad("Издательство", w_pub) << " "
        << pad("Стр.", w_pages) << " "
        << "\n";

    cout
        << string(w_id, '-') << " "
        << string(w_reg, '-') << " "
        << string(w_author, '-') << " "
        << string(w_title, '-') << " "
        << string(w_year, '-') << " "
        << string(w_pub, '-') << " "
        << string(w_pages, '-') << " "
        << "\n";

    for (int i = 0; i < bookCount; i++) {
        cout
            << pad(to_string(i + 1), w_id) << " "
            << pad(to_string(library[i].regNumber), w_reg) << " "
            << pad(truncate(library[i].author, w_author), w_author) << " "
            << pad(truncate(library[i].title, w_title), w_title) << " "
            << pad(to_string(library[i].year), w_year) << " "
            << pad(truncate(library[i].publisher, w_pub), w_pub) << " "
            << pad(to_string(library[i].pages), w_pages) << " "
            << "\n";
    }

    cout << "\nВсего книг: " << bookCount << endl;
}

int displayWidth(string s) {
    int w = 0;
    bool skip;
    for (unsigned char c : s) {

        if(skip){
            skip = false;
            continue;
        }

        if (c > 128){
            skip = true;
        }

        w+= 1;
    }
    return w;
}

string truncate(const string &s, int width){
    int w = displayWidth(s);
    if (w <= width)
        return s;

    return s.substr(0, width - 3) + "...";
}

string pad(string s, int width) {
    int w = displayWidth(s);
    if (w > width) return s;

    return s + string(width - w, ' ');
}

void loadBooks() {
    const int n = 15;
    
    const char* authors[] = {
        "Толстой Л.Н.", "Достоевский Ф.М.", "Пушкин А.С.", 
        "Чехов А.П.", "Гоголь Н.В.", "Тургенев И.С.",
        "Булгаков М.А.", "Набоков В.В.", "Солженицын А.И.",
        "Пастернак Б.Л.", "Шолохов М.А.", "Есенин С.А.",
        "Маяковский В.В.", "Ахматова А.А.", "Цветаева М.И."
    };
    
    const char* titles[] = {
        "Война и мир", "Преступление и наказание", "Евгений Онегин",
        "Вишневый сад", "Мертвые души", "Отцы и дети",
        "Мастер и Маргарита", "Лолита", "Архипелаг ГУЛАГ",
        "Доктор Живаго", "Тихий Дон", "Анна Снегина",
        "Облако в штанах", "Реквием", "Поэма конца",
        "Идиот", "Капитанская дочка", "Три сестры",
        "Ревизор", "Рудин", "Белая гвардия"
    };
    
    const char* publishers[] = {
        "Просвещение", "АСТ", "Эксмо", "Питер", "Азбука",
        "РИПОЛ классик", "Махаон", "Детская литература",
        "Молодая гвардия", "Художественная литература"
    };
    
    srand(time(0));
    
    int booksToAdd = (bookCount + n <= 100) ? n : (100 - bookCount);
    
    for(int i = 0; i < booksToAdd; i++) {
        library[bookCount].regNumber = 1000 + rand() % 9000;
        
        strcpy(library[bookCount].author, authors[rand() % 15]);
        strcpy(library[bookCount].title, titles[rand() % 21]);
        
        library[bookCount].year = 1950 + rand() % 75;
        
        strcpy(library[bookCount].publisher, publishers[rand() % 10]);
        
        library[bookCount].pages = 100 + rand() % 900;
        
        bookCount++;
    }
    
    cout << "\nЗагружено " << booksToAdd << " книг!\n";
}

void saveFile(){
    if (bookCount == 0) {
        cout << "\nСписок книг пуст" << endl;
        return;
    }

    cout << "\n=== Сохранение в файл ===" << endl;
    string filename = "booksdb.txt";

    ofstream file(filename);
    if (!file) {
        cout << "  Ошибка создания файла!" << endl;
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        file << library[i].regNumber << endl;
        file << library[i].author << endl;
        file << library[i].title << endl;
        file << library[i].year << endl;
        file << library[i].publisher << endl;
        file << library[i].pages << endl;
    }

    file.close();
    cout << "\n  Сохранено " << bookCount << " книг в файл: " << filename << endl;
}

void loadFile(){
    ifstream file("booksdb.txt");

    if (!file.is_open()) {
        cout << " Файл не найден!" << endl;
        return;
    }

    int total = 0;
    while (!file.eof()) {
        file >> library[total].regNumber;
        file.ignore();
        file.getline(library[total].author, 50);
        file.getline(library[total].title, 100);   
        file >> library[total].year;
        file.ignore();
        file.getline(library[total].publisher, 50);   
        file >> library[total].pages;

        if(library[total].pages != 0)  
            total++; 
    }

    bookCount = total;

    cout << "Загружено " << total << " книг\n";
    file.close();
}