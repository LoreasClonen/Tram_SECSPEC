//
// Created by uauser on 5/4/17.
//

#ifndef TRAM_NETWERK_SPOOR_H
#define TRAM_NETWERK_SPOOR_H

#include <iostream>
#include "DesignByContract.h"

using namespace std;

class Spoor {
private:
    Spoor* _initCheck;
    int spoorNr;
    string volgende;
    string vorige;

public:
    Spoor();

    bool properlyInitialized();

    int getSpoorNr();

    void setSpoorNr(int spoorNr);

    string getVolgende();

    void setVolgende(string volgende);

    string getVorige();

    void setVorige(string vorige);
};


#endif //TRAM_NETWERK_SPOOR_H
