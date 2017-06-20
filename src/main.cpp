
#include "Parser/Parser.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv){

    Parser parser;
    System* system;
    if(argc > 1){
        if(!strcmp(argv[1],"1")){
            parser.XmlParser(argv[2]);
        }
        else if(!strcmp(argv[1],"2")) {
            parser.XmlParser("testInput/MultipleErrors.xml");
        }
    }
    else{
        parser.XmlParser("InputFiles/XML_Test.xml");


    }
    system = parser.getSystem();
    system->Output();
    system->properlyparsed();
    system->autoSimulation();
}