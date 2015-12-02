#include <iostream>

using namespace std;


int reverse(int x) {
  long long r = 0;
  bool isNegative = false;

  if (x < 0) {
    isNegative = true;
    x = -x;
  }

  while (x) {
    r = r * 10 + x % 10;
    x /= 10;
  }

  if (isNegative)
    r = -r;

  int max = 0x7FFFFFFF;
  int min = -max - 1;
  if (r =< max && r >= min)
    return (int) r;
  else
    return 0;
}

int main(int argc, char *argv[]) {
  int x;
  cin >> x;
  int y = reverse(x);
  cout << y << endl;
  return 0;
}
