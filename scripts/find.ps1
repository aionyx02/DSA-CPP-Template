# 快速搜尋 snippet：比對檔名 / 專有名詞標題 / 說明 / 作者。
# （刻意不比對 @modified / @history，避免日期、"mod" 等雜訊誤中。）
# 用法：
#   ./scripts/find.ps1 mod
#   ./scripts/find.ps1 "binary search"
#   ./scripts/find.ps1 Andy
param(
    [Parameter(Mandatory = $true, Position = 0)][string]$Query
)
$ErrorActionPreference = "Stop"

$root = git rev-parse --show-toplevel
$src = Join-Path $root "src"
$hits = 0

$files = Get-ChildItem -Path $src -Recurse -File -Include *.h, *.hpp, *.cpp, *.cc, *.cxx, *.hh | Sort-Object FullName

foreach ($file in $files) {
    $head = Get-Content $file.FullName -TotalCount 12 -Encoding UTF8

    # 抽出標題列、說明列、作者名（只在這些欄位搜尋）
    $title = ""
    $brief = ""
    $author = ""
    foreach ($line in $head) {
        if ($line -match '^//\s*@author\s*(.+)$') {
            $author = ($Matches[1] -replace '\s*<[^>]*>', '').Trim()
        } elseif ($line -match '^//\s+\S' -and $line -notmatch '^//\s*=+\s*$' -and $line -notmatch '@') {
            if ($title -eq "") { $title = ($line -replace '^//\s*', '') }
            elseif ($brief -eq "") { $brief = ($line -replace '^//\s*', '') }
        }
    }

    $haystack = "$($file.Name) $title $brief $author"
    if ($haystack -notmatch [regex]::Escape($Query)) { continue }

    $rel = $file.FullName.Substring($root.Length + 1) -replace '\\', '/'
    $hits++
    $label = if ($title) { $title } else { $file.Name }
    $label = $label -replace '\s*·\s*', ' | '   # 中點改 ASCII，避免主控台亂碼
    Write-Host "  $label"
    Write-Host "      -> $rel" -ForegroundColor DarkGray
}

if ($hits -eq 0) {
    Write-Host "找不到符合 '$Query' 的 snippet。"
} else {
    Write-Host ""
    Write-Host "共 $hits 筆。" -ForegroundColor Green
}
