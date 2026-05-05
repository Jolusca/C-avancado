# TODO

- [x] max 4 usando o max2 recursivamente
- [ ] printStruct com o .h para a passagem dos dados da struct

0 - First you should write a simple hello.c file, then you will compile this file following the steps below

1 - Preprocessing
gcc hello.c -E > hello.i 
 a extensão nn faz diferença, é o -E q faz

2 - Compiling
gcc -S hello.c
gcc -S helloworld.i

3 - Assembling
as hello.s -o hello.o
gcc -c hello.c

4 - Linking
gcc hello.o -o hello

## gcc hello.c -o hello

###Decompiler
https://dogbolt.org/


gcc main.c -o main -DDEBUG (define debug)
