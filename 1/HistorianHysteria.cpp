#include "HistorianHysteria.h"

#include <sstream>    // std::istringstream
#include <algorithm>  // sort, lower_bound
#include <iterator>   // istream_iterator
#include <cstdlib>    // std::strtol

HistorianHysteria::HistorianHysteria(const std::string& input)
    : raw_input_(input) {}

// 解析：逐行读入，每行两列整数 -> 分别放到 left_row_ / right_row_
void HistorianHysteria::parse() {
    left_row_.clear();
    right_row_.clear();

    std::istringstream iss(raw_input_);
    std::string line;

    while (std::getline(iss, line)) {
        if (line.empty()) continue;

        // 用 istringstream 逐行解析两个整数，允许多个空白分隔
        std::istringstream ls(line);
        long a, b;
        if (ls >> a >> b) {
            left_row_.push_back(static_cast<int>(a));
            right_row_.push_back(static_cast<int>(b));
        }
        // 否则：该行格式不合法，直接忽略（也可以抛异常/记录日志，看你需求）
    }

    parsed_ = true;
}

// 内部保障：需要用到数据时，若未解析则先解析（惰性解析）
void HistorianHysteria::ensureParsed() const {
    if (!parsed_) {
        // 去掉 const 限制来调用非 const 的 parse（只改变缓存状态）
        const_cast<HistorianHysteria*>(this)->parse();
    }
}

// Part 1：两列分别排序，逐对取差的绝对值累加
std::int64_t HistorianHysteria::part1() const {
    ensureParsed();

    // 拷贝一份做排序，不改动原缓存（也可选择在 parse 时排序）
    std::vector<int> L = left_row_;
    std::vector<int> R = right_row_;
    std::sort(L.begin(), L.end());
    std::sort(R.begin(), R.end());

    std::int64_t sum = 0;
    const std::size_t n = std::min(L.size(), R.size());
    for (std::size_t i = 0; i < n; ++i) {
        int diff = L[i] - R[i];
        sum += (diff >= 0 ? diff : -diff);
    }
    return sum;
}

// Part 2：相似度分数 = Σ(左列每个值 * 该值在右列出现次数)
std::int64_t HistorianHysteria::part2() const {
    ensureParsed();

    // 为计数做准备：右列排序 + 通过二分统计出现次数
    std::vector<int> R = right_row_;
    std::sort(R.begin(), R.end());

    std::int64_t score = 0;
    for (int x : left_row_) {
        auto range = std::equal_range(R.begin(), R.end(), x);
        std::int64_t cnt = static_cast<std::int64_t>(range.second - range.first);
        score += static_cast<std::int64_t>(x) * cnt;
    }
    return score;
}
