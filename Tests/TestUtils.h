// TicTacToeUtils:
// Copyright: Project Software Engineering - BA1 informatica - Serge Demeyer -
// University of Antwerp

#ifndef TestUtils_H
#define TestUtils_H

#include <iostream>

bool DirectoryExists(const std::string dirname);

bool FileExists(const std::string dirname);

bool FileIsEmpty(const std::string filename);

bool FileCompare(const std::string leftFileName, const std::string rightFileName);

#endif
