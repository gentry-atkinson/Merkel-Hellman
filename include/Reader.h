#ifndef READER_H
#define READER_H

#include <string>


class Reader
{
    public:
        Reader();
        ~Reader();
        void decrypt(std::string = "message.cypher", std::string = "private.key");

    private:
        static const int charSize = 16;
        int w[charSize], q, r, s;
        void calcS();
};

#endif // READER_H
