pseudo-encrypt
==============

An ***insecure*** imitation encryption program

Encrypt text from stdin using ./encrypt -e  
Encrypted text is written to a file called `encrypted`.  
*e.g.* `echo -n "String to be encrypted" | ./encrypt -e`

Decrypt text from stdin using ./encrypt  
Decrypted text is written to a file called `decrypted`.  
*e.g.* `cat encrypted | ./encrypt`
