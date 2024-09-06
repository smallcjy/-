#include"PipeAndFilter.h"
void PipeandFilter::ProbableNum(int _scale) {
	//���п��ܵ����	
	int number = 1;
	while (_scale >= 1) {
		number *= _scale;
		_scale--;
	}
	probable_num = number;
	back_probable_num = number;
}
void PipeandFilter::AllProbableInstance(int num) {
	//�ҵ������������Ϸ����ڹ��˾�����
	//numΪҪ�ŵ����ӣ��ӵ�һö��ʼ��
	if (num == scale) {
		//��¼��Instance
		for (int i = 1; i <=scale; i++)
		{
			filter_matrix[probable_num][i] = chessboard[i];
		}
		probable_num--;
	}
	else {
		for (int i = num ; i <=scale; i++)
		{
			//ע�⣬����ֻ�õݹ鵽scale-1
			Swap(chessboard[num], chessboard[i]);
			AllProbableInstance(num + 1);
			Swap(chessboard[i], chessboard[num]);
		}
	}
}
void PipeandFilter::Swap(int& a, int& b) {
	//����
	int temp;
	temp = a;
	a = b;
	b = temp;
}
bool PipeandFilter::IfcanPlace(int* chessboard) {
	//�����Ƚ��Ƿ������������
	for (int i = 1; i <scale; ++i) {
		for (int j = i + 1; j <= scale; ++j) {
			if (chessboard[i] == chessboard[j] || abs(chessboard[i] - chessboard[j]) == (j - i)) {
				//����һ���Ҳ���б��
				return false;
			}
		}
	}
	return true;
}
void PipeandFilter::SolutionFilter() {
	//�������������������й��ˣ�ͳ����������������Щ����
	for (int k = 1; k <=back_probable_num; k++)
	{
		if (IfcanPlace(filter_matrix[k]))
		{
			//���ӿ��Է��ã������+1

			solution++;
		}
	}
}