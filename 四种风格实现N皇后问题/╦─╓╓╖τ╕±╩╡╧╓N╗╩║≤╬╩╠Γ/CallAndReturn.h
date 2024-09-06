#pragma once
#include<cmath>
#include<iostream>
using namespace std;
class CallandReturn {
private:
	int scale;
	int solution;
	//��һά�����ʾ���̵��У�ֵ��ʾ�������ӵķ���λ��
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