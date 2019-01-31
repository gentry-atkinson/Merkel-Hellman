/***************************************************
*Author: Gentry Atkinson
*Project: MerkHell
*File: main.cpp
*Date: 31 Jan, 2019
*
*This is a simple command line implementation of the
*Merkel-Hellman knapsack cryptosystem.
****************************************************/



#include <iostream>
#include <cstring>
#include "include/keyPair.h"
#include "include/Writer.h"
#include "include/Reader.h"

using namespace std;

int main(int argc, char** argv)
{
    keyPair kp;
    Writer w;
    Reader r;
    switch(argc){
        case 1:
            cout << "Usage:" << endl;
            cout << "MerkHell:\tdisplay this menu." << endl;
            cout << "MerkHell gen:\tproduce a new key pair." << endl;
            cout << "MerkHell gen filename:\tproduce a key pair with a particular name." << endl;
            cout << "MerkHell enc textfile:\tencrypt a textfile using a public key file with the default name." << endl;
            cout << "MerkHell enc textfile keyfile:\tencrypt a textfile with a particular public keyfile" << endl;
            cout << "MerkHell dec cypherfile:\tdec a cyphertext file with a default private key." << endl;
            cout << "MerkHell dec cypherfile keyfile:\tdecrypt a cyphertext file with a particular private key" << endl;
            cout << "MerkHell --help:\tdisplay this menu" << endl;
            break;
        case 2:
            if (strcmp(argv[1], "--help") == 0){
                cout << "Usage:" << endl;
                cout << "MerkHell:\tdisplay this menu." << endl;
                cout << "MerkHell gen:\tproduce a new key pair." << endl;
                cout << "MerkHell gen filename:\tproduce a key pair with a particular name." << endl;
                cout << "MerkHell enc textfile:\tencrypt a textfile using a public key file with the default name." << endl;
                cout << "MerkHell enc textfile keyfile:\tencrypt a textfile with a particular public keyfile" << endl;
                cout << "MerkHell dec cypherfile:\tdec a cyphertext file with a default private key." << endl;
                cout << "MerkHell dec cypherfile keyfile:\tdecrypt a cyphertext file with a particular private key" << endl;
                cout << "MerkHell --help:\tdisplay this menu" << endl;
            }
            else if (strcmp(argv[1], "gen") == 0){
                kp.generateKeys();
            }
            else {
                cerr << "Unrecognized input. Use \"MerkHell --help\" for syntax." << endl;
            }
            break;
        case 3:
            char tempPriv[50], tempPub[50];
            strcpy(tempPriv, argv[2]);
            strcpy(tempPub, argv[2]);
            if (strcmp(argv[1], "gen") == 0){
                kp.generateKeys(strcat(tempPriv, ".private.key"), strcat(tempPub, ".public.key"));
            }
            else if (strcmp(argv[1], "enc") == 0){
                w.encipher(argv[2],"public.key");
            }
            else if (strcmp(argv[1], "dec") == 0){
                //cout << argv[2] << endl;
                r.decrypt(argv[2], "private.key");
            }
            else {
                cerr << "Unrecognized input. Use \"MerkHell --help\" for syntax." << endl;
            }
            break;
        case 4:
            if (strcmp(argv[1], "enc") == 0){
                w.encipher(argv[2], argv[3]);
            }
            else if (strcmp(argv[1], "dec") == 0){
                r.decrypt(argv[2], argv[3]);
            }
            else {
                cerr << "Unrecognized input. Use \"MerkHell --help\" for syntax." << endl;
            }
            break;
        default:
            cerr << "Unrecognized input. Use \"MerkHell --help\" for syntax." << endl;
    }
    return 0;
}
