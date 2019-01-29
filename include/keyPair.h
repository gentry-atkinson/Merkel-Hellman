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
        void generatePrivate(long[], long&, long&, long&, std::fstream&);
        void generatePublic(long[], long&, long&, long&, std::fstream&);
        static const int charSize = 16;
};

#endif // KEYPAIR_H
