#include <iostream>
#include "rc.h"

int main() {

    rc rodneCislo1;
    rc rodneCislo2("0706283380");
    rc rodneCislo3(rodneCislo1);

    std::cout << "Rodne cislo 1: " << rodneCislo1 << std::endl;
    std::cout << "Rodne cislo 2: " << rodneCislo2 << std::endl;
    std::cout << "Rodne cislo 3: " << rodneCislo3 << std::endl;
    return 0;
}