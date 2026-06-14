# Coding Style — DSA_CPP_Template

本庫為 **C++ snippet 儲存庫**，所有程式碼遵循以下風格。
格式化交給 `.clang-format`（commit 時由 pre-commit hook 自動套用），本文件補充工具管不到的「人為約定」。

## 1. 語言標準

- 預設 **C++17**。
- 函式庫型 snippet（可被別處 `#include`）要使用**乾淨的標準 include**，不要 `using namespace std;`。
- 競賽便利寫法（`#include <bits/stdc++.h>`、`using namespace std;`、火力全開巨集）**只允許**出現在
  `src/04_special/` 或每個 snippet 內部的 `// usage:` 範例段。

## 2. 命名

| 對象 | 規則 | 範例 |
|---|---|---|
| 函式 / 變數 | `snake_case` | `lower_bound_idx`, `dist` |
| 型別 / struct / class | `PascalCase` | `SegmentTree`, `FenwickTree` |
| 常數 / 巨集 | `UPPER_SNAKE` | `MOD`, `MAX_N` |
| 模板參數 | 單字母大寫 | `T`, `U`, `Cmp` |
| 檔名 / 資料夾 | `snake_case` | `segment_tree.cpp` |

## 3. 格式（由 clang-format 落地）

- 縮排 **4 空格**，不用 Tab。
- 行寬 **100**。
- 指標靠左：`int* p`。
- `#pragma once` 作為 include guard（不用 `#ifndef` 三件套）。
- include 由 clang-format 自動排序/分組，請勿手動逆序。
- 換行 **LF**、檔尾留一個換行、去除行尾空白（`.editorconfig` 已設）。

## 4. 每個 snippet 的硬性要求

1. **標準檔頭區塊**（見 `templates/snippet.cpp.tmpl`）——
   含 `@file / @category / @brief / @complexity / @author / @created / @modified / @history`。
   - `@author`、`@created`：建立時填一次，**不要事後改**（保留原作者）。
   - `@modified`、`@history`：**別手動維護**，commit 時 hook 會自動蓋章。
2. **複雜度標註**：在 `@complexity` 寫清楚時間/空間。
3. **使用範例**：檔尾用 `// usage:` 區段，放一段可直接複製貼上跑的示範。

## 5. 一個合格 snippet 長這樣

```cpp
// ============================================================
//  @file        fenwick_tree.cpp
//  @category    資料結構 / tree / 樹狀數組
//  @brief       前綴和查詢 + 單點加值
//  @complexity  update/query O(log n) | 空間 O(n)
//  @author      Aionyx <aionyxhuang@gmail.com>
//  @created     2026-06-14
//  @modified    2026-06-14  by Aionyx
//  @history
//    2026-06-14  Aionyx  初版
// ============================================================
#pragma once

#include <vector>

struct FenwickTree {
    int n;
    std::vector<long long> bit;

    explicit FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    void add(int i, long long v) {
        for (++i; i <= n; i += i & -i) bit[i] += v;
    }

    long long sum(int i) const {  // [0, i]
        long long s = 0;
        for (++i; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

// usage:
//   FenwickTree ft(n);
//   ft.add(2, 5);
//   long long s = ft.sum(4);   // 前 5 項和
```

> 命名與格式不確定時，跑一次 `clang-format -i <file>`，或直接 commit 讓 hook 處理。
