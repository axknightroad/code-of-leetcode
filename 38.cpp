#include <string>
#include <vector>
#include <stack>
using namespace std;

string iTos(int n) {
  string ans;
  string ts;
  while (n) {
    int td = n % 10;
    ts = ans;
    ans = td + '0';
    ans += ts;
    n /= 10;
  }
  return ans;
}

string countAndSay(int n) {
  if (n == 1) return "1";
  string last = countAndSay(n-1);
  string ans;
  int count = 0;
  char c = last[0];
  for(int i = 0; i < last.size(); i++) {
    if (last[i] == c) {
      count++;
    } else {
      ans += iTos(count);
      ans += c;
      count = 1;
      c = last[i];
    }
    if(i == last.size() - 1) {
      ans += iTos(count);
      ans += c;
    }
  }

  return ans;
}
