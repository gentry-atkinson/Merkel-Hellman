/***************************************************
*Author: Gentry Atkinson
*Project: MerkHell
*File: Reader.h
*Date: 31 Jan, 2019
*
*This is a simple command line implementation of the
*Merkel-Hellman knapsack cryptosystem.
*
*The Reader class reads a file containing numerical
*values an deciphers them using a private key file
****************************************************/


#ifndef READER_H
#define READER_H

#include <string>

//TODO: push class variable into instance variables for consistency
class Reader
{
    public:
        Reader();
        ~Reader();
        void decrypt(std::string = "message.cypher", std::string = "private.key");

    private:
        static const int charSize = 16;
        long w[charSize], q, r, s;
        void calcS();
};

#endif // READER_H
