# 由模板產生新 snippet，並自動填好檔頭。
# 用法：
#   ./scripts/new-snippet.ps1 -Path 01_data_structures/tree -Name segment_tree `
#       -Brief "區間查詢 + 單點更新" -Complexity "build O(n) | query/update O(log n)"
param(
    [Parameter(Mandatory = $true)][string]$Path,        # 相對 src/ 的分類路徑
    [Parameter(Mandatory = $true)][string]$Name,        # 檔名（不含副檔名）
    [string]$Brief = "（待填）",
    [string]$Complexity = "（待填）",
    [string]$Ext = "cpp"
)
$ErrorActionPreference = "Stop"

$repoRoot = git rev-parse --show-toplevel
$tmplPath = Join-Path $repoRoot "templates/snippet.cpp.tmpl"
$destDir  = Join-Path $repoRoot (Join-Path "src" $Path)
$destFile = Join-Path $destDir "$Name.$Ext"

if (-not (Test-Path $tmplPath)) { throw "找不到模板：$tmplPath" }
if (-not (Test-Path $destDir))  { New-Item -ItemType Directory -Force -Path $destDir | Out-Null }
if (Test-Path $destFile)        { throw "檔案已存在：$destFile" }

$authorName  = (git config user.name)
$authorEmail = (git config user.email)
if ([string]::IsNullOrWhiteSpace($authorName))  { $authorName = "unknown" }
if ([string]::IsNullOrWhiteSpace($authorEmail)) { $authorEmail = "unknown" }

$date     = Get-Date -Format "yyyy-MM-dd"
$category = ($Path -replace "[\\/]", " / ")

$content = Get-Content $tmplPath -Raw
$content = $content.Replace("{{FILE}}",        "$Name.$Ext")
$content = $content.Replace("{{CATEGORY}}",    $category)
$content = $content.Replace("{{BRIEF}}",       $Brief)
$content = $content.Replace("{{COMPLEXITY}}",  $Complexity)
$content = $content.Replace("{{AUTHOR}}",      "$authorName <$authorEmail>")
$content = $content.Replace("{{AUTHOR_NAME}}", $authorName)
$content = $content.Replace("{{DATE}}",        $date)

# 以 LF 寫出，與 .gitattributes 一致
$content = $content -replace "`r`n", "`n"
[System.IO.File]::WriteAllText($destFile, $content)

Write-Host "[OK] 已建立：$destFile"
