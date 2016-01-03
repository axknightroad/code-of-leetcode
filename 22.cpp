#include <iostream>
#include <vector>
#include <string>

using namespace std;


void dfs(vector<string> &ans, string res, int leftNum, int rightNum, int n) {
  if (leftNum == n && rightNum == n) {
    ans.push_back(res);
  } else if(leftNum >= rightNum && leftNum <= n) {
    dfs(ans, res+'(', leftNum+1, rightNum, n);
    dfs(ans, res+')', leftNum, rightNum+1, n);
  }
}


vector<string> generateParenthesis(int n) {
  vector<string> ans;
  dfs(ans, "(", 1, 0, n);
  return ans;
}


int main(int argc, char *argv[]) {
  vector<string> ans = generateParenthesis(3);
  
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << std::endl;
  }
  
  return 0;
}

