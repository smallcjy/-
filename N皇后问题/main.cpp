#include "PipeAndFilter.h"
#include "PipeAndFilter.cpp"
#include <fstream>

// 递归生成所有可能的棋盘配置
void generate_boards(int n, int row, vector<string>& board, vector<vector<string>>& all_boards) {
    if (row == n) {
        all_boards.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        board[row] = string(n, '.');
        board[row][col] = 'Q';
        generate_boards(n, row + 1, board, all_boards);
    }
}

// 生成所有可能的棋盘配置的入口函数
vector<vector<string>> generate_all_boards(int n) {
    vector<vector<string>> all_boards;
    vector<string> board(n);
    generate_boards(n, 0, board, all_boards);
    return all_boards;
}

// 从文件中读取棋盘的大小
int readFile(string path) {
    ifstream file;

    file.open(path);

    if(!file) {
        cerr<< "Unable to open file " << path << endl;
        return -1;
    }

    int number;
    file >> number;

    file.close();
    return number;

}

// 主函数
int main()
{
    // 从文件中读取棋盘的大小
    int n = readFile("N.txt");
    // 生成所有可能的棋盘配置
    vector<vector<string>> boards = generate_all_boards(n);
    // 创建过滤器
    QueenFilter queenFilter;
    // 连接管道和过滤器，获取有效的棋盘配置
    vector<vector<string>> valid_boards = Pipe::connect(queenFilter, boards);
    // 打印有效的棋盘配置的数量
    cout << "The number of valid_boards is: " << valid_boards.size() << endl;
    return 0;
}