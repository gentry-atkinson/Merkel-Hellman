# Merkel-Hellman

This is a simple (unsecure) command line implementation of the Merkell-Hellman Knapsack Cryptosystem. Its author is Gentry Atkinson, who can be reached at gma23@txstate.edu if you have any questions. Please keep in mind that this implementation is only meant to serve as a demonstration of the algorithm as is not, in any way, even a little bit, secure.

Usage:


MerkHell:	display this menu.

MerkHell gen:	produce a new key pair.

MerkHell gen filename:	produce a key pair with a particular name.

MerkHell enc textfile:	encrypt a textfile using a public key file with the default name.

MerkHell enc textfile keyfile:	encrypt a textfile with a particular public keyfile.

MerkHell dec cypherfile:	dec a cyphertext file with a default private key.

MerkHell dec cypherfile keyfile:	decrypt a cyphertext file with a particular private key.

MerkHell --help:	display this menu.
            
