#include"BlackBoard.h"
void Blackboard::NumModule(int _scale) {
	//���п��ܵ����	
	int number = 1;
	while (_scale >= 1) {
		number *= _scale;
		_scale--;
	}
	probable_num = number;
	back_probable_num = number;
}
void Blackboard::AllInstanceModule(int num) {
	//�ҵ�������������д�ںڰ���
	//numΪҪ�ŵ����ӣ��ӵ�һö��ʼ��
	if (num == scale) {
		//��¼��Instance
		for (int i = 1; i <= scale; i++)
		{
			blackboard[probable_num][i] = blackboard_line[i];
		}
		probable_num--;
	}
	else {
		for (int i = num; i <= scale; i++)
		{
			//ע�⣬����ֻ�õݹ鵽scale-1
			SwapModule(blackboard_line[num], blackboard_line[i]);
			AllInstanceModule(num + 1);
			SwapModule(blackboard_line[i], blackboard_line[num]);
		}
	}
}
void Blackboard::SwapModule(int& a, int& b) {
	//����
	int temp;
	temp = a;
	a = b;
	b = temp;
}
bool Blackboard::IfcanPlaceModule(int* blackboard_line) {
	//�����Ƚ��Ƿ������������
	for (int i = 1; i < scale; ++i) {
		for (int j = i + 1; j <= scale; ++j) {
			if (blackboard_line[i] == blackboard_line[j] || abs(blackboard_line[i] - blackboard_line[j]) == (j - i)) {
				//����һ���Ҳ���б��
				return false;
			}
		}
	}
	return true;
}
void Blackboard::ThreadFuncModule(int id) {
	//idΪ�̱߳�ʶ��
	for (int i = 1; i <= back_probable_num; ++i) {
		if (blackboard[i][1] == id) {
			//�Ե�һ��������Ϊ���߳���Ҫ��������
			if (IfcanPlaceModule(blackboard[i])) {
				solution++;
			}
		}
	}
}
void Blackboard::MultiThreadModules() {
	//�����߳�ģ�鲢����
	//�����߳�����
	const int threadNum = scale;
	vector<thread> threadModules;
	for (int i = 1; i <=threadNum; ++i) {
		// ʹ�ó�Ա������Ϊ�߳���ڵ�ʱ����Ҫ�������ʵ��ָ��ͳ�Ա��������
		threadModules.push_back(thread(&Blackboard::ThreadFuncModule,this,i));
	}
	//�ȴ������߳����
	for (thread& thread : threadModules) {
		thread.join();
	}
	return;
}