#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min(int a, int b) {
  return a < b? a : b;
}

int findKthNum(vector<int> &nums1, vector<int> &nums2, int kth) {
  int length1 = nums1.size();
  int length2 = nums2.size();

  if (!length1) return nums2[kth - 1];
  if (!length2) return nums1[kth - 1];

  int left1 = 0, left2 = 0;
  int mid1 = 0, mid2 = 0;
  int k;

  while (1) {
    if (length1 == left1) return nums2[kth - 1];
    if (length2 == left2) return nums1[kth - 1];
    if (kth == 1) return min(nums1[left1], nums2[left2]);
    k = kth / 2;
    if (length1 - left1 < length2 - left2) {
      if (length1 - left1 < k) k = length1 - left1;
      mid1 = left1 + k - 1;
      mid2 = left2 + kth - k  - 1;
    } else {
      if (length2 - left2 < k) k = length2 - left2;
      mid2 = left2 + k - 1;
      mid1 = left1 + kth - k - 1;
    }

    if (nums1[mid1] < nums2[mid2]) {
      kth -= mid1 - left1 + 1;
      left1 = mid1 + 1;
    } else {
      kth -= mid2 - left2 + 1;
      left2 = mid2 + 1;
    }   
  }

  return -1;
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int totLength = nums1.size() + nums2.size();
  int kth = totLength / 2;


  if (totLength % 2 == 1) {
    return  (double) findKthNum(nums1, nums2, kth + 1);
  } else {
    return (double) (findKthNum(nums1, nums2, kth) +
		     findKthNum(nums1, nums2, kth + 1)) / 2;
  }

}
