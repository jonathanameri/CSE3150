// Created by Y. Wu, Jan 31, 2023
// You are given an input containter (of any STL set/vec/etc) of certain type (e.g., int, string, etc), a container of forbidden items (which may be any STL container type, and so may not be sorted), and a new censored value (of the same type). You are to output (STL container of the same type) the sorted list of items from the input such that this list contains all the items from the input, and any value appearing in the forbidden list is converted to the censored value.  
// For example, suppose the input: [1 -1 2, 5, 2], forbidden list [-1], censored value = 0, then the output is: [0, 1, 2, 2, 5]

// You are to implement a function called ECCensor, which takes four parameters: (i) input container
// of some type, (ii) container for forbidden items, (iii) converted value, and (iv) output container
// of some type. ECCensor will copy items from input container to the output container; for each
// item, if this item is not one of the forbidden items, it just copies the original item; otherwise, it is
// replaced by the passed “converted value”. Also, the output items should sorted. Note: you should
// just sort the output items produced by the current function call. Don’t sort the entire output
// container: suppose one makes many calls to ECCensor and each time the output is not very long;
// but sorting the entire output container could be time consuming. The motivation is from Internet
// Censorship, where companies often need to block certain type of contents. Here, we implement a
// very simplified version of this censorship.

// Now define the function ECCensor ...
#include <algorithm>
#include <iterator>
#include <vector>

template<typename InputC, typename ForbiddenC, typename OutputC>
void ECCensor(const InputC& inputContainer, const ForbiddenC& forbiddenItems, 
              const typename OutputC::value_type& convertedValue, OutputC& outputContainer)
{
    std::vector<typename OutputC::value_type> vectorOut;
    typename OutputC::value_type cv = convertedValue;
    for (const auto& item : inputContainer) {
        if (std::find(forbiddenItems.begin(), forbiddenItems.end(), item) != forbiddenItems.end()) {
            vectorOut.push_back(cv);
        }
        else {
            vectorOut.push_back(item);
        }
    }
    std::copy(vectorOut.begin(), vectorOut.end(), std::inserter(outputContainer, outputContainer.end()));

    //I don't understand how they would want us to do this without sorting at the end
    std::sort(outputContainer.begin(), outputContainer.end());
}