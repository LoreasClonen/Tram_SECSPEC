Metro Netwerk
============

The documentation is created with doxygen comments.

Usage
-----
	There a 3 options for running the software:
		1. Entering the following command: ./Tram_Netwerk
		   This will use a hardcoded XML File, defined in the main.cpp file.
		2. Entering the following command: ./Tram_Netwerk 1 <XML>,
		   in which <XML> is the relative path from the rootfolder to the XML File
		3. Entering the following command: ./Tram_Netwerk 2
		   This will also use a hardcoded XML File, defined in the main.cpp file, so two
		   different files can be hardcoded for easy use.

	To run the debug version of the executable, enter the following command:
		   ./Tram_Netwerk_debug
	This will run the gtest library with all the tests
