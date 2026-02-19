//
// Created by student on 29.01.2026.
//

#ifndef RODNE_CISLO_RC_H
#define RODNE_CISLO_RC_H

#include <string>
#include <ctime>
#include <ostream>
using std::string;
const string default_rc = "5401010483";

class rc {
public:
    rc();

    rc(string);

    rc(const rc &);

    ~rc();

    string get_rodneCislo() const;

    bool set_rodneCislo(string);

    int vek() const;

    int rok() const;

    int mesic() const;

    int den() const;

    string pohlavi() const;

private:
    string rodneCislo;

    static bool jeValidni(string);
};

std::ostream &operator<<(std::ostream &os, const rc &c);

#endif //RODNE_CISLO_RC_H
