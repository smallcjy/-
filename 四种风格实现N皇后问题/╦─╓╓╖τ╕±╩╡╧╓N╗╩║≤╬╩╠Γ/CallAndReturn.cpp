#include"CallAndReturn.h"
bool CallandReturn::IfcanPlace(int line) {
	//判断该行line的棋子位置是否合理
	if (line > scale) {
		return false;
	}
	for (int i = 1; i < line; ++i) {
		//从第一行开始判断
		if (chessboard[i] == chessboard[line] || (line - i) == abs(chessboard[line] - chessboard[i])) {
			return false;
		}
	}
	return true;
}
void CallandReturn::callandreturn() {
	//从第一个棋子开始放
	int number = 1;
	while (number >= 1 && number <= scale) {
		//在该行逐列尝试放，先从(number,1)尝试放
		chessboard[number]++;
		if (chessboard[number] > scale) {
			//该行已经全部尝试过了
			chessboard[number] = 0;
			//再回到上一行
			number--;
			continue;
		}
		//判断该行现在尝试的情况是否合理
		while (IfcanPlace(number) == false){
			//该位置不合理，而且后面还能尝试
			chessboard[number]++;
		}
		//此时要么找到合理的位置，要么超出范围，即本行不能放置
		if (chessboard[number] <=scale) {
			//找到合理位置
			if (number == scale) {
				//到最后一行
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
					//下一个位置
				}
			}
			else {
				//没到最后一行，进入下一行
				number++;
			}
		}
		else {
			//没有找到合理位置,本行置0，回到上一行
			chessboard[number] = 0;
			number--;
		}

	}
}
int CallandReturn::GetResult() {
	this->callandreturn();
	return solution;
}