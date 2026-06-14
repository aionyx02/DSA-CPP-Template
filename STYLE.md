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

## 4. 精簡檔頭（硬性要求）

採**精簡格式**：標題列用**專有名詞**（演算法/資料結構正式名稱），不要冗長描述。
共 6 個欄位、固定順序，模板見 `templates/snippet.cpp.tmpl`：

```
// ============================================================
//  <檔名> · <專有名詞，如 Fenwick Tree (BIT)>
//  <一句話說明> · <複雜度，如 O(log n)>
//  @author   <原作者 name <email>>     ← 建立填一次，hook 不覆蓋
//  @modified <date> by <name>          ← hook 自動更新
//  @history                            ← hook 自動維護，每人每日一行
//    <date> <name> <摘要>
// ============================================================
```

規則：
- **標題列以專有名詞為主**，分類資訊靠資料夾路徑表達（不再放 `@category`）。
- `@author`：原作者，建立後**不要改**；`@modified` / `@history`：**別手動維護**，commit 時 hook 自動蓋章。
- 依賴 `<bits/stdc++.h>` / `using namespace std` 的競賽型 snippet，於說明列或 `// usage:` 註明即可，不另設欄位。
- 檔尾建議用 `// usage:` 放一段可直接複製貼上跑的示範。

> 找 snippet 用 `INDEX.md`（自動生成的總表）或 `scripts/find.ps1 <關鍵字>`，不必逐層翻資料夾。

## 5. 一個合格 snippet 長這樣

```cpp
// ============================================================
//  fenwick_tree.cpp · Fenwick Tree (BIT)
//  前綴和查詢 + 單點加值 · build O(n), query/update O(log n)
//  @author   Aionyx <aionyxhuang@gmail.com>
//  @modified 2026-06-14 by Aionyx
//  @history
//    2026-06-14 Aionyx 初版
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
