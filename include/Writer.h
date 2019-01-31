/***************************************************
*Author: Gentry Atkinson
*Project: MerkHell
*File: Writer.h
*Date: 31 Jan, 2019
*
*This is a simple command line implementation of the
*Merkel-Hellman knapsack cryptosystem.
*
*The Writer class reads a plaintext file and writes
*an encrypted text file.
****************************************************/

#ifndef WRITER_H
#define WRITER_H

#include <string>


class Writer
{
    public:
        Writer();
        ~Writer();
        void encipher(std::string = "plain.txt", std::string = "public.key");

    private:
        void charToBits(char, char);
        static const int charSize = 16;
        int bitArray[charSize];
        long keyArray[charSize];
};

#endif // WRITER_H
