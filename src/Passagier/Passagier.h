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
    * @brief Returns the Station object's name
    * @return string
    */
    string getNaam();

    /**
     * @fn void setNaam(string naam)
     * @brief Sets a new Passenger object's name
     * @param naam - string
     */
    void setNaam(string naam);

    /**
    * @fn string getBeginStation()
    * @brief Returns the Passenger object's Starting Station
    * @return string
    */
    string getBeginStation();

    /**
     * @fn void setBeginStation(string beginStation)
     * @brief Sets a new Passenger object's Starting Station
     * @param beginStation - string
     */
    void setBeginStation(string beginStation);

    /**
    * @fn string getEindStation()
    * @brief Returns the Passenger object's End Station
    * @return string
    */
    string getEindStation();

    /**
     * @fn void setEindStation(string eindStation)
     * @brief Sets a new Passenger object's End Station
     * @param eindStation - string
     */
    void setEindStation(string eindStation);

    /**
    * @fn string getHoeveelheid()
    * @brief Returns the Passenger object's amount
    * @return integer
    */
    int getHoeveelheid();

    /**
     * @fn void setHoeveelheid(string hoeveelheid)
     * @brief Sets a new Passenger object's amount
     * @param hoeveelheid - integer
     */
    void setHoeveelheid(int hoeveelheid);


};


#endif //TRAM_NETWERK_PASSAGIER_H
