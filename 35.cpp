#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  int length = nums.size();
  int l = 0, r = length - 1;
  
  if (!length) return 0;
  if (nums[0] >= target) return 0;
  if (nums[length - 1] == target) return length - 1;
  if (nums[length-1] < target) return length;

  while (l <= r && l >= 0 && r < length) {
    int mid = l + (r - l) /2;
    if (nums[mid] < target && nums[mid + 1] >= target) {
      return mid + 1;
    } else if (nums[mid] > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}
