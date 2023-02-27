// Created by Y. Wu, Feb 16, 2023
// You are given two containers, src and dest (with the same data type);
// you want to copy all items in src to dest (in the order of their appearance in src;
// of course, if dest has its own ordering like a set, you would just go with that container's ordering).
// After copying, dest should contain exactly the same list of items in src. You need to support all kinds of containers and data types.

#include <algorithm>

template <typename Container1, typename Container2>
void ECCopy(Container1 &src, Container2 &dest)
{
    // std::copy(src.begin(), src.end(), back_inserter(dest));
    dest.clear();
    for (auto x : src)
    {
        dest.insert(dest.end(), x);
    }
}