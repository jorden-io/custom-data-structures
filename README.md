This repository serves as a fun exercise I did for myself to re create data structures from the standard library.
not every implimenation is the most optimal as I am very new to c++, although its not my first language.
intentionaly left out certain methods as I wanted to focus on the main keys of data structure.

         ------------hash-map--------------

uses a linked list under the hood, so operations are O(n) worst and O(1) with a hashing function lookup.
// hash_map(key, val) to insert, via operator overload
// hash_map["key"] for lookup, via operator overload.

         ------------vector---------------

simply a dynamicly sized array done through copying to buffer and re sizing. operations are O(n) at best and worst.

         ------------stack---------------

LIFO(last in first out) the stack is a simple datastructure with an array under the hood with primary methods being push and pop.
