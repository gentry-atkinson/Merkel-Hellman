/***************************************************
*Author: Gentry Atkinson
*Project: MerkHell
*File: Reader.cpp
*Date: 31 Jan, 2019
*
*This is a simple command line implementation of the
*Merkel-Hellman knapsack cryptosystem.
****************************************************/

#include "../include/Reader.h"

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

Reader::Reader()
{
    //ctor
}

Reader::~Reader()
{
    //dtor
}

//Calculate the inverse of r mod q
//TODO: use a decent algorithm
void Reader::calcS(){
    //Please change this to use extended euclidean alg
    s = 1;
    while ((s*r)%q != 1)
        s++;
    //cout << "calcS says S is " << s << endl;
}

//For each value in cipherfile, multiply by s mod q
//Extract two char values using superincreasing set w
void Reader::decrypt(string messageName, string keyName){
    ifstream keyFile;
    keyFile.open(keyName);
    string incoming;
    for (int i = 0; i < charSize; i++){
        keyFile >> incoming;
        w[i] = stoi(incoming);
        //cout << w[i] << " ";
    }
    keyFile >> incoming;
    q = stoi(incoming);
    keyFile >> incoming;
    r = stoi(incoming);
    //cout << endl << q << " " << r << endl;
    calcS();
    //cout << "S = " << s << endl;

    ofstream plainFile;
    ifstream cypherFile;
    plainFile.open("decrypt.txt");
    cypherFile.open(messageName);

    long inNum;
    int outChar1, outChar2;

    //cout << "****Message****" << endl;
    while (!cypherFile.eof()){
        cypherFile >> inNum;
        inNum = (inNum * s) % q;
        //cout << inNum << endl;
        outChar1 = 0;
        outChar2 = 0;
        for (int i = charSize-1; i >= charSize/2; i--){
            if(inNum >= w[i]){
                //cout << w[i] << " ";
                inNum -= w[i];
                outChar2 += pow(2, i-(charSize/2));
                //cout << pow(2, i-(charSize/2)) << " " << endl;
            }
        }
        //cout << endl;
        for (int i = (charSize/2)-1; i >= 0; i--){
            if(inNum >= w[i]){
                //cout << w[i] << " ";
                inNum -= w[i];
                outChar1 += pow(2, i);
                //cout << pow(2,i) << " " << endl;
            }
        }
        //cout << endl << "Char1: " << outChar1 << " Char2: " << outChar2 << endl << endl;
        plainFile << static_cast<char>(outChar1) << static_cast<char>(outChar2);
    }

    return;

}
