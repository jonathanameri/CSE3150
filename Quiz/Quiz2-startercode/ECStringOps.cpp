// The following implementation is the code I wrote in ICE week 2
// Now, add namespace ECStringOps and move ECRemoveSpace into this namespace
#include "ECStringOps.h" 

void ECStringOps::ECRemoveSpace(int nums[], int len, int val)
{
  int posLeft=0, posRight=len-1;
  while(posLeft <= posRight )
  {
    if( nums[posLeft] == val  )
    {
      nums[posLeft] = nums[posRight];
      nums[posRight] = '_';
      --posRight;
    }
    else
    {
      ++posLeft;
    }
  }

}

