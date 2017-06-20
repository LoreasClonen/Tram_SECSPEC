/**
 * @file Tram.h
 *
 * @brief Header file for the PCC Class
 *
 * @class PCC
 *
 * @brief This Class contains all the functionalities for the PCC objects, which is a derived class of the Tram class
 *
 * @authors Loreas Clonen & Luuk van Sloun
 */

#include "Tram.h"


#include <iostream>

class PCC: public::Tram{
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