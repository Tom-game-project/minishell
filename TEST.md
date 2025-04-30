# テストケース

## testをminishellの標準入力や引数に与えることで実行することが可能

## minishellはshellとして最低限使える程度の機能が実装されている

### 知られているbashとの挙動の違い

- `echo -n`のオプション複数指定の場合
    実装すべきオプションは一つであるため、重複するものを取り除いたりする必要がないため
    ```
    echo -nnn
    echo -n -n
    ```
    などはbashと同じにはならない

- `*`アスタリスク展開時のsort

- 連続したパイプの最後の要素は親プロセスで実行される
    ```bash
    echo hello | echo world | exit
    ```
    minishell, fishなどではshellを終了する
    zsh, bashなどではshellを終了しない

- minishellでは、heredoc中でascii以外の文字列は未定義
    ansiの規約に従わないので色付き文字などは正常に表示されない

- 自分のいる場所が消されるケース
    `pwd`はminishellではinodeを全く追跡しない設計にした、pwdを実行すると`No such file or directory`になるが、これはある意味間違いではなくすでに自分の今いるディレクトリがディレクトリテーブルから削除されていてマッチしないことを示す
    ```bash
    mkdir dddd && cd dddd && rmdir ../dddd &&
    pwd
    cd ..
    ```

## セルフテスト bashとほぼ同じ機能を持つことを示すテスト

以下のコマンドで、bashとminishellの挙動の違いを確認することができる
環境変数`TEST_FILE`を変更することで任意のshellとの挙動を確認することができる

```bash
touch outfile_bash outfile_minishell && rm outfile_bash outfile_minishell
export TEST_FILE=./minishell && (./minishell minishell_self_test.sh > outfile_minishell) && export TEST_FILE=bash && (bash minishell_self_test.sh > outfile_bash) && delta outfile_minishell outfile_bash
```
