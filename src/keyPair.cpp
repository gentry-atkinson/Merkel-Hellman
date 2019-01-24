#include "../include/keyPair.h"

//#include <fstream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

keyPair::keyPair()
{
    r = 197;
    //we're going to assume 8-bit character encoding
    charSize = 8;
}

keyPair::~keyPair()
{
    //dtor
}

void keyPair::generatePrivate(int[] w, int& sigma_w, int& q, int& r, ofstream privKey){

    srand (time(NULL));
    sigma_w = 0;
    w[0] = rand() % 32;
    sigma_w += w[0];
    for (int i = 1; i < charSize; i++){
        w[i] = (2 * w[i-1]) + (rand() % 32);
        sigma_w += w[i];
    }

    q = sigma_w + (rand() % sigma_w);

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
        inFile >> beta[i];
    }
}

void keyPair::generateKeys(char* privName, char* pubName){
    int w[] = {0,0,0,0,0,0,0,0};    //an SI set
    int sigma_w;                   //the sum of w
    int q;                         //a value greater than sigma_w
    int r;                         //a value in [1,q] coprime to q
    ofstream privKey(privName);
    ofstream pubKey(pubName);
    generatePrivate(w, sigma_w, q, r, privKey);

    return;
}
