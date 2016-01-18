#include <vector>
#include <iostream>
#include <map>

using namespace std;

void initNumMap(map<char, int> &m1, map<char, int> &m2, map<char, int> &m3) {
  for (char c = '1'; c <= '9'; c++) {
    m1[c] = 0;
    m2[c] = 0;
    m3[c] = 0;
  }
}

bool isValidChar(char c, int m[]) {
  if (c >= '0' && c <= '9') {
    if (m[c - '1'] > 0) return false;
    else m[c -'1'] += 1;
  }

  return true;
}

bool isValidSudoku(vector<vector<char> >& board) {
  int h = board.size();
  int m1[9], m2[9], m3[9];
  
  for(int i = 0; i < h; i++) {
    memset(m1, 0, 9 * sizeof(int));
    memset(m2, 0, 9 * sizeof(int));
    memset(m3, 0, 9 * sizeof(int));
    for(int j = 0; j < h; j++) {
      if(!isValidChar(board[i][j], m1) || !isValidChar(board[j][i], m2) || !isValidChar(board[(i/3)*3 + j/3][(i%3)*3 + j%3], m3))
	return false;
    }
  }

  return true;
  
}
