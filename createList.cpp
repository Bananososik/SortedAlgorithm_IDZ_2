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


    int n, c;
    std::cout << "Ввведите номер файла: ";
    std::cin >> n;
    std::cout << std::endl << "введите количство строк: ";
    std::cin >> c;

    std::string filename = "list" + std::to_string(n) + ".txt";
    std::ofstream file1(filename);


    for(int i = 0; i < c; i++){
        file1 << rand() % 31 + 1 << " " << rand() % 12 + 1 << " " << rand() % 25 + 2000 << "\t" << Surname[rand() % 10] << " " << Name[rand() % 10] << " " << MiddleName[rand() % 10] << std::endl;
    }

    file1.close();
    std::cout << std::endl <<"list" << n << ".txt is done" << std::endl;


    return 0;
}