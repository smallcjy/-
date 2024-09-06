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
	//用一维数组表示棋盘的行，值表示该行棋子的放置位置
	int* blackboard_line;
	//共享黑板
	int** blackboard;
	//可能的情况数量
	int probable_num;
	//备份
	int back_probable_num;
public:
	//不同模块Module对黑板进行操作
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
	//核心代码，创建多个线程模块Modules同时对黑板进行操作
	void MultiThreadModules();
	//各个线程实现的功能模块
	void ThreadFuncModule(int id);
	int GetResult() {
		//黑板上写下所有可能的情况
		AllInstanceModule(1);
		//多线程模块计算
		MultiThreadModules();
		return solution;
	};

};