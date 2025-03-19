# 知見

文字列を結合することができる
```bash
echo "文字列の""結合"
```

## `"` `'`の違い

```bash
echo "$PATH"
```

```bash
echo '$PATH'
```

## 正しいケース

```bash
echo '$PATH'" Tom""'""s home Party "'"'"$PATH"'"'
```

```
echo """'''"'"""'
```

## 入力補完lsp他設定

`-I`オプションを使ってコンパイルしているため、開発中にlspがパスを考慮してくれないかもしれないその場合はbearを使って`compile_commands.json`を生成する

```
bear -- make
```
