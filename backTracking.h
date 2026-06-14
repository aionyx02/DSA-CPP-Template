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