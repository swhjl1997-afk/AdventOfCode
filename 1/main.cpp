#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "HistorianHysteria.h"

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 1) 选择输入文件：优先 argv[1]，否则默认 "input.txt"
    const char* path = (argc > 1 ? argv[1] : "input.txt");

    // 2) 读整个文件到字符串
    std::ifstream fin(path, std::ios::in | std::ios::binary);
    if (!fin) {
        std::cerr << "[Error] Cannot open file: " << path << "\n";
        std::cerr << "Usage: " << (argc > 0 ? argv[0] : "aoc_day1")
                  << " [input_file]\n";
        return 1;
    }
    std::ostringstream ss;
    ss << fin.rdbuf();
    const std::string input = ss.str();

    // 3) 构造并计算
    HistorianHysteria hh(input);
    // 若你没用惰性解析，可主动：hh.parse();

    const auto ans1 = hh.part1();
    const auto ans2 = hh.part2();

    // 4) 打印结果
    std::cout << ans1 << "\n" << ans2 << "\n";
    return 0;
}
