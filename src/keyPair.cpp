#include "../include/keyPair.h"

//#include <fstream>
#include <cstdlib>
#include <time.h>
#include <string>
//#include <cmath>
#include <algorithm>
#include <iostream>

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

void keyPair::generatePrivate(int w[], int& sigma_w, int& q, int& r, fstream& privKey){
    if (!privKey.is_open()){
        cerr << "key filestream not open" << endl;
        return;
    }

    srand (time(NULL));
    sigma_w = 0;
    w[0] = rand() % 32;
    sigma_w += w[0];
    for (int i = 1; i < charSize; i++){
        w[i] = (2 * w[i-1]) + (rand() % 32);
        sigma_w += w[i];
    }

    q = sigma_w + (rand() % sigma_w);
    do{
        r = rand() % q;
    }while(__gcd(r,q) != 1);

    for (int i = 0; i < 8; i++){
        privKey << w[i] << " ";
    }
    privKey << q << " ";
    privKey << r << endl;

    return;
}

void keyPair::generatePublic(int w[], int& sigma_w, int& q, int& r, fstream& pubKey){
    if(!pubKey.is_open()){
        cerr << "key filestream not open" << endl;
        return;
    }

    for(int i = 0; i < charSize; i++){
        pubKey << (w[i] * r) % q << " ";
    }
    pubKey << endl;
    return;
}

void keyPair::generateKeys(char* privName, char* pubName){
    int w[] = {0,0,0,0,0,0,0,0};    //an SI set
    int sigma_w;                   //the sum of w
    int q;                         //a value greater than sigma_w
    int r;                         //a value in [1,q] coprime to q
    fstream privKey;
    privKey.open(privName, std::fstream::out);
    fstream pubKey;
    pubKey.open(pubName, std::fstream::out);
    generatePrivate(w, sigma_w, q, r, privKey);
    privKey.close();
    generatePublic(w, sigma_w, q, r, pubKey);

    return;
}
