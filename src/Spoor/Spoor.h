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
    * @return integer
    */
    int getSpoorNr();

    /**
    * @fn int setSpoorNr()
    * @brief Sets a new Spoor object's Track Number
    * @param spoorNr - integer
    */
    void setSpoorNr(int spoorNr);

    /**
    * @fn string getVolgende()
    * @brief Returns the Station object's Next Station
    * @return string
    */
    string getVolgende();

    /**
     * @fn void setVolgende(string volgende)
     * @brief Sets a new Spoor object's Next Station
     * @param volgende - string
     */
    void setVolgende(string volgende);

    /**
    * @fn string getVorige()
    * @brief Returns the Station object's Previous Station
    * @return string
    */
    string getVorige();

    /**
     * @fn void setVorige(string vorige)
     * @brief Sets a new Spoor object's Previous Station
     * @param vorige - string
     */
    void setVorige(string vorige);
};


#endif //TRAM_NETWERK_SPOOR_H
