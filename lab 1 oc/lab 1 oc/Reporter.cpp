#include <iostream>
#include <fstream>
#include <string>

struct employee {
    int num;
    char name[10];
    double hours;
};

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "not enough data\n";
        return 1;
    }

    std::string bin_filename = argv[1];
    std::string report_filename = argv[2];
    double hourly_pay = std::stod(argv[3]);

    std::ifstream in(bin_filename, std::ios::binary);
    if (!in) {
        std::cerr << "file cannot be oppened.\n";
        return 1;
    }

    std::ofstream out(report_filename);

    out << "report made by \"" << bin_filename << " data\n";
    out << "ID \t name \t hours \t paycheck\n";

    employee emp;
    while (in.read(reinterpret_cast<char*>(&emp), sizeof(employee))) {
        double salary = emp.hours * hourly_pay;
        out << emp.num << "\t" << emp.name << "\t" << emp.hours << "\t" << salary << "\n";
    }

    in.close();
    out << "\nReporter closed\n";
    out.close();
    return 0;
}