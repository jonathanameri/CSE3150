#include <vector>

bool IsNonDecreasing( const std::vector<int> &vec)
{
    for(unsigned int i = 1; i < vec.size(); ++i)
    {
        if(vec[i] < vec[i-1]){
            return false;
        }
    }
    return true;
}
