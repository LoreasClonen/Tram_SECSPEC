/**
 * @file Tram.h
 *
 * @brief Header file for the Tram Class
 *
 * @class Tram
 *
 * @brief This Class contains all the functionalities for the Tram objects.
 *
 * @authors Loreas Clonen & Luuk van Sloun
 */
#ifndef XML_EX_TRAM_H
#define XML_EX_TRAM_H

#include <iostream>
#include <set>
#include "DesignByContract.h"
#include "Passagier.h"

using namespace std;


class Tram {
private:
    int lijnNr;
    int zitplaatsen;
    int snelheid;
    string beginStation;
    string huidigStation;
    Tram* _initCheck;
    string type;
    int voertuigNr;
    set<string> passagiers;

public:
    /**
     * @fn Tram()
     * @brief Tram Default Constructor
     */
    Tram();

    /**
    * @fn int getLijnNr()
    * @brief Returns the Tram object's Line Number
    * @return integer
    */
    int getLijnNr();

    /**
    * @fn int getZitplaatsen()
    * @brief Returns the Tram object's Amount of Seats
    * @return integer
    */
    int getZitplaatsen();

    /**
    * @fn int getSnelheid()
    * @brief Returns the Tram object's Speed
    * @return integer
    */
    int getSnelheid();

    /**
    * @fn string getBeginStation()
    * @brief Returns the Tram object's Starting Station
    * @return string
    */
    string getBeginStation();

    /**
    * @fn int setLijnNr(int lijnNr)
    * @brief Sets a new Tram object's Line Number
    * @param lijnNr
    */
    void setLijnNr(int lijnNr);

    /**
    * @fn int setZitplaatsen(int zitplaatsen)
    * @brief Sets a new Tram object's Amount of Seats
    * @param zitplaatsen
    */
    void setZitplaatsen(int zitplaatsen);

    /**
    * @fn int setSnelheid(int snelheid)
    * @brief Sets a new Tram object's Speed
    * @param snelheid
    */
    void setSnelheid(int snelheid);

    /**
    * @fn string setBeginStation(string beginStation)
    * @brief Sets a new Passenger object's Starting Station
    * @param beginStation
    */
    void setBeginStation(string beginStation);

    /**
    * @fn string getHuidigStation()
    * @brief Returns the Passenger object's Current Station
    * @return string
    */
    string getHuidigStation();

    /**
    * @fn string setHuidigStation(string huidigStation)
    * @brief Sets a new Passenger object's Starting Station
    * @param huidigStation
    */
    void setHuidigStation(string huidigStaton);

    /**
     * @fn bool properlyInitialized()
     * @brief Returns true if properly initialized, false if not
     * @return boolean
     */
    bool properlyInitialized();


    /**
    * @fn int getVoertuigNr()
    * @brief Returns the Tram object's Vehicle Number
    * @return integer
    */
    int getVoertuigNr();


    void setVoertuigNr(int voertuigNr);

    bool plaatsenTeKort(int aantal);

    /**
     * @fn void addPassagier(string Passagier, int Aantal, string Station)
     * @brief Adds a Passenger to the Station object's Passenger set
     * @param Passagier - string
     * @param Aantal - integer
     * @param Station - string
     * @return string
     */
    string addPassagiers(string Passagier, int Aantal, string Station);

    /**
     * @fn void removePassagier(string Passagier, int Aantal, string Station)
     * @brief Removes a Passenger from the Station object's Passenger set
     * @param Passagier - string
     * @param Aantal - integer
     * @param Station - string
     * @return string
     */
    string removePassagiers(string, int, string);

    /**
     * @fn set<string> getPassagiers()
     * @brief Returns the Tram object's Passenger set
     * @return passagiers - set
     */
    set<string> getPassagiers();


    string getPlaats();
};


#endif //XML_EX_TRAM_H
