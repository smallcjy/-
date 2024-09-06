#include "PipeAndFilter.h"

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

vector<vector<string>> Pipe::connect(Filter& filter, vector<vector<string>> input ) 
{
    return filter.execute(input);
}