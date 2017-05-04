//
// Created by luuk on 19-3-17.
//

#ifndef TRAM_NETWERK_PARSER_H
#define TRAM_NETWERK_PARSER_H

#include "tinyxml.h"
#include <iostream>
#include "System.h"

using namespace std;

class Parser {
private:
    System* system;
public:
    Parser();

    System *getSystem() const;

    void setSystem(System *system);

    string getElement(TiXmlElement *elem);

    bool XmlParser(string inputFile);

    bool is_number(const string& s);
};
#endif //TRAM_NETWERK_PARSER_H
