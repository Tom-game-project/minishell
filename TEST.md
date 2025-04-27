# テストケース

## バイナリテスト

リダイレクトを使ってコマンドの標準入力で渡した場合と、コマンドの引数名としてファイルを渡した場合で生成されるバイナリが同じかどうかをチェックする

```bash
export MINISHELL=minishell && ((< $MINISHELL cat  | sha256sum)  | awk '{print $1}' > outfile1) && ((sha256sum $MINISHELL | awk '{print $1}') > outfile2) && diff -u outfile1 outfile2 | wc -l
```


## アスタリスク展開の確認

アスタリスク展開されたパスのリストを縦にindexをふって出力するテスト

```bash
echo ./../minishell/src/ex*/ex*.c | awk '{for(i=1;i<=NF;i++) printf "%d:%s ", i, $i; print ""}' | tr ' ' '\n'
```


## 自分のいる場所が消されるケース

```bash
mkdir dddd && cd dddd && rmdir ../dddd && pwd && cd ..
```
