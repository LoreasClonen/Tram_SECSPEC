//
// Created by Luuk van Sloun on 3/9/17.
//

#include "Parser.h"
#include "../Station/Metrostation.h"
#include "../Station/Halte.h"
#include "../Tram/Albatros.h"
#include "../Tram/PCC.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Parser::Parser() {}

string Parser::getElement(TiXmlElement* elem){
    TiXmlNode* firstChild = elem->FirstChild();
    if(firstChild == NULL){
        return "";
    }

    string t = firstChild->Value();

    return t;
}

bool Parser::is_number(const string& s)
{
    return !s.empty() && find_if(s.begin(),
                                      s.end(), [](char c) { return !isdigit(c); }) == s.end();
}



bool Parser::XmlParser(string inputFile) {
    ofstream outputFile;
    outputFile.open("LogFiles/parserLog.txt");
    bool output = true;
    outputFile << "======================" << endl;
    outputFile << "Starting XML Parser..." << endl;
    outputFile << "======================" << endl << endl;
    TiXmlDocument doc;
    const char *file = inputFile.c_str();
    if (!doc.LoadFile(file)) {
        doc.Clear();
        return false;
    }

    TiXmlElement* root = doc.FirstChildElement();
    if (root == NULL) {
        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
        return false;
    }
    System* system = new System;

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL;
         elem = elem->NextSiblingElement()) {
        string elemName = elem->Value();

        if (elemName == "station") {
            outputFile << "Creating new Station:" << endl;
            map<int, Spoor*> tracks;

            string naam = "";
            string type = "";

            for (TiXmlElement *insideElem = elem->FirstChildElement(); insideElem != NULL;
                 insideElem = insideElem->NextSiblingElement()) {
                string elemName = insideElem->Value();


                if (elemName == "naam") {
                    outputFile << "   Getting Station name..." << endl;
                    naam = getElement(insideElem);
                    outputFile << naam << endl;

                }
                if (elemName == "spoor") {
                    Spoor* spoor = new Spoor();

                    string volgende = "";
                    string vorige = "";
                    int spoorNr = -1;

                    for (TiXmlElement *inInsideElem = insideElem->FirstChildElement(); inInsideElem != NULL;
                         inInsideElem = inInsideElem->NextSiblingElement()) {
                        string elemName = inInsideElem->Value();

                        outputFile << "   Getting Station track..." << endl;
                        if(elemName == "spoorNr") {
                            if (is_number(getElement(inInsideElem))) {
                                outputFile << getElement(inInsideElem) << endl;
                                spoorNr = stoi(getElement(inInsideElem));

                            } else {
                                outputFile << " FAULT IN STATION TRACK." << endl;
                                output = false;
                            }
                        }
                        if (elemName == "volgende") {
                            outputFile << "   Getting next Station..." << endl;

                            volgende = getElement(inInsideElem);
                            outputFile << volgende << endl;
                        }
                        if (elemName == "vorige") {
                            outputFile << "   Getting previous Station..." << endl;

                            vorige = getElement(inInsideElem);
                            outputFile << vorige << endl;
                        }
                    }
                    if (spoorNr < 0) {
                        outputFile << "Track Number is negative" << endl;
                        output = false;
                    }
                    if (volgende == "") {
                        outputFile << "Next Station is empty" << endl;
                        output = false;
                    }
                    if (vorige == "") {
                        outputFile << "Previous Station is empty" << endl;
                        output = false;
                    }
                    if (!output) {
                        outputFile << "DELETING INCOMPLETE TRACK" << endl;
                        delete spoor;
                    }
                    if(output) {
                        tracks[spoorNr] = spoor;
                        spoor->setSpoorNr(spoorNr);
                        spoor->setVolgende(volgende);
                        spoor->setVorige(vorige);
                    }
                }

                if (elemName == "type") {
                    outputFile << "   Getting Station Type..." << endl;

                    type = getElement(insideElem);
                    outputFile << type << endl << endl;
                }
            }
            if(type != "halte" and type != "metrostation") {
                if(type == ""){
                    outputFile << "Station Type is empty" << endl;
                }
                else{
                    outputFile << "Station Type is incorrect" << endl;
                }
                output = false;
            }
            Station* station;
            if(type == "halte" or type == "metrostation") {
                if (type == "halte") {

                    station = new Halte;

                    station->setSporen(tracks);
                }

                else if (type == "metrostation") {
                    station = new Metrostation;

                    station->setSporen(tracks);
                }

                if (naam == "") {
                    outputFile << "Station Name is empty" << endl;
                    output = false;
                }

                if (!output) {
                    outputFile << "DELETING INCOMPLETE STATION" << endl;
                    for (auto c : station->getSporen()) {
                        c.second = NULL;
                    }
                    delete station;
                } else {
                    station->setNaam(naam);

                    system->addStation(naam, station);
                }
            }
        }

        else if (elemName == "tram") {
            outputFile << "Creating new Tram:" << endl;

            int lijnNr = -1;
            int zitplaatsen = -1;
            int snelheid = -1;
            string beginStation = "";
            string type = "";
            int voertuigNr = -1;

            for (TiXmlElement *insideElem = elem->FirstChildElement(); insideElem != NULL;
                 insideElem = insideElem->NextSiblingElement()) {
                 string elemName = insideElem->Value();


                if (elemName == "lijnNr") {
                    outputFile << "   Getting Tram Number..." << endl;
                    if(is_number(getElement(insideElem))){
                        lijnNr = stoi(getElement(insideElem));
                    }
                    else {
                        outputFile << " FAULT IN TRAMNUMBER." << endl;
                        output = false;
                    }
                }
                if (elemName == "zitplaatsen") {
                    outputFile << "   Getting Tram seats..." << endl;
                    if(is_number(getElement(insideElem))){
                        zitplaatsen = stoi(getElement(insideElem));
                    }
                    else {
                        outputFile << " FAULT IN SEATS." << endl;
                        output = false;
                    }
                }

                if (elemName == "snelheid") {
                    outputFile << "   Setting Tram speed..." << endl;
                    if(is_number(getElement(insideElem))){
                        snelheid = stoi(getElement(insideElem));
                    }
                    else {
                        outputFile << " FAULT IN SPEED." << endl;
                        output = false;
                    }
                }

                if (elemName == "beginStation") {
                    outputFile << "   Setting Starting Station..." << endl;
                    outputFile << "   Setting Current Station..." << endl;

                    beginStation = getElement(insideElem);

                }

                if (elemName == "type"){
                    outputFile << "   Setting Tram Type..." << endl;

                    type = getElement(insideElem);
                }

                if (elemName == "voertuigNr") {
                    outputFile << "   Setting Tram Vehicle Number..." << endl;
                    if(is_number(getElement(insideElem))){
                        voertuigNr = stoi(getElement(insideElem));
                    }
                    else {
                        output = false;
                    }
                }
            }
            if(type != "Albatros" and type != "PCC") {
                if(type == ""){
                    outputFile << "Station Type is empty" << endl;
                }
                else{
                    outputFile << "Station Type is incorrect" << endl;
                }
                output = false;
            }
            Tram* tram;
            if(type == "Albatros" or type == "PCC") {
                if (type == "Albatros") {

                    tram = new Albatros;
                }

                else if (type == "PCC") {
                    tram = new PCC;
                }

                if (lijnNr < 0) {
                    outputFile << "Tram Line Nr. is negative" << endl;
                    output = false;
                }
                if (zitplaatsen < 0) {
                    outputFile << "Amount of Seats is negative" << endl;
                    output = false;
                }
                if (snelheid < 0) {
                    outputFile << "Tram Speed is negative" << endl;
                    output = false;
                }
                if (beginStation == "") {
                    outputFile << "Tram Starting Station is empty" << endl;
                    output = false;
                }
                if (voertuigNr < 0) {
                    outputFile << "Tram Vehicle Nr. is negative" << endl;
                    output = false;
                }


                if (!output) {
                    outputFile << "DELETING INCOMPLETE TRAM" << endl;
                    delete tram;
                } else {
                    tram->setLijnNr(lijnNr);
                    tram->setZitplaatsen(zitplaatsen);
                    tram->setSnelheid(snelheid);
                    tram->setBeginStation(beginStation);
                    tram->setVoertuigNr(voertuigNr);

                    system->addTram(voertuigNr, tram);
                }
            }
        }
        else if (elemName == "passagier") {
            Passagier* passagier = new Passagier;
            outputFile << "Creating new Passagier:" << endl;

            string naam = "";
            string beginStation = "";
            string eindStation = "";
            int hoeveelheid = -1;

            for (TiXmlElement *insideElem = elem->FirstChildElement(); insideElem != NULL;
                 insideElem = insideElem->NextSiblingElement()) {
                string elemName = insideElem->Value();


                if (elemName == "naam") {
                    outputFile << "   Getting Passenger Name..." << endl;

                    naam = getElement(insideElem);

                }
                if (elemName == "beginstation") {
                    outputFile << "   Getting Passenger Starting Station..." << endl;

                    beginStation = getElement(insideElem);
                }

                if (elemName == "eindstation") {
                    outputFile << "   Setting Passenger End Station..." << endl;

                    eindStation = getElement(insideElem);
                }

                if (elemName == "hoeveelheid") {
                    outputFile << "   Setting Amount of Passengers..." << endl;
                    if(is_number(getElement(insideElem))){
                        hoeveelheid = stoi(getElement(insideElem));
                    }
                    else {
                        output = false;
                    }
                }
            }
            if(naam == "") {
                outputFile << "Passenger Name is empty" << endl;
                output = false;
            }
            if(beginStation == "") {
                outputFile << "Passenger Starting Station is empty" << endl;
                output = false;
            }
            if(eindStation == "") {
                outputFile << "Passenger End Station is empty" << endl;
                output = false;
            }
            if(hoeveelheid < 0) {
                outputFile << "Amount of Passengers is negative" << endl;
                output = false;
            }
            if(!output){
                outputFile << "BEGINSTATION PASSAGIER NIET IN SYSTEEM" << endl;
                delete passagier;
            }
            else{
                system->addPassagier(naam, passagier);
                passagier->setNaam(naam);
                passagier->setBeginStation(beginStation);
                passagier->setEindStation(eindStation);
                passagier->setHoeveelheid(hoeveelheid);

                if(system->getStations().find(beginStation) != system->getStations().end()){
                    system->getStations().find(beginStation)->second->addPassagier(naam);
                }
            }
        }
    }
    system->setProperlyParsed(output);
    Parser::setSystem(system);

    outputFile << "===================" << endl;
    outputFile << "XML Parser finished" << endl;
    outputFile << "===================" << endl << endl;
    doc.Clear();
    outputFile.close();

    return output;
}

System *Parser::getSystem() const {
    return system;
}

void Parser::setSystem(System *system) {
    Parser::system = system;
}
