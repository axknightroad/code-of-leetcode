#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;


string longestPalindrome(string s) {
  int max = 0;
  int start = 0;
  int length = s.size();
  for (int i = 0; i < length; i++) {
    int l = i, r = i;

    while (l > 0 && r < length - 1 && s[l - 1] == s[r + 1]) {
      l--;
      r++;
    }

    if(r - l + 1 > max) {
      start = l;
      max = r - l + 1;
    }
  }

  for(int i = 0; i < length; i++) {
    if (s[i] == s[i + 1]) {
      int l = i, r = i + 1;
      while (l > 0 && r < length - 1 && s[l - 1] == s[r + 1]) {
	l--;
	r++;
      }

      if(r - l + 1 > max) {
	start = l;
	max = r - l + 1;
      }
    }
  }
  return s.substr(start, max);
}

int main() {
  string s = "aaaabaaa";

  s = longestPalindrome(s);

  std::cout << s << std::endl;

  return 0;
}
