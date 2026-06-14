void prefixSum1D(const vector<int>& arr, vector<int>& prefix) {
    int n = arr.size();
    prefix.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
}

int querySum1D(const vector<int>& prefix, int L, int R) {
    return prefix[R + 1] - prefix[L];
}

void prefixSum2D(const vector<vector<int>>& arr, vector<vector<int>>& prefix) {
    int n = arr.size();
    if (n == 0) return;
    int m = arr[0].size();
    
    prefix.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefix[i][j] = prefix[i - 1][j] 
                         + prefix[i][j - 1] 
                         - prefix[i - 1][j - 1] 
                         + arr[i - 1][j - 1];
        }
    }
}

int querySum2D(const vector<vector<int>>& prefix, int row1, int col1, int row2, int col2) {
    int r1 = row1 + 1, c1 = col1 + 1;
    int r2 = row2 + 1, c2 = col2 + 1;
    
    return prefix[r2][c2] 
         - prefix[r1 - 1][c2] 
         - prefix[r2][c1 - 1] 
         + prefix[r1 - 1][c1 - 1];
}