#include <string>
#include <iostream>

using namespace std;

int romanToInt(string s) {
  int value = 0;
  for (int i = 0; i < s.size(); i++) {
    switch (s[i]) {
    case 'M':
      value += 1000;
      break;
      
    case 'D':
      value += 500;
      break;
      
    case 'C':
      if (s[i+1] == 'M' || s[i+1] == 'D')
	value -= 100;
      else
	value += 100;
      break;
      
    case 'L':
      value += 50;
      break;
      
    case 'X':
      if (s[i+1] == 'C' || s[i+1] =='L')
	value -= 10;
      else
	value += 10;
      break;
      
    case 'V':
      value += 5;
      break;
      
    case 'I':
      if(s[i+1] == 'X' || s[i+1] == 'V')
	value -= 1;
      else
	value += 1;
      break;
      
    default:
      break;
    }
  }

  return value;
}
