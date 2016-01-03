#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
  vector<int>::iterator iter;
  
  for(iter = nums.begin(); iter < nums.end();) {
    if(nums[iter-nums.begin()] == val)
      iter = nums.erase(iter);
    else
      iter++;
  }

  return nums.size();
}
