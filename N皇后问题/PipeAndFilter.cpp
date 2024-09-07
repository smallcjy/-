#include "PipeAndFilter.h"

// QueenFilter 的 execute 方法，遍历输入的所有棋盘，如果棋盘有效，则将其添加到结果中
vector<vector<string>> QueenFilter::execute(vector<vector<string>> input)
{
    vector<vector<string>> result;
    for (auto &board : input)
    {
        if (is_valid(board))
        {
            result.push_back(board);
        }
    }
    return result;
}

// 检查棋盘是否有效的方法，遍历棋盘的每一个位置，如果发现一个皇后，并且这个皇后受到攻击，则返回 false
bool QueenFilter::is_valid(vector<string> &board)
{
    int n = board.size();
    vector<int> queens(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'Q')
            {
                queens[i] = j;
                if (!is_not_under_attack(i, j, queens))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

// 检查一个皇后是否受到攻击的方法，遍历所有的已经放置的皇后，如果有任何一个皇后可以攻击到当前位置，则返回 false
bool QueenFilter::is_not_under_attack(int row, int col, vector<int> &queens)
{
    for (int i = 0; i < row; i++)
    {
        if (queens[i] == col || queens[i] - i == col - row || queens[i] + i == col + row)
        {
            return false;
        }
    }
    return true;
}

// Pipe 的 connect 方法，接受一个过滤器和一个输入，返回过滤器处理输入后的结果
vector<vector<string>> Pipe::connect(Filter& filter, vector<vector<string>> input ) 
{
    return filter.execute(input);
}