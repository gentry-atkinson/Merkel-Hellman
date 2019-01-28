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
    int outChar;

    //cout << "****Message****" << endl;
    while (!cypherFile.eof()){
        cypherFile >> inNum;
        inNum = (inNum * s) % q;
        //cout << inNum << " ";
        outChar = 0;
        for (int i = 7; i >= 0; i--){
            if(inNum >= w[i]){
                inNum -= w[i];
                outChar += pow(2, i);
                //cout << pow(2,i) << endl;
            }
        }
        //cout << outChar << endl;
        plainFile << static_cast<char>(outChar);
    }

    return;

}
