#include"CallAndReturn.h"
bool CallandReturn::IfcanPlace(int line) {
	//�жϸ���line������λ���Ƿ����
	if (line > scale) {
		return false;
	}
	for (int i = 1; i < line; ++i) {
		//�ӵ�һ�п�ʼ�ж�
		if (chessboard[i] == chessboard[line] || (line - i) == abs(chessboard[line] - chessboard[i])) {
			return false;
		}
	}
	return true;
}
void CallandReturn::callandreturn() {
	//�ӵ�һ�����ӿ�ʼ��
	int number = 1;
	while (number >= 1 && number <= scale) {
		//�ڸ������г��Էţ��ȴ�(number,1)���Է�
		chessboard[number]++;
		if (chessboard[number] > scale) {
			//�����Ѿ�ȫ�����Թ���
			chessboard[number] = 0;
			//�ٻص���һ��
			number--;
			continue;
		}
		//�жϸ������ڳ��Ե�����Ƿ����
		while (IfcanPlace(number) == false){
			//��λ�ò��������Һ��滹�ܳ���
			chessboard[number]++;
		}
		//��ʱҪô�ҵ������λ�ã�Ҫô������Χ�������в��ܷ���
		if (chessboard[number] <=scale) {
			//�ҵ�����λ��
			if (number == scale) {
				//�����һ��
				//for (int i = 1; i <= scale; ++i) {
				//	cout << chessboard[i] << " ";
				//}
				//cout << endl;
				solution++;
				if (chessboard[number] == scale) {
					chessboard[number] = 0;
					number--;
				}
				else {
					//��һ��λ��
				}
			}
			else {
				//û�����һ�У�������һ��
				number++;
			}
		}
		else {
			//û���ҵ�����λ��,������0���ص���һ��
			chessboard[number] = 0;
			number--;
		}

	}
}
int CallandReturn::GetResult() {
	this->callandreturn();
	return solution;
}