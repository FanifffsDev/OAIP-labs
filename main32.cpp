void saveFile(){
    cout << "\n=== Сохранение в файл ===" << endl;
    string filename = "laptopsdb.txt";

    ofstream file(filename);
    if (!file) {
        cout << "  Ошибка создания файла!" << endl;
        return;
    }

    for (int i = 0; i < laptopCount; i++) {
        file << mas[i].marka << endl;
        file << mas[i].yadra << endl;
        file << mas[i].memory << endl;
        file << mas[i].marterial << endl;
        file << mas[i].color << endl;
    }

    file.close();
    cout << "\nСохранено в файл: " << filename << endl;
}

void loadFile(){
    ifstream file("laptopsdb.txt");

    if (!file.is_open()) {
        cout << " Файл не найден!" << endl;
        return;
    }

    int total = 0;
    while (!file.eof()) {
        file.getline(mas[total].marka, 30);
        file >> mas[total].yadra;
        file >> mas[total].memory;
        file.ignore();
        file.getline(mas[total].material, 20);   
        file.getline(mas[total].color, 15);   

        if(mas[total].pages != 0)  
            total++; 
    }

    laptopCount = total;

    cout << "Загружено";
    file.close();
}