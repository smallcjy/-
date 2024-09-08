#include "PipeAndFilter.h"
#include "PipeAndFilter.cpp"
#include <fstream>
#include <string>

using namespace std;


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
    PipeAndFilter solver(n);
    solver.Solve();
    return 0;
}