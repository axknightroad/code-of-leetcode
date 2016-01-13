#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int myMax(int a ,int b) {
  return a > b? a: b;
}

int longestValidParentheses(string s) {
  vector<int> d(s.size(), 0); //d[i] 为以i为结尾的最长有效字符串
  int max = 0;
  
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == ')'){
      int l = i - d[i-1] - 1;
      if (l >= 0 && s[l] == '(') {
	d[i] = i - l + 1;
      }
      if (l > 0) d[i] += d[l-1];
      max = myMax(max, d[i]);
    }
  }

  return max;
}

int main() {
  string s = "()(()(((((())())((()))(()((())()(()()(()((()))()))))())))))())()())))(()()()())((()()()))()(()(()))())(((()))())(()((()))(()(()))()";
  int ans = longestValidParentheses(s);
  std::cout << ans << std::endl;
}
