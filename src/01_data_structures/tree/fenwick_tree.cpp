// ============================================================
//  @file        fenwick_tree.cpp
//  @category    資料結構 / tree / 樹狀數組
//  @brief       前綴和查詢 + 單點加值
//  @complexity  update/query O(log n) | 空間 O(n)
//  @author      Aionyx <aionyxhuang@gmail.com>
//  @created     2026-06-14
//  @modified    2026-06-14  by aionyx
//  @history
//    2026-06-14  Aionyx  初版
//    2026-06-14  aionyx  修改
// ============================================================
#pragma once

#include <vector>

struct FenwickTree {
    int n;
    std::vector<long long> bit;

    explicit FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    void add(int i, long long v) {  // a[i] += v, 0-indexed
        for (++i; i <= n; i += i & -i) bit[i] += v;
    }

    long long sum(int i) const {  // 回傳 [0, i] 之和
        long long s = 0;
        for (++i; i > 0; i -= i & -i) s += bit[i];
        return s;
    }

    long long range(int l, int r) const {  // [l, r]
        return sum(r) - (l ? sum(l - 1) : 0);
    }
};

// usage:
//   FenwickTree ft(n);
//   ft.add(2, 5);
//   long long s = ft.range(1, 4);
