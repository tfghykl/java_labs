#include <iostream>
#include <fstream>
#include <string>

struct employee {
    int num;
    char name[10];  
    double hours;  
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "not enough data\n";
        return 1;
    }

    std::string filename = argv[1];
    int repord_amount = std::stoi(argv[2]);

    std::ofstream out(filename, std::ios::binary);

    for (int i = 0; i < repord_amount; ++i) {
        employee emp;
        std::cout << "\nEmployee " << i + 1 << ":\n";
        std::cout << "ID:\n ";
        std::cin >> emp.num;
        std::cout << "Name:\n ";
        std::cin >> emp.name;
        std::cout << "hours:\n ";
        std::cin >> emp.hours;

        out.write(reinterpret_cast<const char*>(&emp), sizeof(employee));
    }
    out << "\nCreator closed\n";
    out.close();
    return 0;
}