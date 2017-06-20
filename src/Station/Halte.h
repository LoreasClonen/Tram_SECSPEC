/**
* @file Halte.h
*
* @brief Header file for the Halte Class
*
* @class Halte
*
* @brief This Class contains all the functionalities for the Halte objects which is the daughterclass
         of the Station class.
*
* @authors Loreas Clonen & Luuk van Sloun
*/

#ifndef TRAM_NETWERK_HALTE_H
#define TRAM_NETWERK_HALTE_H


#include "Station.h"

class Halte : public::Station {
public:

    /**
     * @fn string typeString()
     * @brief The class' name is returned.
     * @return a string with the class' name.
     */
    string typeString();

    /**
     * @fn bool isMetrostation()
     * @brief returns wether or not the class is a metrostation
     * @return bool false
     */
    bool isMetrostation();
};


#endif //TRAM_NETWERK_HALTE_H
