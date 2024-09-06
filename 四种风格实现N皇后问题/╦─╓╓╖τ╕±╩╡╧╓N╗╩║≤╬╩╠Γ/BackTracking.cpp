#include "BackTracking.h"
bool BackTracking::IfCanPlace(int line) {
	//判断该行line的棋子位置是否合理
	for (int i = 1; i < line; ++i) {
		//从第一行开始判断
		if (chessboard[i] == chessboard[line] || (line - i) == abs(chessboard[line] - chessboard[i])){
			return false;
		}
	}
	return true;
}
void BackTracking::BackTrack(int num) {
	//num表示该放第几个棋子
	if (num > this->scale) {
		//所有棋子都放完了
		solution++;
	}
	else {
		//该棋子在所在行一列一列放尝试情况
		for (int i = 1; i <= scale; ++i) {
			//假设放在该行第i列
			chessboard[num] = i;
			if (IfCanPlace(num)){
				//如果合理
				BackTrack(num+1);
			}
			//不合理
			continue;
		}
	}

}
int BackTracking::GetResult() {
	BackTrack(1);
	return solution;
}