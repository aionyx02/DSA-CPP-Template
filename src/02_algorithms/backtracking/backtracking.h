// ============================================================
//  backtracking.h · Backtracking (Permutations)
//  回溯枚舉 1..max_time 全排列 · O(n!)
//  @author   Andy-0614 <andytest.0908@gmail.com>
//  @modified 2026-06-14 by aionyx
//  @history
//    2026-06-14 Andy-0614 初版（自 GitHub 匯入）
//    2026-06-14 aionyx 修改
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
