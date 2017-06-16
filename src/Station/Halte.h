//
// Created by uauser on 6/14/17.
//

#ifndef TRAM_NETWERK_HALTE_H
#define TRAM_NETWERK_HALTE_H


#include "Station.h"

class Halte : public::Station {
public:
    string typeString();
    bool isMetrostation();
};


#endif //TRAM_NETWERK_HALTE_H
