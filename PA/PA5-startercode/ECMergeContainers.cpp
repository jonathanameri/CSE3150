// Created by Y. Wu, Jan 31, 2023
// Merge lists (of any STL container type) into a single sorted list (of any STL container type)
// Duplicates allowed unless the output doesn't take duplicates (e.g., a map)
// Note: you should make your code as flexible as possible: you should allow all kinds of outputs: vector, set, etc 
// Make your code short: at most 10 lines of code (LOC) 

// now defiine ECMergeContainers ...
#include <algorithm>
#include <iterator>

template <typename ContainerList, typename OutputContainer>
void ECMergeContainers(const ContainerList& containers, OutputContainer& output)
{
    for (const auto& container : containers) {
        std::copy(container.begin(), container.end(), std::inserter(output, output.end()));
    }
    std::sort(output.begin(), output.end());
}