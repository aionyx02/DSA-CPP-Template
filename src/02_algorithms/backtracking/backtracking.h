// ============================================================
//  @file        backtracking.h
//  @category    演算法 / backtracking / 排列回溯
//  @brief       以回溯枚舉 1..max_time 的所有排列並輸出
//  @complexity  O(n!) 全排列枚舉
//  @author      Andy-0614 <andytest.0908@gmail.com>
//  @created     2026-06-14
//  @modified    2026-06-14  by aionyx
//  @history
//    2026-06-14  Andy-0614  初版（自 GitHub 匯入）
//  @note        依賴 <bits/stdc++.h> + using namespace std；max_time 為外部全域變數
//    2026-06-14  aionyx  修改
// ============================================================
#pragma once

void backTracking(vector<int> nums, vector<bool> used,int time) {
	if (time >= max_time) {
		for (int i : nums) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

	for(int i=0;i<max_time;++i){
		if (used[i]) continue;
		//
		nums[time] = i + 1;
		//
		used[i]=true;
		backTracking(nums,used,time+1);
		used[i]=false;
	}
}
