#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
  int temp;
  vector<int>::iterator iter;
  bool isFirst = true;
 
  for(iter = nums.begin(); iter < nums.end();) {
    if (isFirst) {
      temp = nums[0];
      iter++;
      isFirst = false;
    } else if(nums[iter - nums.begin()] == temp) {
      iter = nums.erase(iter);
    } else {
      temp = nums[iter - nums.begin()];
      iter++;
    }
  }
  
  return nums.size();
}

int main() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(2);

  int ans = removeDuplicates(nums);
  for(int i = 0; i < nums.size(); i++)
    std::cout << nums[i] << std::endl;

  return 0;
}
