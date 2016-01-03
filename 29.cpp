#include <string>
#include <iostream>
#include <vector>

#define MAX_INT 0x8FFFFFFF

using namespace std;

long long multiply(int x, int y) {
  long long ans = 0;
  for(int i = 0; i < y; i++)
    ans += x;
  return ans;
}

int divide(int dividend, int divisor) {
  long long ans = 0;
  bool isNegative = false;
  vector<int> divisor10;
  long long max = 0;
  long long dividendL = dividend;
  long long divisorL = divisor;
  
  if (dividendL < 0) {
    isNegative = !isNegative;
    dividendL = -dividendL;
  }
  if (divisorL < 0) {
    isNegative = !isNegative;
    divisorL = -divisorL;
  }

  if(dividendL < divisorL) return 0;
  
  max = divisorL;
  
  while (dividendL > max) {
    divisor10.push_back(max);
    max = multiply(max, 10);
  }
  
  for(int i = divisor10.size() - 1; i >=0 ; i--){
    ans = multiply(ans, 10);
    while(dividendL - divisor10[i] > 0) {
      dividendL -= divisor10[i];
      ans++;
    }
  }

  if (ans > MAX_INT && !isNegative) return MAX_INT;
  if (ans > MAX_INT + 1 && isNegative) return - MAX_INT - 1;

  return isNegative? -ans: ans;
}

int main() {
  int a,b;
  cin >> a >> b;
  int ans = divide(a,b);
  std::cout << ans << std::endl;
}
