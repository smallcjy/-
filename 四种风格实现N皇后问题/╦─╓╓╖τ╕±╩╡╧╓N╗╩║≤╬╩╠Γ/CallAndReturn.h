#pragma once
#include<cmath>
#include<iostream>
using namespace std;
class CallandReturn {
private:
	int scale;
	int solution;
	//用一维数组表示棋盘的行，值表示该行棋子的放置位置
	int* chessboard;
public:
	CallandReturn(int scale) {
		this->scale = scale; solution = 0; chessboard = new int[scale + 1]; for (int i = 0; i <= scale; ++i) { chessboard[i] = 0; }
	}
	~CallandReturn() { delete[]chessboard; }
	bool IfcanPlace(int line);
	void callandreturn();
	int GetResult();
};