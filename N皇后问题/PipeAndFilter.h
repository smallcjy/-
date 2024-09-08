#include <vector>
#include <iostream>
#pragma once
class PipeAndFilter
{
public:
    PipeAndFilter(int n) : scale(n), solution(0), chessboard(n, 0), filter_matrix(n, std::vector<int>(n, 0))
    {
        probable_num = ProbableNum(scale);
        back_probable_num = probable_num;
    }

    void Solve();

private:
    int scale;
    int solution;
    std::vector<int> chessboard;
    std::vector<std::vector<int>> filter_matrix;
    int probable_num;
    int back_probable_num;
    int ProbableNum(int n)
    {
        return n >= 4 ? 1 : 0;
    }
    void PlaceQueen(int row);
    bool CanPlace(int row, int col);
    void SetQueen(int row, int col);
    void RemoveQueen(int row, int col);
    void UpdateFilterMatrix(int row, int col, int delta);
};