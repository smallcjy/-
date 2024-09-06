#include "PipeAndFilter.h"

int main()
{
    // 生成所有可能的棋盘配置
    vector<vector<string>> boards = {{"Q...", "...Q", ".Q..", "..Q."}, {"..Q.", "Q...", ".Q..", "...Q"}};

    // 创建过滤器
    QueenFilter queenFilter;

    // 连接管道和过滤器
    vector<vector<string>> valid_boards = Pipe::connect(queenFilter, boards);

    // 打印有效的棋盘配置
    for (auto &board : valid_boards)
    {
        for (auto &row : board)
        {
            cout << row << endl;
        }
        cout << "-----------------" << endl;
    }

    return 0;
}