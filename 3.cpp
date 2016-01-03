/*
 question：Longest Substring Without Repeating Characters
 tag: string

 result表示当前不重复子串
 从 i = 0 开始遍历s的每一个字符

 当 s[i] 和 result 不重复时，把 s[i] 加到 result 结尾

 当 s[i] 与 result[k] 重复时, 可知 result[k+1] 至 result 结尾都和 s[i] 不重复
 则不必重复判断该区间内字符串，result.substr(k)为新的不重复子串

 时间复杂度为 O(n)
 */

#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int max = 0;  //最大不重复子串长度
    string result; //当前不重复子串

    for (int i = 0; i< s.length(); i++) {
        int index = result.find(s[i]); //查找s[i]是否重复
        if (index >= 0) { //重复位置为index，则从index＋1处起不重复, 可从index＋1处取子串
            max = max > result.length()? max: result.length();
            result = result.substr(index + 1);
        }
        result += s[i];
    }

    max = max > result.length()? max: result.length();
    return max;
}

int main() {
    string s = "abaa";
    int max = lengthOfLongestSubstring(s);
    cout<<max<<endl;
}
