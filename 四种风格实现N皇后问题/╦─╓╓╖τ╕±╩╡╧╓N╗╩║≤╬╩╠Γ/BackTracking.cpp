#include "BackTracking.h"
bool BackTracking::IfCanPlace(int line) {
	//�жϸ���line������λ���Ƿ����
	for (int i = 1; i < line; ++i) {
		//�ӵ�һ�п�ʼ�ж�
		if (chessboard[i] == chessboard[line] || (line - i) == abs(chessboard[line] - chessboard[i])){
			return false;
		}
	}
	return true;
}
void BackTracking::BackTrack(int num) {
	//num��ʾ�÷ŵڼ�������
	if (num > this->scale) {
		//�������Ӷ�������
		solution++;
	}
	else {
		//��������������һ��һ�зų������
		for (int i = 1; i <= scale; ++i) {
			//������ڸ��е�i��
			chessboard[num] = i;
			if (IfCanPlace(num)){
				//�������
				BackTrack(num+1);
			}
			//������
			continue;
		}
	}

}
int BackTracking::GetResult() {
	BackTrack(1);
	return solution;
}