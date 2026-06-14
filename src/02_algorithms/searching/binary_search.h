// ============================================================
//  @file        binary_search.h
//  @category    演算法 / searching / 二分搜尋
//  @brief       已排序陣列中找相等值 / 第一個大於 target 的位置
//  @complexity  O(log n)
//  @author      Andy-0614 <andytest.0908@gmail.com>
//  @created     2026-06-14
//  @modified    2026-06-14  by aionyx
//  @history
//    2026-06-14  Andy-0614  初版（自 GitHub 匯入）
//  @note        依賴 <bits/stdc++.h> + using namespace std
//    2026-06-14  aionyx  修改
// ============================================================
#pragma once

pair<bool, int> binarySearchEqual(vector<int>& arr, int target) {
    int l = 0;
    int r = arr.size() - 1;
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == target) {
            return {true, m};
        }
        if (arr[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return {false, l};
}

pair<bool, int> binarySearchBig(vector<int>& arr, int target) {
    int l = 0;
    int r = arr.size() - 1;
    int ansIdx = -1;
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] > target) {
            ansIdx = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    if (ansIdx != -1) {
        return {true, ansIdx};
    }
    return {false, (int)arr.size()};
}
