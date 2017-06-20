/**
 * @file Spoor.h
 *
 * @brief Header file for the Spoor Class
 *
 * @class Spoor
 *
 * @brief This Class contains all the functionalities for the Spoor objects.
 *
 * @authors Loreas Clonen & Luuk van Sloun
 */
#ifndef TRAM_NETWERK_SPOOR_H
#define TRAM_NETWERK_SPOOR_H

#include <iostream>
#include "../DesignByContract.h"

using namespace std;

class Spoor {
private:
    Spoor* _initCheck;
    int spoorNr;
    string volgende;
    string vorige;

public:
    /**
     * @fn Spoor();
     * @brief Spoor Default Constructor
     * @post A new Spoor Object has been created
     */
    Spoor();

    /**
     * @fn bool properlyInitialized()
     * @brief Returns true if properly initialized, false if not
     * @return boolean
     */
    bool properlyInitialized();

    /**
    * @fn int getSpoorNr()
    * @brief Returns the Spoor object's Track Number
    * @pre The Spoor Object has been properly initialized
    * @pre The Spoor Object has a non-empty member variable spoorNr
    * @return integer
    */
    int getSpoorNr();

    /**
    * @fn int setSpoorNr()
    * @brief Sets a new Spoor object's Track Number
    * @param spoorNr - integer
    * @pre The Spoor Object has been properly initialized
    * @pre spoorNr is a positive integer
    * @post The Spoor Object's Track Number is equal to variable spoorNr
    */
    void setSpoorNr(int spoorNr);

    /**
    * @fn string getVolgende()
    * @brief Returns the Station object's Next Station
    * @pre The Spoor Object has been properly initialized
    * @pre The Spoor Object has a non-empty member variable volgende
    * @return string
    */
    string getVolgende();

    /**
     * @fn void setVolgende(string volgende)
     * @brief Sets a new Spoor object's Next Station
     * @param volgende - string
     * @pre The Spoor Object has been properly initialized
     * @pre volgende is a non-empty string
     * @post The Spoor Object's Next Station is equal to variable volgende
     */
    void setVolgende(string volgende);

    /**
    * @fn string getVorige()
    * @brief Returns the Station object's Previous Station
    * @pre The Spoor Object has been properly initialized
    * @pre The Spoor Object has a non-empty member variable vorige
    * @return string
    */
    string getVorige();

    /**
    * @fn void setVorige(string vorige)
    * @brief Sets a new Spoor object's Previous Station
    * @param vorige - string
    * @pre The Spoor Object has been properly initialized
    * @pre vorige is a non-empty string
    * @post The Spoor Object's Next Station is equal to variable vorige
    */
    void setVorige(string vorige);
};


#endif //TRAM_NETWERK_SPOOR_H
