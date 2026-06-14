#!/bin/sh
# ============================================================
#  gen-index.sh — 掃描 src/ 下所有 snippet 的精簡檔頭，產生 INDEX.md。
#  由 pre-commit hook 自動呼叫；也可手動執行：sh .githooks/gen-index.sh
# ============================================================
set -eu

cd "$(git rev-parse --show-toplevel)"
out="INDEX.md"

{
    echo "# Snippet 索引"
    echo
    echo "> 由 pre-commit hook 自動生成，請勿手動編輯。需要時執行 \`sh .githooks/gen-index.sh\`。"
    echo
    echo "| 分類 | 名稱（專有名詞） | 說明 | 作者 | 路徑 |"
    echo "|---|---|---|---|---|"
} >"$out"

find src -type f \( -name '*.cpp' -o -name '*.cc' -o -name '*.cxx' \
    -o -name '*.hpp' -o -name '*.h' -o -name '*.hh' \) | LC_ALL=C sort | while IFS= read -r f; do
    # 分類 = src 下第一層資料夾（去掉數字前綴）
    cat=$(printf '%s' "$f" | sed -E 's#^src/[0-9]+_([^/]+)/.*#\1#')

    # 從前 12 行檔頭抽出 title / brief / author（tab 分隔）
    parsed=$(awk '
        NR > 12 { exit }
        {
            line = $0
            if (line !~ /^\/\//) next
            sub(/^\/\/[ \t]*/, "", line)
            if (line ~ /^=+$/) next
            if (line ~ /^@author/)  { sub(/^@author[ \t]*/,  "", line); author = line; next }
            if (line ~ /^@/) next
            if (title == "") { title = line; next }
            if (brief == "") { brief = line; next }
        }
        END { printf "%s\t%s\t%s", title, brief, author }
    ' "$f")

    title=$(printf '%s' "$parsed" | cut -f1)
    brief=$(printf '%s' "$parsed" | cut -f2)
    author=$(printf '%s' "$parsed" | cut -f3)

    # title 形如 "fenwick_tree.cpp · Fenwick Tree (BIT)" → 取 · 後的專有名詞
    term=$(printf '%s' "$title" | sed -E 's/^[^·]*·[[:space:]]*//')
    [ -z "$term" ] && term="$title"
    # author 只留名字（去掉 <email>）
    aname=$(printf '%s' "$author" | sed -E 's/[[:space:]]*<[^>]*>//')

    printf '| %s | %s | %s | %s | `%s` |\n' "$cat" "$term" "$brief" "$aname" "$f" >>"$out"
done

echo "[OK] 已更新 $out"
