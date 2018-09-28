#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main () {

    fstream file;
    file.open("SISet.txt", fstream::out);

    long int totalWeight = 0;

    srand (time(NULL));

    for (int i = 0; i < 32; i++){
        totalWeight = 2*totalWeight + (rand() % 5) + 1;
        file << totalWeight;
        if (i < 31) file << ", ";
    }
    return 0;
}
