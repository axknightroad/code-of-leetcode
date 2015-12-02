#include <string>
#include <iostream>

int myAtoi(string str) {

  int length = str.length();
  long long x = 0;
  bool isNegative = false;
  bool start = false;
  int max = 0x7FFFFFFF;
  int min = -max - 1;
  for (int i = 0; i < length; i++) {
    char temp = str[i];
    if(!start) {
         if (str[i] >= '0' && str[i] <= '9') {
	   x = str[i] - '0';
	   start = true;
	 } else if(str[i] == '-' ) {
	   isNegative = true;
	   start = true;
	 } else if(str[i] == '+'){
	   start = true;
	 } else if(str[i] == ' ') {
	   continue;
	 } else {
	   return 0;
	 }
    } else {
      if (temp >= '0' && temp <= '9') {
	x = x * 10 + (temp - '0');
	if (x - 1 > max) {
	  break;
	}
      } else {
	 break;
      }
    }
  }

  if(isNegative) {
    x = -x;
  }


  if (x > max ) {
    return max;
  } else if (x < min){
    return min;
  }

  return x;
}
