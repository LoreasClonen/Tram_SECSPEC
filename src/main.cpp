//
// Created by luuk on 19-3-17.
//

#include "Parser/Parser.h"
#include <iostream>


using namespace std;

int main(int argc, char** argv){
    Parser parser;
    parser.XmlParser(argv[1]);
    System* system = parser.getSystem();
    system->properlyparsed();
    system->Output();
    system->autoSimulation();
}

