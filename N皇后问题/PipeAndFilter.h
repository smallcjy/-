#ifndef PIPEANDFILTER_H
#define PIPEANDFILTER_H

#include <iostream>
#include <vector>
using namespace std;

class Filter {
public:
    virtual vector<vector<string>> execute(vector<vector<string>> input) = 0;
};

class QueenFilter : public Filter {
public:
    vector<vector<string>> execute(vector<vector<string>> input) override;

private:
    bool is_valid(vector<string>& board);
    bool is_not_under_attack(int row, int col, vector<int>& queens);
};

class Pipe {
public:
    static vector<vector<string>> connect(Filter& filter, vector<vector<string>> input);
};

#endif
