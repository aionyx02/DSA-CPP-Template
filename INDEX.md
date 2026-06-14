# Snippet 索引

> 由 pre-commit hook 自動生成，請勿手動編輯。需要時執行 `sh .githooks/gen-index.sh`。

| 分類 | 名稱（專有名詞） | 說明 | 作者 | 路徑 |
|---|---|---|---|---|
| data_structures | Graph Traversal (DFS / BFS) | 加權鄰接串列建邊 + DFS/BFS 走訪 · O(V + E) | Andy-0614 | `src/01_data_structures/graph/graph_dfs_bfs.h` |
| data_structures | Fenwick Tree (BIT) | 前綴和查詢 + 單點加值 · build O(n), query/update O(log n) | Aionyx | `src/01_data_structures/tree/fenwick_tree.cpp` |
| algorithms | Backtracking (Permutations) | 回溯枚舉 1..max_time 全排列 · O(n!) | Andy-0614 | `src/02_algorithms/backtracking/backtracking.h` |
| algorithms | Prefix Sum (1D / 2D) | 前綴和建表 + O(1) 區間/子矩陣查詢 · 建表 O(nm), 查詢 O(1) | Andy-0614 | `src/02_algorithms/prefix_sum/prefix_query.h` |
| algorithms | Binary Search / upper_bound | 找相等值 / 第一個大於 target 的位置 · O(log n) | Andy-0614 | `src/02_algorithms/searching/binary_search.h` |
| math | Modular Arithmetic (Modular Inverse, Fast Pow) | 模加減乘除 + 快速冪 + 模逆元 · pow/div O(log mod) | Andy-0614 | `src/03_math/number_theory/mod.h` |
| math | Sieve of Eratosthenes / Primality Test | 單一質數判定 + 區間質數篩 · isPrime O(√n), sieve O(R log log R) | Andy-0614 | `src/03_math/number_theory/prime.h` |
| special | Fast I/O Template | 關閉同步 + 解綁 cin/cout 的競賽 main 骨架 | Andy-0614 | `src/04_special/io_fast/main_template.cpp` |
