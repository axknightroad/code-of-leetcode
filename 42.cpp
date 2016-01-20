#include <iostream>
#include <vector>

using namespace std;

int getIndexOFHeight(int l, vector<int>& height){
  int secondHeight = -1;
  for(int i = l + 1; i < height.size(); i++){
    if (height[i] < height[i] - 1) continue;
    if (height[i] >= height[l]) return i;
    if (secondHeight = -1) secondHeight = i;
    else if (height[i] > height[secondHeight]) secondHeight = i;
  }

  return secondHeight;
}

int getTrapBetween(int l, int r, vector<int>& height) {
  if (r - l <= 1) return 0;
  int ans = 0;
  int h = height[l] <= height[r] ? height[l] : height[r];
  for(int i = l + 1; i < r; i++) {
    ans += h -height[i];
  }

  return ans;
}

int trap(vector<int>& height) {
  int l = 0;
  int r = 0;
  int ans = 0;
  
  for(int i = 0; i < height.size(); i++){
    if(height[i] > 0) {
      l = i;
      break;
    }
  }
  while (r != -1) {
    r = getIndexOFHeight(l, height);
    if (r != -1) {
      ans += getTrapBetween(l, r, height);
      l = r;
    }
  }

  return ans;
}
