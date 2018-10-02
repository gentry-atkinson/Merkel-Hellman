#include "keyPair.h"

#include <fstream>
#include <cstdlib>
#include <time.h>

keyPair::keyPair()
{
    generatePrivate();
}

keyPair::~keyPair()
{
    //dtor
}

void keyPair::generatePrivate(){
    fstream file;
    file.open("SISet.txt", fstream::out);

    long int totalWeight = 0;

    srand (time(NULL));

    for (int i = 0; i < 32; i++){
        totalWeight = 2*totalWeight + (rand() % 5) + 1;
        file << totalWeight;
        if (i < 31) file << ", ";
    }

    q = totalWeight + (rand() % totalWeight);

    file << q;

    return 0;
}
