#include <string>
#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
  if(!needle.size()) return 0;
  if (needle.size() > haystack.size()) return -1;
  for(int i = 0; i < haystack.size() - needle.size() + 1; i++){
    for(int j = 0; j < needle.size(); j++) {
      if (i + j > haystack.size() - 1 || haystack[i+j] != needle[j]) {
	break;
      } else if (j == needle.size() - 1) {
	return i;
      }
    }
  }
  return -1;
}

int main() {
  int ans = strStr("abcd", "abdd");
  std::cout << ans << std::endl;
  return 0;
}
