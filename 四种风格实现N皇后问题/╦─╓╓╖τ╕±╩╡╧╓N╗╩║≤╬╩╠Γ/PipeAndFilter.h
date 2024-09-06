#pragma once
#include<cmath>
#include<iostream>
using namespace std;
class PipeandFilter {
private:
	int scale;
	int solution;
	//用一维数组表示棋盘的行，值表示该行棋子的放置位置
	int* chessboard;
	//过滤原始数据，用情况矩阵来表示所有可能情况
	int** filter_matrix;
	//可能的情况数量
	int probable_num;
	//备份
	int back_probable_num;
public:
	PipeandFilter(int scale) {
		this->scale = scale;
		solution = 0;
		ProbableNum(scale);
		chessboard = new int[scale + 1]; 
		for (int i = 0; i <= scale; ++i) 
		{ chessboard[i] = i; }
		filter_matrix = new int *[probable_num+1];
		for (int i =1; i <= probable_num; ++i) {
			filter_matrix[i] = new int[scale + 1];
			for (int j = 0; j <= scale; ++j) {
				filter_matrix[i][j] = 0;
			}
		}
	}
	~PipeandFilter() {
		delete[]chessboard;
		for (int i = 1; i <= probable_num; ++i) {
			delete[] filter_matrix[i];
		}
		delete[] filter_matrix;
	}
	void ProbableNum(int);
	void AllProbableInstance(int num);
	void Swap(int& a, int& b);
	bool IfcanPlace(int* chess);
	void SolutionFilter();
	int GetResult() { 
		AllProbableInstance(1);
		SolutionFilter();
		return solution; 
	};
};
