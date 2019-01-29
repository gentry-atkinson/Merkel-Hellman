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
