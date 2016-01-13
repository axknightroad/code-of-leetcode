#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseArray(vector<int>& nums, int i){
  int j = 0;
  for (j = nums.size()-1.; j > i; j--) {
    if(nums[j] > nums[i]) break;
  }

  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
  sort(nums.begin()+i+1, nums.end());
}


void nextPermutation(vector<int>& nums) {
  bool isSuccess = false;

  for(int i = nums.size() - 1; i > 0; i--) {
    if (nums[i] <= nums[i-1]) continue;
    reverseArray(nums , i-1);
    isSuccess = true;
  }

  if (!isSuccess) sort(nums.begin(), nums.end());
  
}
