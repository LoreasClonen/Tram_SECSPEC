//
// Created by uauser on 3/2/17.
//

#ifndef XML_EX_STATION_H
#define XML_EX_STATION_H

#include <iostream>
#include <set>
#include <map>
#include "DesignByContract.h"
#include "Spoor.h"

using namespace std;

class Station{
private:
    Station* _initCheck;
    string naam;
    string vorige;
    string volgende;
    string type;
    set<string> passagier;
    map<int, Spoor*> sporen;

public:
    Station();

    string getNaam();

    void setNaam(string naam);

    bool properlyInitialized();

    string getType();

    void setType(string type);

    void addPassagier(string Passagier);

    void removePassagier(string Passagier);

    set<string> getPassagier();

    map<int, Spoor*> getSporen();

    void addSpoor(Spoor* spoor, int spoorNr);
};


#endif //XML_EX_STATION_H
