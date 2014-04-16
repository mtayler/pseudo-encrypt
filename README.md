pseudo-encrypt
==============

An ***insecure*** imitation encryption program

Usage
-----

Encrypt text from stdin using ./encrypt -e  
Encrypted text is written to a file called `encrypted`.  
*e.g.* `echo -n "String to be encrypted" | ./encrypt -e`

Decrypt text from stdin using ./encrypt  
Decrypted text is written to a file called `decrypted`.  
*e.g.* `cat encrypted | ./encrypt`

Encryption Keys
---------------

To use different encryption keys: 

1. Simply change the variables `private_key`, `public_key`, and `divisor`. See [this Wikipedia article on RSA key-generation](http://en.wikipedia.org/wiki/RSA_\(cryptosystem\)#Key_generation) to correctly generate keys (or use a utility such as ssh-keygen, and decode to decimal).
2. Run `make` to compile the program with the new keys.

A better key method will be developed later.
