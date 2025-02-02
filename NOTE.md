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

