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
#include "../DesignByContract.h"
#include "../Passagier/Passagier.h"

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
     * @post A new Tram Object has been created
     */
    Tram();

    /**
    * @fn int getLijnNr()
    * @brief Returns the Tram object's Line Number
    * @pre The Tram Object has been properly initialized
    * @pre The Tram Object has a non-empty member variable lijnNr
    * @return integer
    */
    int getLijnNr();

    /**
    * @fn int getZitplaatsen()
    * @brief Returns the Tram object's Amount of Seats
    * @pre The Tram Object has been properly initialized
    * @pre The Tram Object has a non-empty member variable zitplaatsen
    * @return integer
    */
    int getZitplaatsen();

    /**
    * @fn int getSnelheid()
    * @brief Returns the Tram object's Speed
    * @pre The Tram Object has been properly initialized
    * @pre The Tram Object has a non-empty member variable snelheid
    * @return integer
    */
    int getSnelheid();

    /**
    * @fn string getBeginStation()
    * @brief Returns the Tram object's Starting Station
    * @pre The Tram Object has been properly initialized
    * @pre The Tram Object has a non-empty member variable beginStation
    * @return string
    */
    string getBeginStation();

    /**
   * @fn string getHuidigStation()
   * @brief Returns the Passenger object's Current Station
   * @pre The Tram Object has been properly initialized
   * @pre The Tram Object has a non-empty member variable huidigStation
   * @return string
   */
    string getHuidigStation();

    /**
    * @fn int getVoertuigNr()
    * @brief Returns the Tram object's Vehicle Number
    * @pre The Tram Object has been properly initialized
    * @pre The Tram Object has a non-empty member variable voertuigNr
    * @return integer
    */
    int getVoertuigNr();

    /**
    * @fn int setLijnNr(int lijnNr)
    * @brief Sets a new Tram object's Line Number
    * @param lijnNr - integer
    * @pre The Tram Object has been properly initialized
    * @pre lijnNr is a positive integer
    * @post The Tram Object's Line Number is now equal to variable lijnNr
    */
    void setLijnNr(int lijnNr);

    /**
    * @fn int setZitplaatsen(int zitplaatsen)
    * @brief Sets a new Tram object's Amount of Seats
    * @param zitplaatsen - int
    * @pre The Tram Object has been properly initialized
    * @pre zitplaatsen is a positive integer
    * @post The Tram Object's Amount of Seats is now equal to variable zitplaatsen
    */
    void setZitplaatsen(int zitplaatsen);

    /**
    * @fn int setSnelheid(int snelheid)
    * @brief Sets a new Tram object's Speed
    * @param snelheid - integer
    * @pre The Tram Object has been properly initialized
    * @pre snelheid is a positive integer
    * @post The Tram Object's Speed is now equal to variable snelheid
    */
    void setSnelheid(int snelheid);

    /**
    * @fn string setBeginStation(string beginStation)
    * @brief Sets a new Passenger object's Starting Station
    * @param beginStation - string
    * @pre The Tram Object has been properly initialized
    * @pre beginStation is a non-empty string
    * @post The Tram Object's Starting Station is now equal to variable beginStation
    */
    void setBeginStation(string beginStation);

    /**
    * @fn string setHuidigStation(string huidigStation)
    * @brief Sets a new Passenger object's Starting Station
    * @param huidigStation - string
    * @pre The Tram Object has been properly initialized
    * @pre huidigStation is a non-empty string
    * @post The Tram Object's Current Station is now equal to variable huidigStation
    */
    void setHuidigStation(string huidigStation);

    /**
     * @fn void setVoertuigNr(int voertuigNr)
     * @brief Sets a new Tram Object
     * @param voertuigNr - integer
     * @pre The Tram Object has been properly initialized
     * @pre voertuigNr is a positive integer
     * @post The Tram Object's Vehicle Number is now equal to variable voertuigNr
     */
    void setVoertuigNr(int voertuigNr);

    /**
     * @fn bool properlyInitialized()
     * @brief Returns true if properly initialized, false if not
     * @return boolean
     */
    bool properlyInitialized();

    /**
     * @fn bool plaatsenTeKort(int aantal)
     * @brief Returns true if there's enough seats available on the Tram
     * @param aantal - integer
     * @pre The Tram Object has been properly initialized
     * @pre aantal is a positive integer
     * @return boolean
     */
    bool plaatsenTeKort(int aantal);

    /**
     * @fn void addPassagier(string Passagier, int Aantal, string Station)
     * @brief Adds a Passenger to the Tram object's Passenger set
     * @param Passagier - string
     * @param Aantal - integer
     * @param Station - string
     * @pre The Tram Object has been properly initialized
     * @pre Passagier is a non-empty string
     * @pre Aantal is a positive integer
     * @pre Station is non-empty string
     * @post A new Passenger has been added to the Tram Object's Passenger Set
     * @return string
     */
    string addPassagiers(string Passagier, int Aantal, string Station);

    /**
     * @fn void removePassagier(string Passagier, int Aantal, string Station)
     * @brief Removes a Passenger from the Tram object's Passenger set
     * @param Passagier - string
     * @param Aantal - integer
     * @param Station - string
     * @pre The Tram Object has been properly initialized
     * @pre Passagier is a non-empty string
     * @pre Aantal is a positive integer
     * @pre Station is non-empty string
     * @post A Passenger has been removed from the Tram Object's Passenger Set
     * @return string
     */
    string removePassagiers(string, int, string);

    /**
     * @fn set<string> getPassagiers()
     * @brief Returns the Tram object's Passenger set
     * @pre The Tram Object has been properly initialized
     * @pre The Tram Object has a non-empty member variable passagiers
     * @return passagiers - set
     */
    set<string> getPassagiers();

    /**
     * @fn string typeString()
     * @brief Returns the Tram Object's type
     * @pre The Tram Object has been properly initialized
     * @return string
     */
    virtual string typeString();

    /**
     * @fn string verplaatsTram(string station)
     * @brief Sets the Tram Object's Current Station to the next possible one
     * @param station
     * @pre The Tram Object has been properly initialized
     * @pre station is a non-empty string
     * @post The Tram Object's Current Station has been set to the next Station
     * @return string
     */
    virtual string verplaatsTram(string station);

    /**
     * @fn bool isAlbatros()
     * @brief Returns true if the Tram Object is of the Albatros type
     * @pre The Tram Object has been properly initialized
     * @return boolean
     */
    virtual bool isAlbatros();
};


#endif //XML_EX_TRAM_H
