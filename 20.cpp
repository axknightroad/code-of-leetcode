#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatch(char a, char b) {
  bool ans = false;
  switch (a) {
    case '[':
      if(b == ']') ans = true;
      break;
    case '(':
      if(b == ')') ans = true;
      break;
    case '{':
      if(b == '}') ans = true;
      break;
  }

  return ans;
}

bool isValid(string s) {
  stack<char> symbolStack;

  for (int i = 0; i < s.size(); i++) {
    switch (s[i]) {
      case '[':
      case '{':
      case '(': 
	symbolStack.push(s[i]);
	break;

      case ')':
      case '}':
      case ']': 
	if (!symbolStack.size() || !isMatch(symbolStack.top(), s[i])) return false;
	else symbolStack.pop();
	break;

      default:
	break;
    }
  }

  if (!symbolStack.size()) return true;
  else return false;
}

int main() {
  string s = "[]";
  string ans = isValid(s)? "yes" : "no";
  cout << ans << endl;
  return 0;
}
