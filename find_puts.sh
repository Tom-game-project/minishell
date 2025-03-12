#!/bin/bash

# ディレクトリの指定（デフォルトでカレントディレクトリ）
DIR="${1:-.}"

# ディレクトリ以下のすべてのオブジェクトファイルを検索
find "$DIR" -type f -name "*.o" | while read -r file; do
    # nmコマンドを実行してputsシンボルが存在するか確認
    if nm -u "$file" | grep -q "puts"; then
        # 存在する場合、ファイル名を表示
        echo "$file"
	nm -u "$file" > /dev/stdout
    fi
done

