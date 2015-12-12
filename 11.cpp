/*
最优化剪枝
*/


#include <vector>
#include <iostream>

using namespace std;

int myMin(int a, int b) {
    return a < b? a : b;
}

int myMax(int a, int b) {
    return a > b? a: b;
}

int maxAreaRe(vector<int>& height, int l, int r, int max) {
    max = myMax(max, (r - l) * myMin(height[l], height[r]));
    if (r - l == 1) return max;
        if (height[l] > height[r])
            return myMax(max, maxAreaRe(height, l, r - 1, max));
        else
            return myMax(max, maxAreaRe(height, l + 1, r, max));
}

int maxArea(vector<int>& height) {
    return maxAreaRe(height, 0, height.size() - 1, 0);
}

int main() {
    vector<int> height;
    height.push_back(1);
    height.push_back(1);
    cout << maxArea(height) << endl;
    
    return 0;
}
