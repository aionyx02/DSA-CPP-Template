// ============================================================
//  @file        graph_dfs_bfs.h
//  @category    資料結構 / graph / 圖走訪
//  @brief       加權鄰接串列的建邊與 DFS / BFS 走訪
//  @complexity  O(V + E)
//  @author      Andy-0614 <andytest.0908@gmail.com>
//  @created     2026-06-14
//  @modified    2026-06-14  by aionyx
//  @history
//    2026-06-14  Andy-0614  初版（自 GitHub 匯入）
//  @note        依賴 <bits/stdc++.h> + using namespace std
//    2026-06-14  aionyx  修改
// ============================================================
#pragma once

void add_edge(vector<vector<pair<int, int>>>& adj, int root, int child, int weight) {
    adj[root].push_back({child, weight});
}

void dfs(vector<vector<pair<int, int>>>& adj, int node, vector<bool>& visited, bool clear = false) {
    if (clear) {
        for (int i = 0; i < visited.size(); ++i) {
            visited[i] = false;
        }
        dfs(adj, node, visited);
    } else {
        //
        cout << node << " ";
        //
        visited[node] = true;
        for (auto child : adj[node]) {
            if (!visited[child.first]) {
                dfs(adj, child.first, visited);
            }
        }
    }
}

void bfs(vector<vector<pair<int, int>>>& adj, int node, vector<bool>& visited, bool clear = false) {
    if (clear) {
        for (int i = 0; i < visited.size(); ++i) {
            visited[i] = false;
        }
    }
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        //
        cout << now << " ";
        //
        for (auto child : adj[now]) {
            if (!visited[child.first]) {
                visited[child.first] = true;
                q.push(child.first);
            }
        }
    }
}
