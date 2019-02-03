//
// Created by Trevor Rybicki on 2019-02-02.
//

#ifndef GAJOE1_SPIRAL_H
#define GAJOE1_SPIRAL_H


class spiral {
private:
    char ** ourSpiral;
    int matrixSize;
    char* ourString;
public:
    spiral(char* inputFileName);
    void spiralMaker();
    void printToOutput(const char* outputFileName);

};


#endif //GAJOE1_SPIRAL_H
