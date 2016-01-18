#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct origin {
  int x;
  int y;
};

int subBoxIndex(int i, int j) {
  return i/3*3 + j/3;
}

bool reSolve(vector<vector<char> >& board, stack<origin> &dotStack, int row[9][9], int column[9][9], int subBox[9][9]) {
  if (!dotStack.size()) return true;
  origin o = dotStack.top();
  dotStack.pop();
  for (int i = 0; i < 9; i++) {
    if(!row[o.x][i] && !column[o.y][i] && !subBox[subBoxIndex(o.x, o.y)][i]) {
      row[o.x][i] = 1;
      column[o.y][i] = 1;
      subBox[subBoxIndex(o.x, o.y)][i] = 1;
      board[o.x][o.y] = i + '1';
      if(reSolve(board, dotStack, row, column, subBox)) return true;
      row[o.x][i] = 0;
      column[o.y][i] = 0;
      subBox[subBoxIndex(o.x, o.y)][i] = 0;
      board[o.x][o.y] = '.';
    }
  }
  dotStack.push(o);
  return false;
}

void solveSudoku(vector<vector<char> >& board) {
  stack<origin> dotStack;
  int row[9][9], column[9][9], subBox[9][9];
  memset(row, 0, sizeof(int) * 81);
  memset(column, 0, sizeof(int) * 81);
  memset(subBox, 0, sizeof(int) * 81);

  // 预处理
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9 ; j++) {
      if (board[i][j] == '.') {
	origin o;
	o.x = i;
	o.y = j;
	dotStack.push(o);
      } else {
	int d = board[i][j] - '1';
	row[i][d] = 1;
	column[j][d] = 1;
	subBox[subBoxIndex(i,j)][d] = 1;
      }
    }
  }
  
  reSolve(board, dotStack, row, column, subBox);
  
}
