# minishell

## ディレクトリの構造
- src
  - sig
    割り込みの処理
    `ctrl-C`
    `ctrl-D`
    `ctrl-\`
  - parser
    入力された文字列の解釈
  - pipe
    パイプ

## 入力補完lsp他設定

`-I`オプションを使ってコンパイルしているため、開発中にlspがパスを考慮してくれないかもしれないその場合はbearを使って`compile_commands.json`を生成する

```
bear -- make
```
