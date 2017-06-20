/**
 * @file Station.h
 *
 * @brief Header file for the Station Class
 *
 * @class Station
 *
 * @brief This Class contains all the functionalities for the Station objects.
 *
 * @authors Loreas Clonen & Luuk van Sloun
 */
#ifndef XML_EX_STATION_H
#define XML_EX_STATION_H

#include <iostream>
#include <set>
#include <map>
#include "../DesignByContract.h"
#include "../Spoor/Spoor.h"

using namespace std;

class Station{
private:
    Station* _initCheck;
    string naam;
    set<string> passagier;
    map<int, Spoor*> sporen;

public:
    /**
     * @fn Station()
     * @brief Station Default Constructor
     * @post A new Station Object has been created
     */
    Station();

    /**
     * @fn string getNaam()
     * @brief Returns the Station object's name
     * @pre The Station Object has been properly initialized
     * @pre The Station Object has a non-empty member variable naam
     * @return string
     */
    string getNaam();

    /**
     * @fn void setNaam(string naam)
     * @brief Sets a new Station object's name
     * @pre The Station Object has been properly initialized
     * @pre naam is a non-empty string
     * @param naam - string
     * @post The Station Object's name is equal to variable naam
     */
    void setNaam(string naam);

    /**
     * @fn bool properlyInitialized()
     * @brief Returns true if properly initialized, false if not
     * @return boolean
     */
    bool properlyInitialized();

    /**
     * @fn void addPassagier(string Passagier)
     * @brief Adds a Passenger to the Station object's Passenger set
     * @pre The Station Object has been properly initialized
     * @pre Passagier is a non-empty string
     * @param Passagier - string
     * @post A new Passenger has been added to the Station Object's Passenger Set
     */
    void addPassagier(string Passagier);

    /**
     * @fn void removePassagier(string Passagier)
     * @brief Removes a Passenger from the Station object's Passenger set
     * @pre The Station Object has been properly initialized
     * @pre Passagier is a non-empty string
     * @param Passagier - string
     * @post A Passenger has been removed from the Station Object's Passenger Set
     */
    void removePassagier(string Passagier);

    /**
     * @fn set<string> getPassagier()
     * @brief Returns the Station object's Passenger set
     * @pre The Station Object has been properly initialized
     * @pre The Station Object has a non-empty member variable passagier
     * @return passagier - set
     */
    set<string> getPassagier();

    /**
     * @fn map<int, Spoor*> getSporen()
     * @brief Returns the Station object's Tracks map
     * @pre The Station Object has been properly initialized
     * @pre The Station Object has a non-empty member variable sporen
     * @return sporen - map
     */
    map<int, Spoor*> getSporen();

    /**
     * @fn void setSporen(map<int, Spoor*> sporen)
     * @brief Sets a new map of Tracks as the Station Object's Track Map
     * @param sporen
     * @pre The Station Object has been properly initialized
     * @post The Station Object's Track Map is equal to sporen
     */
    void setSporen(map<int, Spoor *> sporen);

    /**
     * @fn void addSpoor(Spoor* spoor, int spoorNr)
     * @brief Adds a new Station Track to the Tracks map
     * @param spoor - Spoor Pointer
     * @param spoorNr - integer
     * @pre The Station Object has been properly initialized
     * @post The Track Object has been added to the Station Object's Track Map
     */
    void addSpoor(Spoor* spoor, int spoorNr);

    /**
     * @fn string typeString()
     * @brief The class' name is returned.
     * @pre The Station Object has been properly initialized
     * @return string
     */
    virtual string typeString();

    /**
     * @fn bool isMetrostation()
     * @brief returns wether or not the class is a metrostation
     * @pre The Station Object has been properly initialized
     * @return boolean
     */
    virtual bool isMetrostation();
};


#endif //XML_EX_STATION_H
