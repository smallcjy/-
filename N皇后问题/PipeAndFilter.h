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

// #include <iostream>
// #include <vector>
// using namespace std;

// class Filter {
// public:
//     virtual vector<vector<string>> execute(vector<vector<string>> input) = 0;
// };

// class QueenFilter : public Filter {
// public:
//     vector<vector<string>> execute(vector<vector<string>> input) override {
//         vector<vector<string>> result;
//         for (auto& board : input) {
//             if (is_valid(board)) {
//                 result.push_back(board);
//             }
//         }
//         return result;
//     }

// private:
//     bool is_valid(vector<string>& board) {
//         int n = board.size();
//         vector<int> queens(n, -1);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (board[i][j] == 'Q') {
//                     queens[i] = j;
//                     if (!is_not_under_attack(i, j, queens)) {
//                         return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }

//     bool is_not_under_attack(int row, int col, vector<int>& queens) {
//         for (int i = 0; i < row; i++) {
//             if (queens[i] == col || queens[i] - i == col - row || queens[i] + i == col + row) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// class Pipe {
// public:
//     static vector<vector<string>> connect(Filter& filter, vector<vector<string>> input) {
//         return filter.execute(input);
//     }
// };

// int main() {
//     // 生成所有可能的棋盘配置
//     vector<vector<string>> boards = {{"Q...", "...Q", ".Q..", "..Q."}, {"..Q.", "Q...", ".Q..", "...Q"}};

//     // 创建过滤器
//     QueenFilter queenFilter;

//     // 连接管道和过滤器
//     vector<vector<string>> valid_boards = Pipe::connect(queenFilter, boards);

//     // 打印有效的棋盘配置
//     for (auto& board : valid_boards) {
//         for (auto& row : board) {
//             cout << row << endl;
//         }
//         cout << "-----------------" << endl;
//     }

//     return 0;
// }