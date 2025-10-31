#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <sstream>

struct date{
    int day;
    int month;
    int year;
};

struct FCs{
    std::string name;
    std::string surName;
    std::string midleName;
};

struct El{
    date key1;
    FCs key2;
    int index;
};

bool keyIsBigger(El m, El key){
    if(m.key1.year != key.key1.year) return m.key1.year > key.key1.year;
    if(m.key1.month != key.key1.month) return m.key1.month > key.key1.month;
    if(m.key1.day != key.key1.day) return m.key1.day > key.key1.day;
    
    if(m.key2.surName != key.key2.surName) return m.key2.surName < key.key2.surName;
    if(m.key2.name != key.key2.name) return m.key2.name < key.key2.name;
    return m.key2.midleName < key.key2.midleName;
}


int binSearch(El list[], int right, int key){
    int l = -1;
    int r = right;
    int m;
    while(l < r - 1){
        m = (l + r) / 2;
        if(keyIsBigger(list[m], list[key])){
            l = m;
        } else{
            r = m;
        }
    }
    return r;
}

void binInsertionSort(El list[], int size){
    for(int i = 1; i < size; i++){
        El key = list[i];
        int pos = binSearch(list, i, i);  
        
        for(int j = i - 1; j >= pos; j--){
            list[j + 1] = list[j];
        }
        
        list[pos] = key;
    }
}

int main(){
    // Обработка list10
    {
        El* arr = new El[1000000]; 
        std::ifstream list10("list10.txt");
        if(!list10.is_open()) {
            std::cerr << "Error opening list10.txt" << std::endl;
            return 1;
        }

        int i = 0;
        std::string line;
        
        while(std::getline(list10, line) && i < 1000000){
            std::istringstream iss(line);
            iss >> arr[i].key1.day >> arr[i].key1.month >> arr[i].key1.year;
            iss >> arr[i].key2.surName >> arr[i].key2.name >> arr[i].key2.midleName;
            arr[i].index = i + 1;  // Индекс от 1
            i++;
        }
        
        list10.close();
        int size = i;

        auto start = std::chrono::steady_clock::now();
        binInsertionSort(arr, size);
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        std::cout << "list10 - Время затраченное на сортировку: " << elapsed.count() << " сек" << std::endl;

        std::ofstream output("outputlist10.txt");
        for(int i = 0; i < size; i++){  
            output << arr[i].key1.day << " " << arr[i].key1.month << " " << arr[i].key1.year << "\t" 
                   << arr[i].key2.surName << " " << arr[i].key2.name << " " << arr[i].key2.midleName 
                   << "\t" << arr[i].index << std::endl;  
        }
        output.close();
        delete[] arr;
    }

    // Обработка list10k
    {
        El* arr = new El[1000000]; 
        std::ifstream list10k("list10k.txt");
        if(!list10k.is_open()) {
            std::cerr << "Error opening list10k.txt" << std::endl;
            return 1;
        }

        int i = 0;
        std::string line;
        
        while(std::getline(list10k, line) && i < 1000000){
            std::istringstream iss(line);
            iss >> arr[i].key1.day >> arr[i].key1.month >> arr[i].key1.year;
            iss >> arr[i].key2.surName >> arr[i].key2.name >> arr[i].key2.midleName;
            arr[i].index = i + 1;  // Индекс от 1
            i++;
        }
        
        list10k.close();
        int size = i;

        auto start = std::chrono::steady_clock::now();
        binInsertionSort(arr, size);
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        std::cout << "list10k - Время затраченное на сортировку: " << elapsed.count() << " сек" << std::endl;

        std::ofstream output("outputlist10k.txt");
        for(int i = 0; i < size; i++){  
            output << arr[i].key1.day << " " << arr[i].key1.month << " " << arr[i].key1.year << "\t" 
                   << arr[i].key2.surName << " " << arr[i].key2.name << " " << arr[i].key2.midleName 
                   << "\t" << arr[i].index << std::endl;  
        }
        output.close();
        delete[] arr;
    }

    // Обработка list100k
    {
        El* arr = new El[1000000]; 
        std::ifstream list100k("list100k.txt");
        if(!list100k.is_open()) {
            std::cerr << "Error opening list100k.txt" << std::endl;
            return 1;
        }

        int i = 0;
        std::string line;
        
        while(std::getline(list100k, line) && i < 1000000){
            std::istringstream iss(line);
            iss >> arr[i].key1.day >> arr[i].key1.month >> arr[i].key1.year;
            iss >> arr[i].key2.surName >> arr[i].key2.name >> arr[i].key2.midleName;
            arr[i].index = i + 1;  // Индекс от 1
            i++;
        }
        
        list100k.close();
        int size = i;

        auto start = std::chrono::steady_clock::now();
        binInsertionSort(arr, size);
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        std::cout << "list100k - Время затраченное на сортировку: " << elapsed.count() << " сек" << std::endl;

        std::ofstream output("outputlist100k.txt");
        for(int i = 0; i < size; i++){  
            output << arr[i].key1.day << " " << arr[i].key1.month << " " << arr[i].key1.year << "\t" 
                   << arr[i].key2.surName << " " << arr[i].key2.name << " " << arr[i].key2.midleName 
                   << "\t" << arr[i].index << std::endl;  
        }
        output.close();
        delete[] arr;
    }
    
    return 0;
}