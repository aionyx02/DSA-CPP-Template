# 演算法工具箱

---

## 目錄
- [演算法工具箱](#演算法工具箱)
  - [目錄](#目錄)
  - [1. backTracking.h](#1-backtrackingh)
    - [`backTracking`](#backtracking)
  - [2. binarySearch.h](#2-binarysearchh)
    - [`binarySearchEqual`](#binarysearchequal)
    - [`binarySearchBig`](#binarysearchbig)
  - [3. graph\_dfs\_bfs.h](#3-graph_dfs_bfsh)
    - [`add_edge`](#add_edge)
    - [`dfs`](#dfs)
    - [`bfs`](#bfs)
  - [4. mod.h](#4-modh)
    - [`add_mod`](#add_mod)
    - [`sub_mod`](#sub_mod)
    - [`mul_mod`](#mul_mod)
    - [`pow_mod`](#pow_mod)
    - [`div_mod`](#div_mod)
  - [5. prefix\_suffix.h](#5-prefix_suffixh)
    - [`prefixSum`](#prefixsum)
    - [`suffixSum`](#suffixsum)
  - [6. prime.h](#6-primeh)
    - [`isPrime`](#isprime)
    - [`primeRangeNumber`](#primerangenumber)

---

## 1. backTracking.h

### `backTracking`
* **input**
  * `vector<int> nums`：存放當前排列結果的容器。
  * `vector<bool> used`：記錄每個數字是否已被選用，避免重複選取。
  * `int time`：當前的遞迴深度，代表目前正在決定排列中的第幾個位置。
* **describe**
  * 透過深度優先搜尋（DFS）走訪所有可能的排列組合。在每一步嘗試中，檢查 `used` 狀態以決定是否選用 `nums` 中的數字，進入下一層遞迴後再將狀態恢復，以此達到撤銷選擇與窮舉的效果。
* **output**
  * `void`：無回傳值，當遞迴深度達到指定條件時，直接將該組排列結果輸出至標準輸出。

---

## 2. binarySearch.h

### `binarySearchEqual`
* **input**
  * `vector<int>& arr`：已排序的來源目標陣列。
  * `int target`：欲尋找的目標數值。
* **describe**
  * 在已排序的陣列中，利用雙指標每次將搜尋範圍折半，持續比對中間值與目標值，直到找到與 `target` 完全相等的元素為止。
* **output**
  * `pair<bool, int>`：第一個欄位代表是否成功找到相等的目標值；第二個欄位在成功時回傳該目標值的索引，失敗時回傳目標值應插入的索引位置。

### `binarySearchBig`
* **input**
  * `vector<int>& arr`：已排序的來源目標陣列。
  * `int target`：用來尋找嚴格大於此值的邊界參考目標。
* **describe**
  * 在已排序的陣列中，利用二分法尋找第一個大於 `target` 的元素。當中間值大於目標值時，記錄當前位置並往左半邊限縮範圍，直到逼近出嚴格大於目標值的最小邊界。
* **output**
  * `pair<bool, int>`：第一個欄位代表陣列中是否存在大於 `target` 的元素；第二個欄位在存在時回傳第一個大於 `target` 的元素索引，若不存在則回傳陣列總長度（代表超出範圍）。

---

## 3. graph_dfs_bfs.h

### `add_edge`
* **input**
  * `vector<vector<pair<int, int>>>& adj`：圖的鄰接串列，記錄每個節點與其相鄰節點、邊權重的對應關係。
  * `int root`：邊的起點節點編號。
  * `int child`：邊的終點節點編號.
  * `int weight`：該條邊的權重值。
* **describe**
  * 在有向圖的鄰接串列中，從指定的起點節點（`root`）向終點節點（`child`）加入一條帶有權重（`weight`）的有向邊。
* **output**
  * `void`：無回傳值，直接修改傳入的鄰接串列結構。

### `dfs`
* **input**
  * `vector<vector<pair<int, int>>>& adj`：圖的鄰接串列。
  * `int node`：當前進行深度優先搜尋的起點節點編號。
  * `vector<bool>& visited`：記錄各個節點是否已被訪問過的狀態陣列。
  * `bool clear`：可選參數，用來決定在搜尋前是否要重設走訪狀態（預設為 `false`）。
* **describe**
  * 運用深度優先搜尋（DFS）策略，若 `clear` 為真則先將走訪陣列全部初始化為未訪問，接著遞迴地往圖的深處走訪所有未曾造訪過的相鄰節點，並在訪問時將節點編號輸出。
* **output**
  * `void`：無回傳值，結果直接輸出至標準輸出。

### `bfs`
* **input**
  * `vector<vector<pair<int, int>>>& adj`：圖的鄰接串列。
  * `int node`：廣度優先搜尋的起始節點編號。
  * `vector<bool>& visited`：記錄各個節點是否已被訪問過的狀態陣列.
  * `bool clear`：可選參數，用來決定在搜尋前是否要重設走訪狀態（預設為 `false`）。
* **describe**
  * 運用廣度優先搜尋（BFS）策略，藉由佇列（Queue）來輔助實現層序走訪。走訪時由近到遠擴展相鄰節點，並在取出佇列元素時將其數值輸出。
* **output**
  * `void`：無回傳值，結果直接輸出至標準輸出。

---

## 4. mod.h

### `add_mod`
* **input**
  * `long long a`：被加數。
  * `long long b`：加數。
  * `long long mod`：取模基數。
* **describe**
  * 計算兩數相加並取模的結果。先將負數平移為正數餘數，再透過減法關係進行邊界檢查，避免傳統兩數直接相加時可能產生的整數溢位問題。
* **output**
  * `long long`：相加取模後的正整數餘數結果。

### `sub_mod`
* **input**
  * `long long a`：被減數。
  * `long long b`：減數.
  * `long long mod`：取模基數。
* **describe**
  * 計算兩數相減並取模的結果。先處理輸入的正負號，在相減前進行大小判定，若被減數小於減數，則補上一個模數再進行減法，以確保結果不會出現負數。
* **output**
  * `long long`：相減取模後的正整數餘數結果。

### `mul_mod`
* **input**
  * `long long a`：被乘數。
  * `long long b`：乘數。
  * `long long mod`：取模基數。
* **describe**
  * 計算兩數相乘並取模的結果。在相乘前先做基本的正數化校正，並將資料型態暫時轉型為 `__int128_t` 進行乘法運算，徹底防止因兩個接近最大限制的 `long long` 相乘而導致的溢位。
* **output**
  * `long long`：相乘取模後的正整數餘數結果。

### `pow_mod`
* **input**
  * `long long base`：底數。
  * `long long exp`：指數，可支援負整數。
  * `long long mod`：取模基數。
* **describe**
  * 採用快速冪（Binary Exponentiation）演算法計算次方位。若遇到指數為負數的情況，會利用費馬小定理求出底數的模反元素後轉為正指數計算。
* **output**
  * `long long`：次方取模後的正整數餘數結果。

### `div_mod`
* **input**
  * `long long a`：分子（被除數）。
  * `long long b`：分母（除數）。
  * `long long mod`：取模基數。
* **describe**
  * 在模世界中實作除法運算。將除以 `b` 的行為，轉換為乘以 `b` 的 `-1` 次方（即模反元素），再透過乘法取模函式得到最終結果。
* **output**
  * `long long`：除法取模後的正整數餘數結果。

---

## 5. prefix_suffix.h

### `prefixSum`
* **input**
  * `vector<int>& arr`：原始輸入的資料陣列。
  * `vector<int>& prefix`：用來接收前綴和計算結果的目標容器。
* **describe**
  * 計算輸入陣列的前綴和（Prefix Sum）。每個位置的新數值等於陣列開頭到該當前位置所有元素的總和，可用於後續單次查詢區間和。
* **output**
  * `void`：無回傳值，計算結果直接填充至傳入的 `prefix` 陣列中。

### `suffixSum`
* **input**
  * `vector<int>& arr`：原始輸入的資料陣列。
  * `vector<int>& suffix`：用來接收後綴和計算結果的目標容器。
* **describe**
  * 計算輸入陣列的後綴和（Suffix Sum）。從陣列尾端向前端進行累加，每個位置的新數值等於當前位置到陣列最末端所有元素的總和。
* **output**
  * `void`：無回傳值，計算結果直接填充至傳入的 `suffix` 陣列中。

---

## 6. prime.h

### `isPrime`
* **input**
  * `long long n`：待檢驗的目標整數。
* **describe**
  * 快速判定一個獨立的大整數是否為質數。藉由排除 2 和 3 的倍數，並利用步長為 6 的迴圈檢查至 $\sqrt{n}$，從而有效提高對單一未知數的篩選效率。
* **output**
  * `bool`：若目標整數為質數則傳回 `true`，否則傳回 `false`。

### `primeRangeNumber`
* **input**
  * `int L`：欲搜尋質數區間的左界。
  * `int R`：欲搜尋質數區間的右界。
* **describe**
  * 實作埃拉托斯特尼篩法（Sieve of Eratosthenes），在 `[0, R]` 範圍內利用質數倍數標記法篩出所有合數，最後收集並整理落在指定閉區間 `[L, R]` 內的所有質數。
* **output**
  * `vector<int>`：包含該區間內所有質數、由小到大排序的整數陣列。