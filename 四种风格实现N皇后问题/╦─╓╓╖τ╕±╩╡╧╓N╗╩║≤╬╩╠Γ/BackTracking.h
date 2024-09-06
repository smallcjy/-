#pragma once
#include<cmath>
using namespace std;
class BackTracking {
private:
	int scale;
	int solution;
	//��һά�����ʾ���̵��У�ֵ��ʾ�������ӵķ���λ��
	int* chessboard;
public:
	BackTracking(int n) { scale = n; solution = 0; chessboard = new int[n + 1]; for (int i = 0; i <= scale; ++i) { chessboard[i] = 0; }
	};
	~BackTracking() { delete[]chessboard; };
	bool IfCanPlace(int);
	void BackTrack(int);
	int GetResult();
};