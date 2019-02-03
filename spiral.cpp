//
// Created by Trevor Rybicki on 2019-02-02.
//

#include "spiral.h"
#include <fstream>
#include <string>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

spiral::spiral(char *inputFileName) {
    // read input from file into ourString
    if (inputFileName != nullptr) {
        std::ifstream inputStream(inputFileName);
        std::string tmpString;
        getline(inputStream, tmpString);
        ourString = new char[tmpString.length()];
        strcpy(ourString, tmpString.c_str());
        inputStream.close();
    }
    // replaces the matrixSideSize function
    matrixSize = ceil(sqrt(strlen(ourString)));

}

void spiral::spiralMaker() {


    ourSpiral = new char*[matrixSize * matrixSize];

    //allocation of a char for each element...
    for(int i = 0; i < (matrixSize * matrixSize); i++) {
        ourSpiral[i] = new char[1];
    }




    //changeStep - how much until we permanently deincrement how many steps we take
    int changeStep = 3;

    //movementHolder - how much we should be going. initializer. if 0, then we're done
    //movementGo - how much moves left before we check
    int movementHolder = matrixSize - 1;
    int movementCounter = movementHolder;

    //direction?
    int drowVal = 0;
    int dcolVal = 1;

    //points to accessing our matrix.
    int rowVal = 0, colVal = 0;

    //How many letters we increment?
    int lettersLeft = strlen(ourString);

    //do we print a letter from our string or '.'
    int stringIndex = 0;

    //flag to leave while loop
    bool flag = true;
    for(int x = 0; x < (matrixSize * matrixSize); x++) {
        //put in letters from the input string. if there are none, instead place a .
        if (lettersLeft > 0) {
            //test
            cout << "Placing letter of '" << ourString[stringIndex] << "' at " << rowVal << "," << colVal << endl;
            ourSpiral[rowVal][colVal] = ourString[stringIndex];
            lettersLeft += -1;
            stringIndex++;
        }
        else {
            cout << "Placing letter of '" << '.' << "' at " << rowVal << "," << colVal << endl;
            ourSpiral[rowVal][colVal] = '.';
        }

        //adjust movement
        rowVal += drowVal;
        colVal += dcolVal;

        //increment move
        //cout << "movementCounter before: " << movementCounter << endl;
        movementCounter--;
        cout << "movementCounter after: " << movementCounter << endl;
        //out of moves? change dir
        if (movementCounter == 0) {
            //Going down
            if (dcolVal == 1) {
                //cout << "Direction is now down" << endl;
                drowVal = 1;
                dcolVal = 0;
            }
                //Going left
            else if (drowVal == 1) {
                //cout << "Direction is now left" << endl;
                dcolVal = -1;
                drowVal = 0;
            }
                //Going up
            else if (dcolVal == -1) {
                //cout << "Direction is now up" << endl;
                drowVal = -1;
                dcolVal = 0;
            }
                //Going right
            else if (drowVal == -1) {
                //cout << "Direction is now right" << endl;
                dcolVal = 1;
                drowVal = 0;
            }
            movementCounter = movementHolder;
            changeStep--;
        }
        //Do we need to decrease overall movement?
        //if yes, we deincrement movementHolder
        if (changeStep == 0) {
            movementHolder--;
            changeStep = 2;
            movementCounter = movementHolder;
        }
        //at the middle, exit loop
    }
}

void spiral::printToOutput(const char* outputFileName) {
    ofstream outFile;
    outFile.open(outputFileName);

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            outFile << ourSpiral[i][j];
        }
        outFile << endl;
    }
    outFile.close();
}