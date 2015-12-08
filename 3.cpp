#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int max = 0;
  int length = s.length();
  string result;
  int end = 0;
  int start = 0;
  
  while (start < length) {
    string nowCharString;
    result = s.substr(start, end - start + 1);
    end++;
    
    while (end < length) {
      nowCharString = s[end];
      int index = result.find(nowCharString);
      
      if(index < 0) {
	result += nowCharString;
	end++;
      } else {
	if (result.length() > max) max = result.length();
	start += index + 1;
	break;
      }    
    }
    
    if (end >= length) {
      if (result.length() > max) max = result.length();
      break;
    }
  }
  
  return max;
}
