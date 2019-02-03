#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h> //just in case
#include "ArgumentManager.h"
#include "spiral.h"

using namespace std;

int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cout << "Usage: Subsequence \"input=<file>;output=<file>\"" << std::endl;
        return -1;
    }

    ArgumentManager am(argc, argv);
    std::string infilename = am.get("input");
    std::string outfilename = am.get("output");
    std::cout << "File name for input: " << infilename << std::endl
              << "File name for output: " << outfilename << std::endl;

    char * in = new char[1000];
    spiral sp(strcpy(in, infilename.c_str()));
    sp.spiralMaker();
    sp.printToOutput(outfilename.c_str());
    delete [] in;
    return 0;
}