#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <set>

int main(){
    srand(time(0));
    std::string Name[10] = {"Алексей", "Дмитрий", "Иван", "Сергей", "Андрей", "Максим", "Егор", "Владимир", "Павел", "Никита"};
    std::string Surname[10] = {"Иванов", "Петров", "Сидоров", "Смирнов", "Кузнецов", "Попов", "Васильев", "Новиков", "Фёдоров", "Морозов"};
    std::string MiddleName[10] = {"Алексеевич", "Дмитриевич", "Иванович", "Сергеевич", "Андреевич", "Максимович", "Егорович", "Владимирович", "Павлович", "Никитич"};
    std::ofstream file1("list1.txt");
    std::ofstream file2("list2.txt");

    for(int i = 0; i < 1000000; i++){
        file1 << rand() % 31 + 1 << " " << rand() % 12 + 1 << " " << rand() % 25 + 2000 << "\t" << Surname[rand() % 10] << " " << Name[rand() % 10] << " " << MiddleName[rand() % 10] << std::endl;
    }

    file1.close();
    std::cout << "File1 is done" << std::endl;

    for(int i = 0; i < 10000000; i++){
        file2 << rand() % 31 + 1 << " " << rand() % 12 + 1 << " " << rand() % 126 + 1900 << "\t" << Surname[rand() % 10] << " " << Name[rand() % 10] << " " << MiddleName[rand() % 10] << std::endl;
    }
    
    file2.close();
    std::cout << "File2 is done" << std::endl;

    return 0;
}