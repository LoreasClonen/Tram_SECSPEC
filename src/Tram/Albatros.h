/**
* @file Albatros.h
*
* @brief Header file for the Albatros Class
*
* @class Albatros
*
* @brief This Class contains all the functionalities for the Albatros objects, which is a derived class
         of the Tram class.
*
* @authors Loreas Clonen & Luuk van Sloun
*/
#ifndef TRAM_NETWERK_ALBATROS_H
#define TRAM_NETWERK_ALBATROS_H

#include "Tram.h"
#include "../Station/Station.h"

class Albatros: public::Tram {
public:
    /**
     * @fn bool isAlbatros()
     * @brief Returns true if the Tram Object is of the Albatros type
     * @pre The Tram Object has been properly initialized
     * @return boolean
     */
    bool isAlbatros();

    /**
     * @fn string typeString()
     * @brief Returns the Tram Object's type
     * @pre The Tram Object has been properly initialized
     * @return string
     */
    string typeString();
};


#endif //TRAM_NETWERK_ALBATROS_H
