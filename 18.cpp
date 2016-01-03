#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
  vector<vector<int> > ans;
  sort(nums.begin(), nums.end());
  if (nums.size() < 4) return ans;
 
  for(int i = 0; i < nums.size() - 3; i++) {
    while (i > 0 && nums[i] == nums[i - 1]) i++;
    
    for(int j = i + 1; j < nums.size() - 2; j++) {
      while(j > i + 1 && nums[j] == nums[j - 1]) j++;
      int l = j + 1;
      int r = nums.size() - 1;
      
      while (l < r) {
	int tempSum = nums[i]+nums[j]+nums[l]+nums[r];
	if(nums[i]+nums[j]+nums[l]+nums[r] == target) {
	  vector<int> temp{nums[i], nums[j], nums[l], nums[r]};
	  ans.push_back(temp);
	}
	if(tempSum <= target) {
	  do {
	    l++;
	  } while (nums[l] == nums[l-1] && l <= r);
	} else {
	  do {
	    r--;
	  } while (nums[r] == nums[r+1] && l <= r);
	}
      }     
    }
  }
  
  return ans;
}

int main() {
  vector<int> nums{1, 0, -1, 0, -2, 2};
  int target = 0;
  vector<vector<int> > ans = fourSum(nums, target);
  
  for (int i = 0; i < ans.size(); i++) {
    printf("(");
    for(int j = 0; j < ans[i].size(); j++){
      printf("%d ", ans[i][j]);
    }
    printf(")\n");
  }
  
  return 0;
}
    

