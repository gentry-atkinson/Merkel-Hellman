#ifndef KEYPAIR_H
#define KEYPAIR_H


class keyPair
{
    public:
        keyPair();
        virtual ~keyPair();

    private:
        void generatePrivate();
        void generatePublic();
};

#endif // KEYPAIR_H
