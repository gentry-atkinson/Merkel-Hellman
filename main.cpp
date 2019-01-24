#include <iostream>
#include <cstring>
#include "include/keyPair.h"


using namespace std;

int main(int argc, char** argv)
{
    keyPair kp;
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
            if (strcmp(argv[1], "gen") == 0){
                kp.generateKeys();
            }
    }
    return 0;
}
