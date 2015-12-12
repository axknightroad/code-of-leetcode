bool isPalindrome(int x) {
  if (x < 10 && x >= 0) return true;
  if (x < 0 || !(x % 10) ) return false;
  int y = 0;
  while (x >= y) {
    if (x == y || x / 10 == y)  return true;
    y = y * 10 + x % 10;
    x /= 10;
  }
    
  return false;
}
