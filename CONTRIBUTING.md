# 貢獻指南 — DSA_CPP_Template

## 0. 第一次使用：安裝 hook（必做）

clone 後跑一次，啟用「自動署名章」與「自動格式化」：

```powershell
# Windows / PowerShell
./scripts/install-hooks.ps1
```

```sh
# Git Bash / WSL / Linux / macOS
sh ./scripts/install-hooks.sh
```

它只是設定 `git config core.hooksPath .githooks`。沒裝 hook 也能 commit，但檔頭不會被自動蓋章。

> hook 在 Windows 上透過 Git for Windows 內附的 `sh` 執行，無需額外安裝。
> `clang-format` 為**選用**：有裝就自動格式化，沒裝只跳過格式化、署名章照蓋。

## 1. 新增一個 snippet

建議用腳本產生（檔頭會自動填好）：

```powershell
./scripts/new-snippet.ps1 -Path 01_data_structures/tree -Name segment_tree `
    -Brief "區間查詢 + 單點更新" -Complexity "build O(n) | query/update O(log n)"
```

`-Path` 是相對 `src/` 的分類資料夾，`-Name` 是檔名（不含副檔名）。
手寫也可以，但**檔頭區塊不可省**（格式見 `templates/snippet.cpp.tmpl` 與 `STYLE.md`）。

## 2. 分類放哪裡

```
src/
├─ 01_data_structures/   資料結構（含圖論：tree / heap / disjoint_set / graph / misc）
├─ 02_algorithms/        演算法（sorting / searching / dp / greedy / string）
├─ 03_math/              數學（number_theory / combinatorics / linear_algebra / geometry）
└─ 04_special/           特殊寫法（io_fast / bit_tricks / macros）
```

新子分類就開新資料夾，並補一個 `.gitkeep`（讓空資料夾能入庫）。

## 3. 署名 / 痕跡追蹤機制（本庫核心）

**目標：只要動過這個專案，就會留下痕跡；即便忘記寫，commit 時也會被自動蓋章。**

機制有兩層，互相印證：

1. **檔頭 metadata（人看得懂的層）**
   - `@author` / `@created`：原作者，建立後不再變動。
   - `@modified`：最後修改者 + 日期 —— **commit 時 pre-commit hook 自動覆寫**。
   - `@history`：每位修改者在當日留下一行；同日同人不重複（冪等）。
   - 你**不需要**手動維護 `@modified` / `@history`，hook 會處理。

2. **git 本身（機器精準的層）**
   - 每個 commit 都記了 author / time，逐行可用 `git blame` 回溯。

### AI 如何「自動標註是誰動了」

- 逐行歸屬：`git blame src/01_data_structures/tree/segment_tree.cpp`
- 某檔完整歷史：`git log -p -- <file>`
- 檔頭 `@history` 提供人類可讀摘要，`git blame` 提供精準到行的歸屬，兩者對照即可。

## 4. commit 前會自動發生什麼

對本次 commit 中 `src/**` 的 `.cpp/.cc/.cxx/.hpp/.h/.hh`：

1. 若有 `clang-format` → 自動格式化。
2. 由 `.githooks/stamp.sh` 蓋上 / 更新檔頭署名章。
3. 自動 re-stage。

所以你 commit 後，檔案內容可能比你 `git add` 時多了署名章——這是預期行為。

## 5. 提交訊息

簡短、動詞開頭，標明分類，例：

```
feat(ds/tree): 新增 lazy 線段樹（區間加值 + 區間求和）
fix(math/number_theory): 修正 modpow 溢位
```
