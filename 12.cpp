#include <string>
#include <iostream>

using namespace std;

string intToRoman(int num) {
  int numKiloBit = num / 1000;
  num = num % 1000;
  int numHectoBit = num / 100;
  num = num % 100;
  int numDecaBit = num / 10;
  num = num % 10;
  
  string result;
  
  // 处理千位
  while (numKiloBit > 0) {
    result += "M";
    numKiloBit--;
  }
  
  // 处理百位
  if (numHectoBit == 9) {
    result += "CM";
    numHectoBit -= 9;
  } else if (numHectoBit >= 5) {
    result += "D";
    numHectoBit -= 5;
  } else if (numHectoBit == 4) {
    result += "CD";
    numHectoBit -= 4;
  }
  
  while (numHectoBit > 0) {
    result += "C";
    numHectoBit--;
  }
  
  // 处理十位
  if (numDecaBit == 9) {
    result += "XC";
    numDecaBit -= 9;
  } else if (numDecaBit >= 5) {
    result += "L";
    numDecaBit -= 5;
  } else if (numDecaBit == 4) {
    result += "XL";
    numDecaBit -= 4;
  }
  
  while (numDecaBit > 0) {
    result += "X";
    numDecaBit--;
  }
  
  // 处理个位
  if (num == 9) {
    result += "IX";
    num -= 9;
  } else if (num >= 5) {
    result += "V";
    num -= 5;
  } else if (num == 4) {
    result += "IV";
    num -= 4;
  }
  
  while (num > 0) {
    result += "I";
    num--;
  }
  
  return result;
}

int main() {
  int num = 1999;
  string s;
  s = intToRoman(num);
  cout << s << endl;
  return 0;
}
