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

To use different encryption keys, change the entries in the file `keys`. The keys are ordered public_key, divisor, private_key: or e, n, d.

A better key method to be added.
