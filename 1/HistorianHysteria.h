#pragma once

#include <string>
#include <vector>
#include <cstdint>   // for int64_t

class HistorianHysteria {
public:
    // 构造：保存原始输入（不解析）
    explicit HistorianHysteria(const std::string& input);

    // 析构：无资源，遵循 Rule of Zero
    ~HistorianHysteria() = default;

    // 解析原始数据到左右两列（id 列表）
    void parse();

    // 第1部分与第2部分的答案（const：不修改成员）
    std::int64_t part1() const;
    std::int64_t part2() const;

    // 可选：暴露原始数据的只读访问（如你需要）
    const std::string& raw() const { return raw_input_; }

private:
    std::string raw_input_;          // 原始整块输入
    std::vector<int> left_row_;      // 左列
    std::vector<int> right_row_;     // 右列

    // 工具：确保已经 parse 过（内部自检/惰性解析可在需要时调用）
    void ensureParsed() const;

    // 将 ensureParsed 的“已解析”状态做成可变的缓存标记
    // （不改变逻辑数据，只是标记状态）
    mutable bool parsed_ = false;
};
