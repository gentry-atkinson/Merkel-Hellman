#ifndef KEYPAIR_H
#define KEYPAIR_H


class keyPair
{
    public:
        keyPair();
        virtual ~keyPair();
        void generateKeys();

    private:
        void generatePrivate();
        void generatePublic();
        int* privateWeights;
        int q;
        int* publicWeights;
        int charSize;
        int r;
};

#endif // KEYPAIR_H
