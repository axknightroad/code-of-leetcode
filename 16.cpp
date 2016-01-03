#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int absMinus(int a, int b) {
  return a - b >= 0? a - b: b - a;
}

int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  int ans = nums[0] + nums[1] + nums[2];
  int closest = absMinus(ans, target);
  if (!closest) return 0;
  for(int i = 0; i < nums.size(); i++){
    int l = i + 1;
    int r = nums.size() - 1;
    while (l < r) {
      int sum = nums[i] + nums[l] + nums[r];
      int tempDistance = absMinus(sum, target);
      if (tempDistance < closest) {
	ans = sum;
	closest = tempDistance;
      }
      if (sum == target) return ans;
      else if (sum < target) l++;
      else r--;
    }
  }

  return ans;
}


int main() {
  vector<int> nums;
  nums.push_back(-1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(-4);
  int target = 1;

  int ans = threeSumClosest(nums, target);

  std::cout << ans << std::endl;
  return 0;
}
