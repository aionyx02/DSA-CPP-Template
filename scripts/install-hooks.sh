#!/bin/sh
# 安裝 git hooks（Git Bash / WSL / Linux / macOS）
set -eu

cd "$(git rev-parse --show-toplevel)"

git config core.hooksPath .githooks
chmod +x .githooks/pre-commit .githooks/stamp.sh 2>/dev/null || true

echo "[OK] core.hooksPath = $(git config --get core.hooksPath)"
echo "[OK] pre-commit hook 已啟用，commit 時會自動蓋署名章。"
