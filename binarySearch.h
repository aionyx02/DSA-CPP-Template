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