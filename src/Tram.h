//
// Created by uauser on 3/2/17.
//

#ifndef XML_EX_TRAM_H
#define XML_EX_TRAM_H

#include <iostream>
#include <set>
#include "DesignByContract.h"
#include "Passagier.h"

using namespace std;


class Tram {
private:
    int lijnNr;
    int zitplaatsen;
    int snelheid;
    string beginStation;
    string huidigStation;
    Tram* _initCheck;
    string type;
    int voertuigNr;
    set<string> passagiers;

public:
    Tram();

    int getLijnNr();

    int getZitplaatsen();

    int getSnelheid();

    string getBeginStation();

    void setLijnNr(int lijnNr);

    void setZitplaatsen(int zitplaatsen);

    void setSnelheid(int snelheid);

    void setBeginStation(string beginStation);

    string getHuidigStation();

    void setHuidigStation(string huidigStaton);

    bool properlyInitialized();

    string getType();

    void setType(string type);

    int getVoertuigNr();

    void setVoertuigNr(int voertuigNr);

    bool plaatsenTeKort(int);

    void addPassagiers(string);

    void removePassagiers(string);

    set<string> getPassagiers();

};


#endif //XML_EX_TRAM_H
