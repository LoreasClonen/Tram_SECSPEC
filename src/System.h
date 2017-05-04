//
// Created by uauser on 3/16/17.
//

#ifndef TRAM_NETWERK_SYSTEM_H
#define TRAM_NETWERK_SYSTEM_H

#include "Station.h"
#include "Tram.h"
#include "Passagier.h"
#include <iostream>
#include <map>
#include "DesignByContract.h"

using namespace std;

class System {
private:
    map<string, Station *> stations;
    map<int, Tram *> trams;
    map<string, Passagier*> passagiers;
    bool properlyParsed;
    System* _initCheck;

public:
    System();

    bool properlyInitialized();

    map<string, Station*> getStations();

    map<int, Tram*> getTrams();

    string Output();

    string verplaatsTram(Tram* tram);

    void addStation(string naam, Station* station);

    void addTram(int lijnNr, Tram* tram);

    bool Valid_circuit();

    void properlyparsed();

    void ronde_rijden(bool ronde_gedaan);

    void setProperlyParsed(bool properlyParsed);

    map<string, Passagier *> getPassagiers();

    void addPassagier(string naam, Passagier* passagier);

    Station* findNextStation(Station* station, int spoorNr, string type);

    void autoSimulation();
};

#endif //TRAM_NETWERK_SYSTEM_H
