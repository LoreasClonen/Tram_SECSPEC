/**
* @file Halte.h
*
* @brief Header file for the Halte Class
*
* @class Halte
*
* @brief This Class contains all the functionalities for the Halte objects, which is a derived class
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
     * @pre The Halte Object has been properly initialized
     * @return string
     */
    string typeString();

    /**
     * @fn bool isMetrostation()
     * @brief returns wether or not the class is a metrostation
     * @pre The Halte Object has been properly initialized
     * @return boolean
     */
    bool isMetrostation();
};


#endif //TRAM_NETWERK_HALTE_H
