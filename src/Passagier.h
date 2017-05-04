//
// Created by uauser on 4/19/17.
//

#ifndef TRAM_NETWERK_PASSAGIER_H
#define TRAM_NETWERK_PASSAGIER_H

#include <iostream>

using namespace std;

class Passagier {
private:
    string naam;
    string beginStation;
    string eindStation;
    int hoeveelheid;

public:
    Passagier();

    string getNaam();

    void setNaam(string naam);

    string getBeginStation();

    void setBeginStation(string beginStation);

    string getEindStation();

    void setEindStation(string eindStation);

    int getHoeveelheid();

    void setHoeveelheid(int hoeveelheid);
};


#endif //TRAM_NETWERK_PASSAGIER_H
