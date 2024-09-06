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
// Author:���Ĳ���202130480749����2
// Ҫ�󣺴���ע������
//ȫ�ֱ��������ڴ洢�����㷨��ͬ��ģ�Ľ��
vector<int> results1;
vector<int> results2;
vector<int> results3;
vector<int> results4;
//ȫ�ֱ��� �洢����ʱ��
vector<double> time1;
vector<double> time2;
vector<double> time3;
vector<double> time4;
void PipeAndFilter(int scale, vector<int>& result)
{
	PipeandFilter method(scale);
	int solution = method.GetResult();
	//��������result��
	results1.push_back(solution);
}
void CallAndReturn(int scale, vector<int>& result)
{
	CallandReturn method(scale);
	int solution = method.GetResult();
	//��������result��
	results2.push_back(solution);
}
void Backtracking(int scale,vector<int> &result)
{
	BackTracking method(scale);
	int solution = method.GetResult();
	//��������result��
	results3.push_back(solution);
}
void BlackBoard(int scale, vector<int>& result) {
	Blackboard method(scale);
	int solution = method.GetResult();
	//��������result��
	results4.push_back(solution);
}
void SpeedTest(void (*algorithmFunction)(int scale,vector<int>& result), int num, vector<int>&result, vector<double>&time) {
	clock_t start_t1 = clock();

	// �����㷨����
	algorithmFunction(num,result);

	clock_t end_t1 = clock();
	double cost_t1 = (double)(end_t1 - start_t1) / CLOCKS_PER_SEC;

	//�洢ִ��ʱ��
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
	//Ҫ�󣺶��ļ�����ʽ���롰�������ݡ�

	//����һ��ifstream������ļ�
	ifstream infile;

	//�ļ�·��
	string file_path = "test.txt";

	//���ļ�
	infile.open(file_path);

	//����ļ��Ƿ��
	if (!infile.is_open()) {
		cerr << "�޷����ļ���" << endl;
		return;
	}

	//���ж�ȡ
	string line;

	while (getline(infile, line)) {
		// �����ַ�����
		istringstream iss(line);
		int num;

		//����num
		while (iss >> num) {
			numbers.push_back(num);
		}
	}

	//�ر��ļ�
	infile.close();

	return;
}
int main() {
	//��ȡ�ı�����
	vector<int> numbers;
	ReadDataFormText(numbers);
	// �����ȡ������
	for (int num : numbers) {
		cout << "Your input scale N:" <<num<<" ";
		cout << endl;
		//���м��㲢����ʱ��
		SpeedTest(PipeAndFilter, num, results1, time1);
		SpeedTest(CallAndReturn, num, results2, time2);
		SpeedTest(Backtracking,num, results3,time3);
		SpeedTest(BlackBoard,num, results4,time4);

	}
	//��ӡ���
	PrintResult();
	PrintTime(); 
}