//
// Created by uauser on 6/14/17.
//

#ifndef TRAM_NETWERK_METROSTATION_H
#define TRAM_NETWERK_METROSTATION_H


#include "Station.h"

class Metrostation : public::Station {
public:
    string typeString();
    bool acceptingAlbatros();
};


#endif //TRAM_NETWERK_METROSTATION_H
