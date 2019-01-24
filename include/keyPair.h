#ifndef KEYPAIR_H
#define KEYPAIR_H

#include<fstream>

class keyPair
{
    public:
        keyPair();
        virtual ~keyPair();
        void generateKeys(char* privName="private.key", char* pubName="public.key");

    private:
        void generatePrivate(int[], int&, int&, int&, std::fstream&);
        void generatePublic(int[], int&, int&, int&, std::fstream&);
        //bool isCoPrime(int, int);
        int* privateWeights;
        int q;
        int* publicWeights;
        int charSize;
        int r;
};

#endif // KEYPAIR_H
