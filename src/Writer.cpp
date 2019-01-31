/***************************************************
*Author: Gentry Atkinson
*Project: MerkHell
*File: Writer.cpp
*Date: 31 Jan, 2019
*
*This is a simple command line implementation of the
*Merkel-Hellman knapsack cryptosystem.
****************************************************/

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

//Converts two char values to bits in a 16 value
//int array
void Writer::charToBits(char input1, char input2){
    //cout << endl << input1 << input2 << ": ";
    int numInput = static_cast<int>(input1);
    for (int i = (charSize/2) - 1; i >= 0; i--){
        if (numInput >= pow(2, i)){
            numInput -= pow(2,i);
            bitArray[i] = 1;
        }
        else{
            bitArray[i] = 0;
        }
        //cout << bitArray[i] << " ";
    }

    numInput = static_cast<int>(input2);
    for (int i = (charSize/2) - 1; i >= 0; i--){
        if (numInput >= pow(2, i)){
            numInput -= pow(2,i);
            bitArray[i+(charSize/2)] = 1;
        }
        else{
            bitArray[i+(charSize/2)] = 0;
        }
        //cout << bitArray[i+(charSize/2)] << " ";
    }

    return;
}

//Reads 2 chars at a time from a plaintext file.
//Chars are converted to int value 'a'
//Writes values (sum(a[i] * beta[i])) to ciphertext file
void Writer::encipher(string textName, string keyName){
    char nextChar1, nextChar2;
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
        plainStream.get(nextChar1);
        if(plainStream.eof()){
            nextChar2 = '\n';
        }
        else{
            plainStream.get(nextChar2);
        }
        charToBits(nextChar1, nextChar2);
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
    nextChar1 = ' ';
    nextChar2 = ' ';
    plainStream.close();
    cipherStream.close();

    return;
}
