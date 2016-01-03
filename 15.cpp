#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<vector<int> > threeSum(vector<int>& nums) {
  vector<vector<int> > result;
  
  if (nums.size() < 3)  return result;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 1; i++) {
    if (i > 0 && nums[i] == nums[i-1]) continue;
    int l = i + 1;
    int r = nums.size() - 1;
    while (l < r) {
      int sum = nums[i] + nums[l] + nums[r];
      if (!sum) {
	vector<int> temp;
	temp.push_back(nums[i]);
	temp.push_back(nums[l]);
	temp.push_back(nums[r]);
	result.push_back(temp);
	l++;
	while(nums[l] == nums[l - 1]) l++;
      } else if (sum > 0) {
	r--;
      } else {
	l++;
      }
    }
  }
  
  return result;     
}


int main(){
  vector<int> nums;
  vector<vector<int> > result;
  result = threeSum(nums);

  return 0;
  
}
