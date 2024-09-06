#include"PipeAndFilter.h"
void PipeandFilter::ProbableNum(int _scale) {
	//所有可能的情况	
	int number = 1;
	while (_scale >= 1) {
		number *= _scale;
		_scale--;
	}
	probable_num = number;
	back_probable_num = number;
}
void PipeandFilter::AllProbableInstance(int num) {
	//找到所有情况的组合放置在过滤矩阵中
	//num为要放的棋子，从第一枚开始放
	if (num == scale) {
		//记录该Instance
		for (int i = 1; i <=scale; i++)
		{
			filter_matrix[probable_num][i] = chessboard[i];
		}
		probable_num--;
	}
	else {
		for (int i = num ; i <=scale; i++)
		{
			//注意，这里只用递归到scale-1
			Swap(chessboard[num], chessboard[i]);
			AllProbableInstance(num + 1);
			Swap(chessboard[i], chessboard[num]);
		}
	}
}
void PipeandFilter::Swap(int& a, int& b) {
	//交换
	int temp;
	temp = a;
	a = b;
	b = temp;
}
bool PipeandFilter::IfcanPlace(int* chessboard) {
	//两两比较是否该棋局情况成立
	for (int i = 1; i <scale; ++i) {
		for (int j = i + 1; j <= scale; ++j) {
			if (chessboard[i] == chessboard[j] || abs(chessboard[i] - chessboard[j]) == (j - i)) {
				//不在一列且不在斜线
				return false;
			}
		}
	}
	return true;
}
void PipeandFilter::SolutionFilter() {
	//过滤器，对情况矩阵进行过滤，统计所有情况的棋局哪些成立
	for (int k = 1; k <=back_probable_num; k++)
	{
		if (IfcanPlace(filter_matrix[k]))
		{
			//棋子可以放置，情况数+1

			solution++;
		}
	}
}