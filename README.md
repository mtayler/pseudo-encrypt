pseudo-encrypt
==============

An ***insecure*** imitation encryption program

Usage
-----

Encrypt text from stdin using ./encrypt -e  
Encrypted text is written to a file called `output.vir`.  
*e.g.* `echo -n "String to be encrypted" | ./encrypt -e`

Decrypt text from stdin using ./encrypt  
Decrypted text is written to a file called `output.txt`.  
*e.g.* `./encrypt < output.vir`

Encryption Keys
---------------

To use different encryption keys, change the entries in the file `keys`. The keys are ordered public_key, divisor, private_key: or e, n, d. If the decrypted file is not a plain text file, the keys are most likely too large, or too small to fully process the range of values defined in the ASCII standard.

A better key method to be added.
