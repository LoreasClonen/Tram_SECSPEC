/**
* @file Metrostation.h
*
* @brief Header file for the Metrostation Class
*
* @class Metrostation
*
* @brief This Class contains all the functionalities for the Metrostation objects which is the daughterclass
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
     * @return a string with the class' name.
     */
    string typeString();
    /**
     * @fn bool isMetrostation()
     * @brief returns wether or not the class is a metrostation
     * @return bool true
     */
    bool isMetrostation();
};


#endif //TRAM_NETWERK_METROSTATION_H
