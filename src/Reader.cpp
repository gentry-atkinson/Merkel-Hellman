#include "Reader.h"

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

void Reader::calcS(){
    //Please change this to use extended euclidean alg
    s = 1;
    while ((s*r)%q != 1)
        s++;
}

void Reader::decrypt(string messageName, string keyName){
    ifstream keyFile;
    keyFile.open(keyName);
    string incoming;
    for (int i = 0; i < charSize; i++){
        keyFile >> incoming;
        w[i] = stoi(incoming);
    }
    keyFile >> incoming;
    q = stoi(incoming);
    keyFile >> incoming;
    r = stoi(incoming);
    calcS();
    //cout << "S = " << s << endl;

    ofstream plainFile;
    ifstream cypherFile;
    plainFile.open("decrypt.txt");
    cypherFile.open(messageName);

    int inNum;
    int outChar;

    while (!cypherFile.eof()){
        cypherFile >> inNum;
        inNum = (inNum * s) % q;
        for (int i = charSize - 1; i >= 0; i--){
            if(inNum >= w[i]){
                inNum -= w[i];
                outChar += pow(2, i);
            }
        }
        plainFile << static_cast<char>(outChar);
    }

    return;

}
