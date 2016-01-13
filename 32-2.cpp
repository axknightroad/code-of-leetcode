#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int max(int a, int b) {
  return a > b? a: b;
}

int longestValidParentheses(string s) {
  stack<int> lefts;
  int lastMatch = 0;
  int max = 0;
  
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ')'){
      int thisLongest = 0;
      if (lefts.empty()) lastMatch = i+1;
      else {
	int lastLeft = lefts.top();
	lefts.pop();
	if (lefts.empty()) thisLongest = i - lastMatch + 1;
	else thisLongest = i - lefts.top();
      }
      max = myMax(max, thisLongest);
    }
    else {
      lefts.push(i);
    }
  }
  
  return max;
}
