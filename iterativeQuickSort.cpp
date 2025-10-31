#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <sstream>
#include <stack>

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

struct stackEl{
    int left; 
    int right;
};

bool keyIsBigger(El m, El key){
    if(m.key1.year != key.key1.year) return m.key1.year < key.key1.year;
    if(m.key1.month != key.key1.month) return m.key1.month < key.key1.month;
    if(m.key1.day != key.key1.day) return m.key1.day < key.key1.day;
    
    if(m.key2.surName != key.key2.surName) return m.key2.surName > key.key2.surName;
    if(m.key2.name != key.key2.name) return m.key2.name > key.key2.name;
    return m.key2.midleName > key.key2.midleName;
}

void swap(El arr[], int i, int j){
    El temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int median(El arr[], int left, int right){
    int mid = (left + right) / 2;
    
    if (keyIsBigger(arr[left], arr[mid])){
        swap(arr, left, right);
    }
    if (keyIsBigger(arr[left], arr[right])){
        swap(arr, left, right);
    }
    if (keyIsBigger(arr[mid], arr[right])){
        swap(arr, mid, right);
    }

    return mid;
}

int patritionHoare(El arr[], int left, int right){
    int pivotIndex = median(arr, left, right);
    El pivot = arr[pivotIndex];
    
    int i = left;
    int j = right;

    while(true){
        while(keyIsBigger(pivot, arr[i])){
            i++;
        }

        while(keyIsBigger(arr[j], pivot)){
            j--;
        }

        if(i >= j) return j;
        
        swap(arr, i, j);
        i++;
        j--;
    }
}

void iterativeQuickSort(El arr[], int size){
    if(size <= 1){
        return;
    }

    std::stack<stackEl> stak;
    stak.push({0, size - 1});

    while(!stak.empty()){
        stackEl leftRight = stak.top();
        stak.pop();
        if(leftRight.left >= leftRight.right){
            continue;
        }

        int p = patritionHoare(arr, leftRight.left, leftRight.right);

        int left_size = p - leftRight.left + 1;
        int right_size = p + leftRight.right - 1;

        if(left_size > right_size){
            if(leftRight.left < p){
                stak.push({leftRight.left, p});
            }
            if(p+1 < leftRight.right){
                stak.push({p+1, leftRight.right});
            }
        } else{
            if(p+1 < leftRight.right){
                stak.push({p+1, leftRight.right});
            }
            if(leftRight.left < p){
                stak.push({leftRight.left, p});
            }
        }
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
        iterativeQuickSort(arr, size);
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        std::cout << "list10 - Время затраченное на сортировку: " << elapsed.count() << " сек" << std::endl;

        std::ofstream output("outputlist10_.txt");
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
        iterativeQuickSort(arr, size);
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        std::cout << "list10k - Время затраченное на сортировку: " << elapsed.count() << " сек" << std::endl;

        std::ofstream output("outputlist10k_.txt");
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
        iterativeQuickSort(arr, size);
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        std::cout << "list100k - Время затраченное на сортировку: " << elapsed.count() << " сек" << std::endl;

        std::ofstream output("outputlist100k_.txt");
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