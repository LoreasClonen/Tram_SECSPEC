//
// Created by uauser on 5/11/17.
//

#ifndef TRAM_NETWERK_ALBATROS_H
#define TRAM_NETWERK_ALBATROS_H

#include "Tram.h"
#include "../Station/Station.h"

class Albatros: Tram {
public:
    string verplaatsTram(string station);
    bool validStation(string type);
    string typeString();
};


#endif //TRAM_NETWERK_ALBATROS_H
