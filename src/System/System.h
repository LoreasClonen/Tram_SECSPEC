/**
 * @file System.h
 *
 * @brief Header file for System class
 *
 * @class System
 *
 * @brief This Class contains all the functionalities for the System objects.
 *
 * @authors Loreas Clonen & Luuk van Sloun
 */
#ifndef TRAM_NETWERK_SYSTEM_H
#define TRAM_NETWERK_SYSTEM_H

#include "../Station/Station.h"
#include "../Tram/Tram.h"
#include "../Passagier/Passagier.h"
#include <iostream>
#include <map>
#include <fstream>
#include "../DesignByContract.h"

using namespace std;

class System {
private:
    map<string, Station *> stations;
    map<int, Tram *> trams;
    map<string, Passagier*> passagiers;
    bool properlyParsed;
    System* _initCheck;

    string help_ronde_rijden(int aantal_klaar,int aantal_trams, string output);

    string findNextStation(Station* station, int spoorNr, Tram* tram);

    string ronde_rijden();

    bool Valid_circuit();

    bool isConsistent();

    bool checkTram(Tram* tram, Station* station, Passagier* passagier);

    set<int> overeenkomstigeSporen(Station* huidig, Station* eind);

public:
    /**
     * @brief System Default Constructor
     * @fn System()
     */
    System();
    /**
     * @fn bool properlyInitialized()
     * @brief Returns the system object's properlyInitialized member
     * @return bool
     */
    bool properlyInitialized();
    /**
     * @fn map<string, Station*> getStations()
     * @brief Returns the System object's stations member
     * @return map<string, Tram*>
     */
    map<string, Station*> getStations();

    /**
     * @fn map<string, Tram*> getTrams()
     * @brief Returns the System object's trams member
     * @return map<string, Tram*>
     */
    map<int, Tram*> getTrams();

    /**
     * @fn string Output()
     * @brief Returns a string of the current system lay-out
     * @return string
     */
    string Output();

    /**
     * @fn void addStation(string naam, Station* station)
     * @brief adds a Station* to the stations member
     * @param naam - string
     * @param station - Station*
     */
    void addStation(string naam, Station* station);

    /**
     * @fn void addTram(int lijnNr, Tram* tram)
     * @brief adds a Tram* to the trams member
     * @param lijnNr - int
     * @param tram - Tram*
     */

    void addTram(int lijnNr, Tram* tram);

    /**
     * @fn void properlyparsed()
     * @brief checks wether or not the system is properly parsed
     */
    void properlyparsed();

    /**
     * @fn void setProperlyParsed(bool properlyparsed)
     * @brief Gives a new value to the member properlyparsed
     */

    void setProperlyParsed(bool properlyParsed);

        /**
     * @fn map<string, Passagier*> getPassagiers()
     * @brief Returns the member passagiers
     * @return map<string, Passagier*>
     */
    map<string, Passagier *> getPassagiers();

    /**
     * @fn void addPassagier(string naam, Passagier* passagier)
     * @brief adds a Passagier* to the passagiers member
     * @param naam - string
     * @param passagier - Passagier*
     */
    void addPassagier(string naam, Passagier* passagier);

    /**
     * @fn void autoSimulation()
     * @brief Simulates the system running
     */

    void autoSimulation();
};

#endif //TRAM_NETWERK_SYSTEM_H
