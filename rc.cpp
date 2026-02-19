//
// Created by student on 29.01.2026.
//

#include "rc.h"

#include <ctime>
#include <bits/locale_classes.h>

rc::rc() : rodneCislo(default_rc) {
}

rc::rc(string rCislo){
    if (!set_rodneCislo(rCislo)){
        this -> rodneCislo = default_rc;
    }
}

rc::rc(const rc &c) : rodneCislo(c.get_rodneCislo()) {

}

rc::~rc(){

}

int rc::rok() const {
    int r;
    r = stoi(rodneCislo.substr(0, 2));
    if (r >= 54) {
        return 1900 + r;
    } else {
        return 2000 + r;
    }
}

int rc::mesic() const {
    int mesic;
    mesic = stoi(rodneCislo.substr(2, 2));
    if (mesic > 50) {
        return mesic - 50;
    } else {
        return mesic;
    }
}

int rc::den() const {
    return stoi(rodneCislo.substr(4, 2));
}

string rc::pohlavi() const {
    if (stoi(rodneCislo.substr(2, 2)) > 50) {
        return "Zena";
    } else {
        return "Muz";
    }
}

bool rc::jeValidni(string cislo_R) {
    if (cislo_R.length() != 10) {
        return false;
    }
    if (stoi(cislo_R.substr(0, 9)) % 11 == stoi(cislo_R.substr(9, 1))) {
        return true;
    } else if (stoi(cislo_R.substr(0, 9)) % 11 == 10 && stoi(cislo_R.substr(9, 1)) == 0) {
        return true;
    } else {
        return false;
    }
}

std::ostream & operator<<(std::ostream &os, const rc &c) {
    os << c.get_rodneCislo() << " (vek: " << c.vek() << ", pohlavi: " << c.pohlavi() << ")";
    return os;
}

string rc::get_rodneCislo() const {
    return rodneCislo;
}

bool rc::set_rodneCislo(string rodneCislo) {
    if (jeValidni(rodneCislo)){
        this->rodneCislo = rodneCislo;
        //(*this).rodneCislo = rodneCislo;
        return true;
    }
    return false;
}

int rc::vek() const {
    int sysRok;
    int sysMesic;
    int sysDen;
    int v;
    time_t t = time(nullptr);
    tm * now = localtime(&t);
    sysRok = now->tm_year + 1900;
    sysMesic = now->tm_mon + 1;
    sysDen = now->tm_mday;

    v = sysRok - this -> rok();
    if (sysMesic < mesic() || (sysMesic == mesic() && sysDen < den())) {
        v--;
    }
    return v;
}
