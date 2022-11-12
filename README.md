# bool8_t
8 boolean values stored in 1 byte. It was originally created in 23rd May 2020.

bool8_t is an unsigned 1 byte integer
class that lets you to store 8 bools
(8 bytes) in 1 byte.

- use [] to access each value.
- use set(index, value) to assign value.
    
To use effectively in actual coding,
you better define your boolean names that
corresponds to each index of array using

#define BOOL_NAME INDEX
    
so you dont struggle with indexes
