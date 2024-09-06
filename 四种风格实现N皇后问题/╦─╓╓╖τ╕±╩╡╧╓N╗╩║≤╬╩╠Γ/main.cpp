#include <iostream>
#include<string>
#include<fstream>
#include <sstream>
#include<vector>
#include<ctime>
#include <cstdlib>
#include <chrono>
#include <cstdlib>
using namespace std;
#include"BackTracking.h"
#include"CallAndReturn.h"
#include"PipeAndFilter.h"
#include"BlackBoard.h"
// Author:李文博（202130480749）软2
// 要求：代码注释良好
//全局变量，用于存储四种算法不同规模的结果
vector<int> results1;
vector<int> results2;
vector<int> results3;
vector<int> results4;
//全局变量 存储运行时间
vector<double> time1;
vector<double> time2;
vector<double> time3;
vector<double> time4;
void PipeAndFilter(int scale, vector<int>& result)
{
	PipeandFilter method(scale);
	int solution = method.GetResult();
	//结果存放在result中
	results1.push_back(solution);
}
void CallAndReturn(int scale, vector<int>& result)
{
	CallandReturn method(scale);
	int solution = method.GetResult();
	//结果存放在result中
	results2.push_back(solution);
}
void Backtracking(int scale,vector<int> &result)
{
	BackTracking method(scale);
	int solution = method.GetResult();
	//结果存放在result中
	results3.push_back(solution);
}
void BlackBoard(int scale, vector<int>& result) {
	Blackboard method(scale);
	int solution = method.GetResult();
	//结果存放在result中
	results4.push_back(solution);
}
void SpeedTest(void (*algorithmFunction)(int scale,vector<int>& result), int num, vector<int>&result, vector<double>&time) {
	clock_t start_t1 = clock();

	// 调用算法函数
	algorithmFunction(num,result);

	clock_t end_t1 = clock();
	double cost_t1 = (double)(end_t1 - start_t1) / CLOCKS_PER_SEC;

	//存储执行时间
	time.push_back(cost_t1);
}
void PrintResult() {
	cout << "PipeAndFilter Results:" << " ";
	for (std::vector<int>::iterator it = results1.begin(); it != results1.end(); ++it) {
		std::cout << *it << " ";
	}
	cout << endl;
	cout << "CallAndReturn Results:" << " ";
	for (std::vector<int>::iterator it = results2.begin(); it != results2.end(); ++it) {
		std::cout << *it << " ";
	}
	cout << endl;
	cout << "Backtracking Results:" << " ";
	for (std::vector<int>::iterator it = results3.begin(); it != results3.end(); ++it) {
		std::cout << *it << " ";
	}
	cout << endl;
	cout << "BlackBoard Results:" << " ";
	for (std::vector<int>::iterator it = results4.begin(); it != results4.end(); ++it) {
		std::cout << *it << " ";
	}
	cout << endl;
}
void PrintTime(){
	cout << "PipeAndFilter Time:" << " ";
	for (std::vector<double>::iterator it = time1.begin(); it != time1.end(); ++it) {
		std::cout << *it << " ";
	}
	cout << endl;
	cout << "CallAndReturn Time:" << " ";
	for (std::vector<double>::iterator it = time2.begin(); it != time2.end(); ++it) {
		std::cout << *it << " ";
	}
	cout << endl;
	cout << "Backtracking Time:" << " ";
	for (std::vector<double>::iterator it = time3.begin(); it != time3.end(); ++it) {
		std::cout << *it << " ";
	}
	cout << endl;
	cout << "BlackBoard Time:" << " ";
	for (std::vector<double>::iterator it = time4.begin(); it != time4.end(); ++it) {
		std::cout << *it << " ";
	}
	cout << endl;
}
void ReadDataFormText(vector<int> &numbers) {
	//要求：读文件的形式读入“测试数据”

	//声明一个ifstream对象打开文件
	ifstream infile;

	//文件路径
	string file_path = "test.txt";

	//打开文件
	infile.open(file_path);

	//检查文件是否打开
	if (!infile.is_open()) {
		cerr << "无法打开文件！" << endl;
		return;
	}

	//按行读取
	string line;

	while (getline(infile, line)) {
		// 创建字符串流
		istringstream iss(line);
		int num;

		//读入num
		while (iss >> num) {
			numbers.push_back(num);
		}
	}

	//关闭文件
	infile.close();

	return;
}
int main() {
	//读取文本数据
	vector<int> numbers;
	ReadDataFormText(numbers);
	// 输出读取的整数
	for (int num : numbers) {
		cout << "Your input scale N:" <<num<<" ";
		cout << endl;
		//进行计算并测试时间
		SpeedTest(PipeAndFilter, num, results1, time1);
		SpeedTest(CallAndReturn, num, results2, time2);
		SpeedTest(Backtracking,num, results3,time3);
		SpeedTest(BlackBoard,num, results4,time4);

	}
	//打印结果
	PrintResult();
	PrintTime(); 
}