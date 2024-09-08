#include "PipeAndFilter.h"

void PipeAndFilter::Solve()
{
    PlaceQueen(0);
    std::cout << "Total solutions: " << solution << std::endl;
}

// 放置皇后
void PipeAndFilter::PlaceQueen(int row)
{
    if (row == scale)  // 如果已经放置了scale个皇后（即所有皇后都已放置完毕）
    {
        solution++;  // 解决方案数量加1
        return;
    }

    for (int col = 0; col < scale; col++)  // 遍历当前行的每一列
    {
        if (CanPlace(row, col))  // 如果可以在当前位置放置皇后
        {
            SetQueen(row, col);  // 放置皇后
            PlaceQueen(row + 1);  // 在下一行放置皇后
            RemoveQueen(row, col);  // 移除当前位置的皇后，以便于寻找其他可能的解决方案
        }
    }
}

// 判断是否可以在指定位置放置皇后
bool PipeAndFilter::CanPlace(int row, int col)
{
    return filter_matrix[row][col] == 0;
}
// 设置皇后
void PipeAndFilter::SetQueen(int row, int col)
{
    chessboard[row] = col;
    UpdateFilterMatrix(row, col, 1);
}
// 移除皇后
void PipeAndFilter::RemoveQueen(int row, int col)
{
    chessboard[row] = 0;
    UpdateFilterMatrix(row, col, -1);
}
// 更新过滤矩阵
void PipeAndFilter::UpdateFilterMatrix(int row, int col, int delta)
{
    for (int i = 0; i < scale; i++)  // 遍历每一行
    {
        for (int j = 0; j < scale; j++)  // 遍历每一列
        {
            // 如果当前位置与指定位置在同一行、同一列或同一对角线上
            if (i == row || j == col || i - j == row - col || i + j == row + col)
            {
                filter_matrix[i][j] += delta;  // 更新过滤矩阵的值
            }
        }
    }
}