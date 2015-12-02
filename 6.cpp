#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

string convert(string s, int numRows) {
  string result(s);
  if (numRows > 1) {
    int numEveryTurn = 2 * numRows - 2;
    int length = s.length();
    int numTurns = length / numEveryTurn;
    int remainder = length % numEveryTurn;
    int k = 0, nowRemaind = 1;
    int numNotHaveRem = length - remainder;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numTurns; j++){
	result[k++] = s[j * numEveryTurn + i];
	if (i > 0 && i < numRows - 1) {
	  result[k++] = s[(j + 1) * numEveryTurn -i];
	}
      }
      if (remainder > i) {
	result[k++] = s[numNotHaveRem + i];
      }
      if (remainder > numEveryTurn - i && i < numRows - 1) {
	result[k++] = s[length - nowRemaind];
	nowRemaind += 1;
      }
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  string s;
  int numRows;
  cin >> s >> numRows;
  cout << convert(s, numRows) << endl;
  return 0;
}
