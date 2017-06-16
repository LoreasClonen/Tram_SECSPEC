/**
 * @file Tram.h
 *
 * @brief Header file for the PCC Class
 *
 * @class PCC
 *
 * @brief This Class contains all the functionalities for the PCC objects.
 *
 * @authors Loreas Clonen & Luuk van Sloun
 */

#include "Tram.h"


#include <iostream>

class PCC: public::Tram{
public:

    string verplaatsTram(std::string);
    string typeString();
    bool validStation(string type);
};