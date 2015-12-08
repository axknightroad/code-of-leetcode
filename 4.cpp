#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minNum(int a, int b) {
  return a <= b? a: b;
}
    
int getKth(vector<int>& nums1, vector<int>& nums2, int k) {
  int l1 = nums1.size();
  int l2 = nums2.size();
  int start1 = 0, start2 = 0;
  int end1 = l1 - 1;
  int end2 = l2 - 1;
  int overFlag = 0;
  int now1 = 0;
  int now2 = 0;
        
  if (!l1) {
    return nums2[k];
  }
        
  if (!l2) {
    return nums1[k];
  }
        
  if (l1 == 1) {
    overFlag = 1;
  }
        
  if(l2 == 1) {
    overFlag = 2;
  }
        
  while (start1 <= end1 && start2 <= end2 && !overFlag) {
    now1 = start1 + (end1 - start1) / 2;
    now2 = start2 + (end2 - start2) / 2;
            
    if (now1 + now2 + 1 == k) {
      if (nums1[now1] >= nums2[now2] && nums1[now1] <= nums2[now2 + 1])
	return nums1[now1];
      else if (nums1[now1] <= nums2[now2] && nums1[now1 + 1] >= nums2[now2])
	return nums2[now2];
    }
            
    if (now1 + now2 + 1 > k) {
      if (nums1[now1] >= nums2[now2]) {
	end1 = now1 - 1;
      } else {
	end2 = now2 - 1;
      }
    } else {
      if (nums1[now1 + 1] <= nums2[now2 + 1]) {
	start1 = now1 + 1;
      } else {
	start2 = now2 + 1;
      }
    }
            
    if (end1 < 0) {
      return nums2[k];
    }
            
    if (end2 < 0) {
      return nums1[k];
    }
            
    if (start1 > end1 || start1 == l1 - 1) {
      now1 = l1 - 1;
      overFlag = 1;
    } else if (start2 > end2 || start2 == l2 -1) {
      now2 = l2 -1;
      overFlag = 2;
    }
  }
        
  if (overFlag == 1) {
    now2 = k - 1 - now1;
    if (nums2[now2] >= nums1[now1])
      return nums2[now2];
    else if (nums2[now2 + 1] >= nums1[now1])
      return nums1[now1];
    else return nums2[now2 + 1];
            
  } else if (overFlag == 2) {
    now1 = k - 1 - now2;
    if (nums1[now1] >= nums2[now2])
      return nums1[now1];
    else if (nums1[now1 + 1] >= nums2[now2])
      return nums2[now2];
    else return nums1[now1 + 1];
  }
        
  return 0;
}
    
    
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  if (nums1.size() == 1 && nums2.size() == 1)
    return (double) (nums1[0] + nums2[0]) / 2;
        
  int length = nums1.size() + nums2.size();
        
  if  (length% 2 == 1) {
    return (double) getKth(nums1, nums2, length/2);
  } else {
    return (double) (getKth(nums1, nums2, length/2) + getKth(nums1, nums2 ,length/2 - 1)) / 2;
  }
}




