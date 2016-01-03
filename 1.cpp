/*
二分查找
*/



#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result(2);
    vector<int> copyNums(nums);
    int length = nums.size();
    int indexMin = 0, indexMax = length - 1;
    int indexTemp = 0;
    int value1 = 0, value2 = 0;
    int index1, index2;
    bool isOver = false;
    vector<int>::iterator it;
    //printf("num[0] = %i, num[1] = %i\n",nums[0], nums[1]);
    sort(nums.begin(), nums.end());
    //printf("num[0] = %i, num[1] = %i\n",nums[0], nums[1]);
    for(int i = 0; i < length; i++) {
        indexMin = i + 1;
        indexMax = length - 1;
        //printf("num[i] = %i, num[indexMin] = %i\n",nums[i], nums[indexMin]);
        if (nums[i] + nums[indexMin] == target) {
            value1 = nums[i];
            value2 = nums[indexMin];
            isOver = true;
            break;
        } else if (nums[i] + nums[indexMax] == target){
            value1 = nums[i];
            value2 = nums[indexMax];
            isOver = true;
            break;
        }
        while (nums[i] + nums[indexMin] < target && nums[i] + nums[indexMax] > target && indexMin < indexMax && !isOver) {
            indexTemp = (indexMin + indexMax) / 2;
            if (nums[i] + nums[indexTemp] == target) {
                value1 = nums[i];
                value2 = nums[indexTemp];
                isOver = true;
                break;
            } else if (nums[i] + nums[indexTemp] < target) {
                indexMin = indexTemp + 1;
                if (nums[i] + nums[indexMin] == target) {
                    value1 = nums[i];
                    value2 = nums[indexMin];
                    isOver = true;
                    break;
                }
            } else {
                indexMax = indexTemp - 1;
                if (nums[i] + nums[indexMax] == target){
                    value1 = nums[i];
                    value2 = nums[indexMax];
                    isOver = true;
                    break;
                }
            }
        }
        if (isOver) {
            break;
        }
    }

    it = find(copyNums.begin(), copyNums.end(), value1);
    index1 = it - copyNums.begin();
    it = find(copyNums.begin(), copyNums.end(), value2);
    index2 = it - copyNums.begin();

    if (index1 == index2) {
        it = find(copyNums.begin() + index1 + 1, copyNums.end(), value2);
        index2 = it - copyNums.begin();
    } else if (index1 > index2) {
        int tempIndex = index1;
        index1 = index2;
        index2 = tempIndex;
    }

    result[0] = index1 +1;
    result[1] = index2 +1;

    return result;
}

int main() {
    vector<int> nums;
    int temp;
    int length;
    int target;
    printf("input length:\n");
    scanf("%i", &length);
    for (int i = 0; i < length; i++) {
        printf("input nums:\n");
        scanf("%i", &temp);
        nums.push_back(temp);
    }

    printf("input target:\n");
    scanf("%i", &target);

    vector<int> result = twoSum(nums, target);
    for (int i = 0; i < 2; i++) {
        printf("%i ", result[i]);
    }
    printf("\n");
    return 0;
}
