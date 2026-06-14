# 安裝 git hooks（Windows / PowerShell）
# 把 hooksPath 指向版控內的 .githooks，所有人 clone 後跑一次即可。
$ErrorActionPreference = "Stop"

$repoRoot = git rev-parse --show-toplevel
Set-Location $repoRoot

git config core.hooksPath .githooks

# 確保 hook 在 Git Bash 下可執行（Windows 上權限位元通常無影響，仍設定以利 WSL/跨平台）
git update-index --chmod=+x .githooks/pre-commit .githooks/stamp.sh 2>$null

Write-Host "[OK] core.hooksPath = $(git config --get core.hooksPath)"
Write-Host "[OK] pre-commit hook 已啟用，commit 時會自動蓋署名章。"
