/**
 * @file Parser.h
 *
 * @brief Header file for the Parser Class
 *
 * @class Parser
 *
 * @brief This Class contains all the functionalities for the Parser objects.
 *
 * @authors Loreas Clonen & Luuk van Sloun
 */
#ifndef TRAM_NETWERK_PARSER_H
#define TRAM_NETWERK_PARSER_H

#include "../tinyxml/tinyxml.h"
#include <iostream>
#include "../System/System.h"

using namespace std;

class Parser {
private:
    System* system;

public:
    /**
     * @fn Parser();
     * @brief Parser Default Constructor
     * @post A new Parser Object has been created
     */
    Parser();

    /**
    * @fn System* getSystem()
    * @brief Returns the Parser object's System Object
    * @pre The Parser Object has been properly initialized
    * @pre The Parser Object has a non-empty member variable system
    * @return System Pointer
    */
    System *getSystem() const;

    /**
    * @fn System* getSystem()
    * @brief Sets a new Parser object's System Object
    * @param system - System Pointer
    * @pre The Parser Object has been properly initialized
    * @pre system has been properly initialized
    * @post The Parser Object's System is equal to system
    */
    void setSystem(System *system);

    /**
    * @fn string getElement(TiXmlElement *elem)
    * @brief Returns the text contained in a TiXmlElement Object
    * @pre The Parser Object has been properly initialized
    * @pre elem is a non-empty TiXmlElement
    * @return string
    */
    string getElement(TiXmlElement *elem);

    /**
    * @fn bool XmlParser(string inputFile)
    * @brief Returns true if the inputfile is correctly parsed, false if not
    * @pre The Parser Object has been properly initialized
    * @return boolean
    */
    bool XmlParser(string inputFile);

    /**
    * @fn bool is_number(const string& s)
    * @brief Returns true if the entered string is a number, false if not
    * @pre The Parser Object has been properly initialized
    * @pre s is a non-empty string
    * @return boolean
    */
    bool is_number(string s);
};
#endif //TRAM_NETWERK_PARSER_H
