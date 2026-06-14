# 快速搜尋 snippet：比對檔頭的檔名 / 專有名詞 / 說明 / 作者。
# 用法：
#   ./scripts/find.ps1 mod
#   ./scripts/find.ps1 "binary search"
#   ./scripts/find.ps1 Andy
param(
    [Parameter(Mandatory = $true, Position = 0)][string]$Query
)
$ErrorActionPreference = "Stop"

$root = git rev-parse --show-toplevel
$src  = Join-Path $root "src"
$hits = 0

Get-ChildItem -Path $src -Recurse -File -Include *.h, *.hpp, *.cpp, *.cc, *.cxx, *.hh |
    Sort-Object FullName | ForEach-Object {
        $head = Get-Content $_.FullName -TotalCount 12
        if (($head -join "`n") -match [regex]::Escape($Query)) {
            # 標題列 = 邊框後第一條非 @ 的註解
            $title = ($head | Where-Object {
                    $_ -match '^//\s+\S' -and $_ -notmatch '^//\s*=+\s*$' -and $_ -notmatch '@'
                } | Select-Object -First 1) -replace '^//\s*', ''
            $rel = $_.FullName.Substring($root.Length + 1) -replace '\\', '/'
            $hits++
            Write-Host ("  {0,-50} " -f $title) -NoNewline
            Write-Host $rel -ForegroundColor DarkGray
        }
    }

if ($hits -eq 0) {
    Write-Host "找不到符合 '$Query' 的 snippet。"
} else {
    Write-Host ""
    Write-Host "共 $hits 筆。" -ForegroundColor Green
}
