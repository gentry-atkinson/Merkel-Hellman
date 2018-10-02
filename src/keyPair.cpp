#include "../include/keyPair.h"

#include <fstream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

keyPair::keyPair()
{
    r = 197;
    charSize = 8;

    ifstream inFile("SISet.txt");
    if (!inFile.good()){
        generatePrivate();
        generatePublic();
    }

    for (int i = 0; i < charSize; i++){

    }
}

keyPair::~keyPair()
{
    //dtor
}

void keyPair::generatePrivate(){
    fstream file;
    file.open("SISet.txt", fstream::out);

    //if (file.good()) return;
    //else {

    long int totalWeight = rand() %256;

    int charSize = 8;
    srand (time(NULL));

    for (int i = 0; i < charSize; i++){
        totalWeight = 2*totalWeight + (rand() % 5) + 1;
        file << totalWeight;
        file << ", ";
    }

    int q = totalWeight + (rand() % totalWeight);

    file << q;
    //}

    return;
}

void keyPair::generatePublic(){
    fstream outFile;
    outFile.open("RegSet.txt", fstream::out);

    ifstream inFile;
    inFile.open("SISet.txt");

    int beta[8];
    string input;

    for (int i = 0; i < charSize; i++){
        inFile >> input;
        beta[i] = stoi(input);
    }
}
