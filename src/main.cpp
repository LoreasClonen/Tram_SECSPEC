//
// Created by luuk on 19-3-17.
//

#include "Parser/Parser.h"
#include <iostream>


using namespace std;

int main(){
    Parser parser;
    parser.XmlParser("testInput/TramSnelheid.xml");
    System* system = parser.getSystem();
    system->properlyparsed();
    system->Output();
    system->autoSimulation();
}

