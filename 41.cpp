#include <vector>

int firstMissingPositive(vector<int>& nums) {
  int n = nums.size();
  nums.push_back(0);
  int lastMatch = 0;
  
  for (int i = 0; i < n + 1; i++) {
    if (nums[i] == i|| nums[i] < 0 || nums[i] > n + 1) continue;
    bool over = false;
    int now = nums[i];
    while (!over) {
      if (nums[now] == now || nums[now] < 0 || nums[now] > n + 1) over = true;
      int temp = nums[now];
      nums[now] = now;
      now = temp;
    }
    while (nums[lastMatch + 1] == lastMatch + 1) {
      lastMatch++;
    }
  }
  
  return lastMatch + 1;
}
