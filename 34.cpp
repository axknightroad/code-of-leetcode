#include <vector>
#include <iostream>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
  vector<int> ans(2, -1);
  int length = nums.size();  
  int l0 = 0, l1 = 0, r0 = length - 1, r1 = length -1, mid0 , mid1;
  bool isFound0 = false, isFound1 = false;
  if(!length || nums[l0] > target || nums[r0] < target) return ans;

  if(nums[l0] == target) {
    isFound0 = true;
    ans[0] = l0;
    
  }
  
  if(nums[r0] == target) {
    isFound1 = true;
    ans[1] = r0;
  }

  while (!isFound0 || !isFound1) {
    if (l0 > r0 || l0 < 0 || r0 >= length || l1 > r1 || l1 < 0 || r1 >= length) break;
    if (!isFound0) {
      mid0 = l0 + (r0 - l0) / 2;
      if(nums[mid0] < target && nums[mid0 + 1] == target) {
	ans[0] = mid0 + 1;
	isFound0 = true;
      } else if (nums[mid0 + 1] < target) {
	l0 = mid0 + 1;
      } else  {
	r0 = mid0 - 1;
      }
    }
    if (!isFound1) {
      mid1 = l1 + (r1 - l1) / 2;
      if(nums[mid1] > target && nums[mid1 - 1] == target) {
	ans[1] = mid1 - 1;
	isFound1 = true;
      } else if (nums[mid1] <= target) {
	l1 = mid1 + 1;
      } else {
	r1 = mid - 1;
      }
    }
    
  }
  return ans;
  
}
