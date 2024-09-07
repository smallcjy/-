#ifndef PIPEANDFILTER_H
#define PIPEANDFILTER_H

#include <iostream>
#include <vector>
using namespace std;

// Filter 是一个抽象类，定义了一个虚函数 execute，接受一个二维字符串向量作为输入
class Filter {
public:
    // 执行过滤操作，具体实现由子类提供
    virtual vector<vector<string>> execute(vector<vector<string>> input) = 0;
};

// QueenFilter 是 Filter 的一个具体实现，用于处理棋盘问题
class QueenFilter : public Filter {
public:
    // 重写 execute 函数，实现具体的过滤逻辑
    vector<vector<string>> execute(vector<vector<string>> input) override;

private:
    // 检查棋盘布局是否有效
    bool is_valid(vector<string>& board);
    // 检查给定位置的皇后是否不受攻击
    bool is_not_under_attack(int row, int col, vector<int>& queens);
};

// Pipe 类用于连接过滤器和输入，实现管道和过滤器模式
class Pipe {
public:
    // 连接过滤器和输入，返回过滤后的结果
    static vector<vector<string>> connect(Filter& filter, vector<vector<string>> input);
};

#endif