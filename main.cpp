#include <iostream>
#include "rc.h"

int main() {
    rc rodneCislo1;
    rc rodneCislo2("0706283380");
    rc rodneCislo3(rodneCislo1);
    string rodneCislo4;

    std::cout << "Rodne cislo 1: " << rodneCislo1 << std::endl;
    std::cout << "Rodne cislo 2: " << rodneCislo2 << std::endl;
    std::cout << "Rodne cislo 3: " << rodneCislo3 << std::endl;
    do {
        std::cout << "Zadejte platne rodne cislo: ";
        std::getline(std::cin, rodneCislo4);
        if (rodneCislo1.set_rodneCislo(rodneCislo4)) {
            std::cout << "Rodne cislo 4: " << rodneCislo1 << std::endl;
        } else {
            std::cout << "Neplatne rodne cislo." << std::endl;
        }
    } while (!rodneCislo1.set_rodneCislo(rodneCislo4));
    return 0;
}
