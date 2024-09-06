#include"BlackBoard.h"
void Blackboard::NumModule(int _scale) {
	//所有可能的情况	
	int number = 1;
	while (_scale >= 1) {
		number *= _scale;
		_scale--;
	}
	probable_num = number;
	back_probable_num = number;
}
void Blackboard::AllInstanceModule(int num) {
	//找到所有情况的组合写在黑板上
	//num为要放的棋子，从第一枚开始放
	if (num == scale) {
		//记录该Instance
		for (int i = 1; i <= scale; i++)
		{
			blackboard[probable_num][i] = blackboard_line[i];
		}
		probable_num--;
	}
	else {
		for (int i = num; i <= scale; i++)
		{
			//注意，这里只用递归到scale-1
			SwapModule(blackboard_line[num], blackboard_line[i]);
			AllInstanceModule(num + 1);
			SwapModule(blackboard_line[i], blackboard_line[num]);
		}
	}
}
void Blackboard::SwapModule(int& a, int& b) {
	//交换
	int temp;
	temp = a;
	a = b;
	b = temp;
}
bool Blackboard::IfcanPlaceModule(int* blackboard_line) {
	//两两比较是否该棋局情况成立
	for (int i = 1; i < scale; ++i) {
		for (int j = i + 1; j <= scale; ++j) {
			if (blackboard_line[i] == blackboard_line[j] || abs(blackboard_line[i] - blackboard_line[j]) == (j - i)) {
				//不在一列且不在斜线
				return false;
			}
		}
	}
	return true;
}
void Blackboard::ThreadFuncModule(int id) {
	//id为线程标识符
	for (int i = 1; i <= back_probable_num; ++i) {
		if (blackboard[i][1] == id) {
			//以第一行棋子作为各线程需要处理的情况
			if (IfcanPlaceModule(blackboard[i])) {
				solution++;
			}
		}
	}
}
void Blackboard::MultiThreadModules() {
	//创建线程模块并启动
	//创建线程向量
	const int threadNum = scale;
	vector<thread> threadModules;
	for (int i = 1; i <=threadNum; ++i) {
		// 使用成员函数作为线程入口点时，需要传递类的实例指针和成员函数参数
		threadModules.push_back(thread(&Blackboard::ThreadFuncModule,this,i));
	}
	//等待所有线程完成
	for (thread& thread : threadModules) {
		thread.join();
	}
	return;
}