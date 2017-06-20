/**
 * @file Passagier.h
 *
 * @brief Header file for the Passagier Class
 *
 * @class Passagier
 *
 * @brief This Class contains all the functionalities for the Passagier objects.
 *
 * @authors Loreas Clonen & Luuk van Sloun
 */
#ifndef TRAM_NETWERK_PASSAGIER_H
#define TRAM_NETWERK_PASSAGIER_H

#include <iostream>
#include "../DesignByContract.h"
#include "../Tram/Tram.h"

using namespace std;

class Passagier {
private:
    Passagier* _initCheck;
    string naam;
    string beginStation;
    string eindStation;
    int hoeveelheid;

public:
    /**
     * @fn Passagier();
     * @brief Passenger Default Constructor
     * @post A new Passenger Object has been created
     */
    Passagier();

    /**
     * @fn bool properlyInitialized()
     * @brief Returns true if properly initialized, false if not
     * @return boolean
     */
    bool properlyInitialized();

    /**
    * @fn string getNaam()
    * @brief Returns the Station Object's name
    * @pre The Passenger Object has been properly initialized
    * @pre The Passenger Object has a non-empty member variable naam
    * @return string
    */
    string getNaam();

    /**
     * @fn void setNaam(string naam)
     * @brief Sets a new Passenger Object's name
     * @param naam - string
     * @pre The Passenger Object has been properly initialized
     * @pre naam is a non-empty string
     * @post The Passenger Object's Name is equal to variable naam
     */
    void setNaam(string naam);

    /**
    * @fn string getBeginStation()
    * @brief Returns the Passenger Object's Starting Station
    * @pre The Passenger Object has been properly initialized
    * @pre The Passenger Object has a non-empty member variable beginStation
    * @return string
    */
    string getBeginStation();

    /**
     * @fn void setBeginStation(string beginStation)
     * @brief Sets a new Passenger Object's Starting Station
     * @param beginStation - string
     * @pre The Passenger Object has been properly initialized
     * @pre beginStation is a non-empty string
     * @post The Passenger Object's Starting Station is equal to variable beginStation
     */
    void setBeginStation(string beginStation);

    /**
    * @fn string getEindStation()
    * @brief Returns the Passenger Object's End Station
    * @pre The Passenger Object has been properly initialized
    * @pre The Passenger Object has a non-empty member variable eindStation
    * @return string
    */
    string getEindStation();

    /**
     * @fn void setEindStation(string eindStation)
     * @brief Sets a new Passenger Object's End Station
     * @param eindStation - string
     * @pre The Passenger Object has been properly initialized
     * @pre eindStation is a non-empty string
     * @post The Passenger Object's End Station is equal to variable eindStation
     */
    void setEindStation(string eindStation);

    /**
    * @fn string getHoeveelheid()
    * @brief Returns the Passenger object's amount
    * @pre The Passenger Object has been properly initialized
    * @pre The Passenger Object has a non-empty member variable hoeveelheid
    * @return integer
    */
    int getHoeveelheid();

    /**
     * @fn void setHoeveelheid(string hoeveelheid)
     * @brief Sets a new Passenger object's amount
     * @param hoeveelheid - integer
     * @pre The Passenger Object has been properly initialized
     * @pre hoeveelheid is a positive integer
     * @post The Passenger Object's Amount is equal to variable hoeveelheid
     */
    void setHoeveelheid(int hoeveelheid);


};


#endif //TRAM_NETWERK_PASSAGIER_H
