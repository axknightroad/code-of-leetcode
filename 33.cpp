#include <vector>
#include <iostream>

using namespace std;

int biSearch(vector<int> &nums, int target, int s, int e) {
  int ans = -1;
  if (nums[s] == target) return s;
  if (nums[e] == target) return e;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (nums[mid] == target) {
      ans = mid;
      break;
    } else if (nums[mid] > target) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }

  return ans;
}

int search(vector<int>& nums, int target) {
  int ans;
  int end = 0;
  int l = 0, r = nums.size() - 1;
  if(!nums.size()) return -1;
  if (nums[l] < nums[r]) end = r;
  else if(nums[l] > nums[l+1]) end = l;
  else {
    int mid;
    while (l <= r && l >=0 && r < nums.size()) {
      mid = l + (r - l) / 2;
      if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
	end = mid;
      else if (nums[mid] > nums[l])
	l = mid + 1;
      else
	r = mid - 1;
    }
  }

  if (target > nums[0]) ans = biSearch(nums, target, 0, end);
  else ans = biSearch(nums, target, end + 1, nums.size()-1);

  return ans;
}

int main() {
  vector<int> nums;
  int target = 0;
  
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(7);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);

  int ans = search(nums, target);
  cout << ans << endl;
}
