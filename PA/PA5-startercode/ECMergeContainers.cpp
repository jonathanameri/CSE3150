// Created by Y. Wu, Jan 31, 2023
// Merge lists (of any STL container type) into a single sorted list (of any STL container type)
// Duplicates allowed unless the output doesn't take duplicates (e.g., a map)
// Note: you should make your code as flexible as possible: you should allow all kinds of outputs: vector, set, etc 
// Make your code short: at most 10 lines of code (LOC) 

// now defiine ECMergeContainers ...
using namespace std;


template <class container, class container2>
typename container2 :: value_type ECMergeContainers(container &a, container2 &b)
{
    typename container2 :: value_type res;

    for(auto k : container)
    {
        for(auto item : k)
        {
            
        }
    }
}
