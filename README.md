# DSA_CPP_Template

C++ 演算法 / 資料結構 **snippet 儲存庫**。
每段程式碼都有統一的檔頭、統一的格式，並且 **commit 時自動記錄「誰動過」**——
就算沒手動填，hook 也會蓋上修改者與時間，日後可由 `git blame` + 檔頭 `@history` 完整回溯。

## 快速上手

```powershell
# 1) 安裝 hook（啟用自動署名章 + 自動格式化）— clone 後做一次
./scripts/install-hooks.ps1            # Git Bash 用 sh ./scripts/install-hooks.sh

# 2) 新增一個 snippet（檔頭自動填好）
./scripts/new-snippet.ps1 -Path 01_data_structures/tree -Name segment_tree `
    -Brief "區間查詢 + 單點更新" -Complexity "build O(n) | query/update O(log n)"

# 3) 照常 commit —— 檔頭署名章會自動蓋上
git add . ; git commit -m "feat(ds/tree): 線段樹"
```

## 分類結構

| 目錄 | 類別 | 內容 |
|---|---|---|
| `src/01_data_structures/` | 資料結構（含圖論） | `tree` `heap` `disjoint_set` `graph` `misc` |
| `src/02_algorithms/` | 演算法 | `sorting` `searching` `dp` `greedy` `string` |
| `src/03_math/` | 數學 | `number_theory` `combinatorics` `linear_algebra` `geometry` |
| `src/04_special/` | 特殊寫法 | `io_fast` `bit_tricks` `macros` |

> 子分類可自由擴充：開新資料夾並補一個 `.gitkeep` 即可。

## 快速查找

不用逐層翻資料夾：

```powershell
# 關鍵字搜尋（比對檔名 / 專有名詞 / 說明 / 作者）
./scripts/find.ps1 "binary search"
./scripts/find.ps1 mod
```

或直接開 [`INDEX.md`](INDEX.md) —— 自動生成的總表，一行一個 snippet，Ctrl+F 即可。
（`INDEX.md` 由 pre-commit hook 自動更新，免手動維護。）

## 文件

- [`INDEX.md`](INDEX.md) — 所有 snippet 的自動索引表。
- [`STYLE.md`](STYLE.md) — coding style（命名 / 格式 / 精簡檔頭規範）。
- [`CONTRIBUTING.md`](CONTRIBUTING.md) — 如何新增 snippet、署名機制細節、如何用 git 回溯。

## 署名 / 痕跡追蹤（本庫特色）

兩層互相印證：

1. **檔頭 metadata**：`@author`（原作者，不變）/ `@modified`（最後修改者，hook 自動更新）/
   `@history`（每位修改者每日一行）。
2. **git 歷史**：`git blame <file>` 逐行歸屬、`git log -p -- <file>` 完整變更。

→ 任何人「動過手腳」都會留痕；AI 可直接讀這兩層自動標註是誰改的。
