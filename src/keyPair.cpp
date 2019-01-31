/***************************************************
*Author: Gentry Atkinson
*Project: MerkHell
*File: keyPair.cpp
*Date: 31 Jan, 2019
*
*This is a simple command line implementation of the
*Merkel-Hellman knapsack cryptosystem.
****************************************************/

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
    //ctor
}

keyPair::~keyPair()
{
    //dtor
}

//Outputs the private key:
//  w-> a super increasing set of integer values
//  sigma_w-> the sum of all w values
//  q-> a value greater than sigma_w
//  r-> a value less than q
void keyPair::generatePrivate(long w[], long& sigma_w, long& q, long& r, fstream& privKey){
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

    for (int i = 0; i < charSize; i++){
        privKey << w[i] << " ";
    }
    privKey << q << " ";
    privKey << r << endl;

    return;
}

//Outputs the public key:
//  beta[i] = (w * r) mod q
void keyPair::generatePublic(long w[], long& sigma_w, long& q, long& r, fstream& pubKey){
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

//Default private key name is "private.key"
//Default public key name is "public.key"
//
//TODO: this method should only take a single name.
void keyPair::generateKeys(char* privName, char* pubName){
    long w[charSize] = {0};                  //an SI set
    long sigma_w;                   //the sum of w
    long q;                         //a value greater than sigma_w
    long r;                         //a value in [1,q] coprime to q

    fstream privKey;
    privKey.open(privName, std::fstream::out);
    fstream pubKey;
    pubKey.open(pubName, std::fstream::out);
    generatePrivate(w, sigma_w, q, r, privKey);
    privKey.close();
    generatePublic(w, sigma_w, q, r, pubKey);
    pubKey.close();

    //clean up
    for (int i = 0; i < charSize; i++)
        w[i] = 0;
    sigma_w = 0;
    q = 0;
    r = 0;

    return;
}
