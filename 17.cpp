#include <iostream>
#include <vector>
#include <string>

using namespace std;


void dfs(string digits, int turn, vector<string> &letter, string lastAns, vector<string> &ans) {
  int thisDigit = digits[turn] - '0';
  if(turn >= digits.size()) ans.push_back(lastAns);
  else {
    for(int i = 0; i < letter[thisDigit].size(); i++) {
      dfs(digits, turn+1, letter, lastAns+letter[thisDigit][i], ans);
    }
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> ans;
  vector<string> letter{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  /*
  letter.push_back("0");
  letter.push_back("1");
  letter.push_back("abc");
  letter.push_back("def");
  letter.push_back("ghi");
  letter.push_back("jkl");
  letter.push_back("mno");
  letter.push_back("pqrs");
  letter.push_back("tuv");
  letter.push_back("wxyz");
  */
  if(digits.size()) dfs(digits, 0, letter, "", ans);

  return ans;
}

int main() {
  string digits = "23";
  vector<string> ans = letterCombinations(digits);
  for(int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << std::endl;
  }
  return 0;
}
