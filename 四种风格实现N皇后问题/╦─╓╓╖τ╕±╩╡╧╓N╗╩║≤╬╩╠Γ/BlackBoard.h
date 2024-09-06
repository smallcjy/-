#pragma once
#include<iostream>
#include<thread>
#include<cmath>
#include<vector>
using namespace std;
class Blackboard {
private:
	int scale;
	int solution;
	//��һά�����ʾ���̵��У�ֵ��ʾ�������ӵķ���λ��
	int* blackboard_line;
	//����ڰ�
	int** blackboard;
	//���ܵ��������
	int probable_num;
	//����
	int back_probable_num;
public:
	//��ͬģ��Module�Ժڰ���в���
	Blackboard(int scale) {
		this->scale = scale;
		solution = 0;
		NumModule(scale);
		blackboard_line = new int[scale + 1];
		for (int i = 0; i <= scale; ++i)
		{
			blackboard_line[i] = i;
		}
		blackboard = new int* [probable_num + 1];
		for (int i = 1; i <= probable_num; ++i) {
			blackboard[i] = new int[scale + 1];
			for (int j = 0; j <= scale; ++j) {
				blackboard[i][j] = 0;
			}
		}
	}
	~Blackboard() {
		delete[]blackboard_line;
		for (int i = 1; i <= probable_num; ++i) {
			delete[] blackboard[i];
		}
		delete[] blackboard;
	}
	void NumModule(int);
	void AllInstanceModule(int num);
	void SwapModule(int& a, int& b);
	bool IfcanPlaceModule(int* chess);
	//���Ĵ��룬��������߳�ģ��Modulesͬʱ�Ժڰ���в���
	void MultiThreadModules();
	//�����߳�ʵ�ֵĹ���ģ��
	void ThreadFuncModule(int id);
	int GetResult() {
		//�ڰ���д�����п��ܵ����
		AllInstanceModule(1);
		//���߳�ģ�����
		MultiThreadModules();
		return solution;
	};

};