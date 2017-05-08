/**
 * \class Station
 *
 * This Class contains all the functionalities
 * for the Station objects.
 *
 * \authors Loreas Clonen & Luuk van Sloun
 */
#ifndef XML_EX_STATION_H
#define XML_EX_STATION_H

#include <iostream>
#include <set>
#include <map>
#include "DesignByContract.h"
#include "Spoor.h"

using namespace std;

class Station{
/// \private
private:
    /**
     * \brief Station pointer to the object itself
     * \param Station pointer
     */
    Station* _initCheck;
    /**
     * \brief Station name
     * \param naam - string
     */
    string naam;
    /**
     * \brief Station type
     * \param type - string
     */
    string type;
    /**
     * \brief Passengers in Station
     * \param passagier = set of strings
     */
    set<string> passagier;
    /**
     * \brief Station Tracks
     * \param sporen - map
     * \param spoorNr - map key - integer
     * \param Spoor - map second - Track pointer
     */
    map<int, Spoor*> sporen;

/// \public
public:
    /**
     * \brief Station Default Constructor
     * \fn Station()
     */
    Station();

    /**
     * \fn string getNaam()
     * \brief Returns the Station object's name
     * \return string
     */
    string getNaam();

    /**
     * \fn void setNaam(string naam)
     * \brief Sets a new Station object's name
     * \param naam - string
     */
    void setNaam(string naam);

    /**
     * \fn bool properlyInitialized()
     * \brief Returns true if properly initialized, false if not
     * \return bool
     */
    bool properlyInitialized();

    /**
     * \fn string getType()
     * \brief Returns the Station object's type
     * \return string
     */
    string getType();

    /**
     * \fn void setType(string type)
     * \brief Sets a new Station object's type
     * \param type - string
     */
    void setType(string type);

    /**
     * \fn void addPassagier(string Passagier)
     * \brief Adds a Passenger to the Station object's Passenger set
     * \param Passagier - string
     */
    void addPassagier(string Passagier);

    /**
     * \fn void removePassagier(string Passagier)
     * \brief Removes a Passenger from the Station object's Passenger set
     * \param Passagier - string
     */
    void removePassagier(string Passagier);

    /**
     * \fn set<string> getPassagier()
     * \brief Returns the Station object's Passenger set
     * \return passagier - set
     */
    set<string> getPassagier();

    /**
     * \fn map<int, Spoor*> getSporen()
     * \brief Returns the Station object's Tracks map
     * \return sporen - map
     */
    map<int, Spoor*> getSporen();

    /**
     * \fn void addSpoor(Spoor* spoor, int spoorNr)
     * \brief Adds a new Station Track to the Tracks map
     * \param spoor - Track Pointer
     * \param spoorNr - integer
     */
    void addSpoor(Spoor* spoor, int spoorNr);
};


#endif //XML_EX_STATION_H
