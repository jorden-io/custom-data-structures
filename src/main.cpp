#include <iostream>
#include "hash_map.hpp"
#include "stack.hpp"
#include "vec.hpp"
int main(int argc, char *argv[])
{
    ds::hash_map<int> test_hash{};
    ds::stack stack{};
    ds::vec<int> vector{};
    test_hash("jessica", 8008);
    test_hash("pessica", 7777);
    test_hash("lessica", 9999);
    std::cout << test_hash["jessica"];
    return 0;
}