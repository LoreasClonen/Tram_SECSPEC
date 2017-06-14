//
// Created by uauser on 5/11/17.
//

#ifndef TRAM_NETWERK_ALBATROS_H
#define TRAM_NETWERK_ALBATROS_H

#include "Tram.h"
#include "Station.h"

class Albatros: Tram {
public:
    void verplaatsTram(string station);
    bool validStation(string type);
};


#endif //TRAM_NETWERK_ALBATROS_H
