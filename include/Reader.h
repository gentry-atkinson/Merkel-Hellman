#ifndef READER_H
#define READER_H

#include <string>


class Reader
{
    public:
        Reader();
        ~Reader();
        void decrypt(std::string = "message.cypger", std::string = "private.key");

    private:
        int s;
        int q;
        void calcS();
};

#endif // READER_H
