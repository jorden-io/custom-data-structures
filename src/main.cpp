#include <iostream>
#include "hash_map.hpp"
#include "stack.hpp"
#include "vec.hpp"

int main(int argc, char *argv[])
{
    ds::hash_map<int> hash_map{};
    hash_map("hello", 8008);
    hash_map("world", 7777);
    std::cout << hash_map["hello"] << "\n";
    std::cout << hash_map["world"];
    return 0;
}