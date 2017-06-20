/**
* @file Metrostation.h
*
* @brief Header file for the Metrostation Class
*
* @class Metrostation
*
* @brief This Class contains all the functionalities for the Metrostation objects, which is a derived class
         of the Station class.
*
* @authors Loreas Clonen & Luuk van Sloun
*/
#ifndef TRAM_NETWERK_METROSTATION_H
#define TRAM_NETWERK_METROSTATION_H


#include "Station.h"

class Metrostation : public::Station {
public:
    /**
     * @fn string typeString()
     * @brief The class' name is returned.
     * @pre The Station Object has been properly initialized
     * @return string
     */
    string typeString();

    /**
     * @fn bool isMetrostation()
     * @brief returns wether or not the class is a metrostation
     * @pre The Station Object has been properly initialized
     * @return boolean
     */
    bool isMetrostation();
};


#endif //TRAM_NETWERK_METROSTATION_H
