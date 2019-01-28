#include "../include/Writer.h"

#include <math.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

Writer::Writer()
{
    //ctor
}

Writer::~Writer()
{
    //dtor
}

void Writer::charToBits(char input){
    //cout << endl << input << ": ";
    int numInput = static_cast<int>(input);
    for (int i = charSize - 1; i >= 0; i--){
        if (numInput >= pow(2, i)){
            numInput -= pow(2,i);
            bitArray[i] = 1;
        }
        else{
            bitArray[i] = 0;
        }
        //cout << bitArray[i];
    }

    return;
}

void Writer::encipher(string textName, string keyName){
    char nextChar;
    int sumToWrite;

    ifstream keyStream;
    keyStream.open(keyName);
    string nextKeyVal;
    for (int i = 0; i < charSize; i++){
        keyStream >> nextKeyVal;
        keyArray[i] = stoi(nextKeyVal);
    }

    ifstream plainStream;
    plainStream.open(textName);
    ofstream cipherStream;
    cipherStream.open("message.cipher");

    while(!plainStream.eof()){
        plainStream.get(nextChar);
        charToBits(nextChar);
        sumToWrite = 0;
        for (int i = 0; i < charSize; i++){
            sumToWrite += (bitArray[i] * keyArray[i]);
        }
        cipherStream << sumToWrite << " ";
    }

    for (int i = 0; i < charSize; i++){
        bitArray[i] = 0;
        keyArray[i] = 0;
    }
    nextChar = ' ';
    plainStream.close();
    cipherStream.close();

    return;
}
