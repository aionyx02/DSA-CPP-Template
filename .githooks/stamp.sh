#!/bin/sh
# ============================================================
#  stamp.sh <file>
#  在 C++ snippet 檔頭蓋上「修改者 + 日期」並維護 @history（精簡格式）。
#  - 無檔頭 → 自動插入精簡檔頭（視當前 committer 為原作者）。
#  - 有檔頭 → 更新 @modified；@history 區塊內若今天此人尚無紀錄則補一行。
#  - 冪等：同日同人重複 commit 不會重複加 history 行。
#  - @author 一旦存在就不更動（保留原作者痕跡）。
# ============================================================
set -eu

file="$1"
name="$(git config user.name 2>/dev/null || echo unknown)"
email="$(git config user.email 2>/dev/null || echo unknown)"
today="$(date +%F)"

tmp="$(mktemp)"

# 以是否含 @modified 標記判斷檔頭是否存在
if ! grep -q '@modified' "$file" 2>/dev/null; then
    base="$(basename "$file")"
    {
        echo "// ============================================================"
        echo "//  $base · （待補專有名詞）"
        echo "//  （待補說明） · （複雜度）"
        echo "//  @author   $name <$email>"
        echo "//  @modified $today by $name"
        echo "//  @history"
        echo "//    $today $name 自動建立檔頭"
        echo "// ============================================================"
        cat "$file"
    } >"$tmp"
    mv "$tmp" "$file"
    exit 0
fi

# 已有檔頭：更新 @modified，並在 @history 區塊（區塊結束前）冪等補一行
awk -v name="$name" -v today="$today" '
    BEGIN { in_hist = 0; seen = 0 }

    /^\/\/[[:space:]]*@modified/ {
        print "//  @modified " today " by " name
        next
    }

    /^\/\/[[:space:]]*@history/ {
        print
        in_hist = 1
        seen = 0
        next
    }

    {
        if (in_hist == 1) {
            # 區塊結束（碰到分隔線 // ====）：補當日紀錄
            if ($0 ~ /^\/\/[[:space:]]*=+/) {
                if (seen == 0)
                    print "//    " today " " name " 修改"
                in_hist = 0
                print
                next
            }
            if (index($0, today) > 0 && index($0, name) > 0)
                seen = 1
            print
            next
        }
        print
    }
' "$file" >"$tmp"
mv "$tmp" "$file"
