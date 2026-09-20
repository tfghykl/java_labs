#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

struct employee {
    int num;
    char name[10];
    double hours;
};

int main() {

    std::string bin_file;
    int records;

    std::cout << "Input .bin name: ";
    std::cin >> bin_file;
    std::cout << "input amount of records: ";
    std::cin >> records;

    std::string creator_cmd = "Creator.exe " + bin_file + " " + std::to_string(records);
    std::cout << "\nCreator started up\n";
    
    STARTUPINFOA si1;
    PROCESS_INFORMATION pi1;
    ZeroMemory(&si1, sizeof(si1));
    si1.cb = sizeof(si1);
    ZeroMemory(&pi1, sizeof(pi1));

    char* cmd1 = new char[creator_cmd.length() + 1];
    strcpy_s(cmd1, creator_cmd.length() + 1, creator_cmd.c_str());

    CreateProcessA(NULL, cmd1, NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1);
    WaitForSingleObject(pi1.hProcess, INFINITE);
    CloseHandle(pi1.hProcess);
    CloseHandle(pi1.hThread);
    delete[] cmd1;


    std::ifstream in(bin_file, std::ios::binary);
    if (in) {
        employee emp;
        std::cout << "bin:\n";
        while (in.read((char*)&emp, sizeof(employee))) {
            std::cout << "ID: " << emp.num
                << " | Name: " << emp.name
                << " | Hours: " << emp.hours << "\n";
        }
        in.close();
    }

    std::string report_file;
    double hourly_pay;
    std::cout << "\nReport file name: ";
    std::cin >> report_file;
    std::cout << "hourly pay: ";
    std::cin >> hourly_pay;

    std::string reporter_cmd = "Reporter.exe " + bin_file + " " + report_file + " " + std::to_string(hourly_pay);
    std::cout << "\nReporter started up\n";

    STARTUPINFOA si2;
    PROCESS_INFORMATION pi2;
    ZeroMemory(&si2, sizeof(si2));
    si2.cb = sizeof(si2);
    ZeroMemory(&pi2, sizeof(pi2));

    char* cmd2 = new char[reporter_cmd.length() + 1];
    strcpy_s(cmd2, reporter_cmd.length() + 1, reporter_cmd.c_str());

    CreateProcessA(NULL, cmd2, NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2);
    WaitForSingleObject(pi2.hProcess, INFINITE);
    CloseHandle(pi2.hProcess);
    CloseHandle(pi2.hThread);
    delete[] cmd2;

    std::ifstream report_in(report_file);
    if (report_in) {
        std::cout << "\nreport:\n";
        std::string line;
        while (std::getline(report_in, line)) {
            std::cout << line << "\n";
        }
        report_in.close();
    }

    return 0;
}