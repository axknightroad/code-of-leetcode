#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  string result;
  if (!strs.size()) return result;
  if (strs.size() == 1) return strs[0];
  int max = 0;
  for (max = 0; max < strs[0].size() && max < strs[1].size(); max++) {
    if (strs[0][max] != strs[1][max]) {
      if (!max) return result;
      break;
    }
  }
          
  max--;
          
  for (int i = 2; i< strs.size(); i++) {
    //if (!strs[i].size()) return "";
    if (max >= strs[i].size()) max = strs[i].size() - 1;
    while (max >= 0 && strs[i][max] != strs[0][max])
      max--;
  }
              
  if (max < 0) return result;
        
  result = strs[0].substr(0, max+1);
  return result;
        
}

int main() {
  vector<string> strs;
  string s1("c");
  string s2("c");
  strs.push_back(s1);
  strs.push_back(s2);
  string result = longestCommonPrefix(strs);
  cout << result << endl;

  return 0;
}
