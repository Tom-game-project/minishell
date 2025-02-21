# parse testcase

通常
```c
echo hello
```
ctl_or
```c
echo hello || ls -la
```
ctl_and
```c
echo hello && ls -la
```
rdt_rdt_out
```c
echo hello > outfile
echo hello>outfile
```
rdt_rdt_in
```c
cat < infile
cat<infile
< infile cat
```
rdt_pipe
```c
ls -la | grep .c
```
rdt_heardoc_in
```c
<< EOF echo
echo<<EOF
```
rdt_heardoc_out
```c
>> outfile cat outfile
cat outfile>>outfile
```
```c

```
```c

```
```c

```
```c

```
```c

```
```c

```
```c

```


# parse要件
課題で要求されていない、閉じられていない引用符や特殊文字（例: \（バックスラッシュ）、;（セミコロン）など）を解釈しないこと。

シングルクォート ' を適切に処理し、引用されたシーケンス内のメタ文字の解釈を防ぐこと。

ダブルクォート " を適切に処理し、引用されたシーケンス内のメタ文字（ただし $（ドル記号）を除く）の解釈を防ぐこと。

リダイレクションを実装すること:
```
< は入力をリダイレクトする。
> は出力をリダイレクトする。
<< は区切り文字を指定し、その区切り文字を含む行が現れるまで入力を読み取る（ただし、履歴を更新する必要はありません）。
>> は出力を追記モードでリダイレクトする。
パイプ（| 文字）を実装すること。パイプライン内の各コマンドの出力は、次のコマンドの入力にパイプを通じて接続されます。
```

環境変数（$ に続く文字列）を適切に処理し、それらの値に展開すること。

$? を処理し、直前に実行されたフォアグラウンドパイプラインの終了ステータスに展開すること。
優先順位を示すための括弧を用いた && と || を実装すること。

## operatorの挙動

### &&
```
左側のコマンドが成功（終了ステータス = 0）の場合のみ、右側のコマンドを実行する。

左側のコマンドが失敗（終了ステータス ≠ 0）の場合、右側のコマンドは実行されない。
```

### ||
```
左側のコマンドが失敗（終了ステータス ≠ 0）した場合に、右側のコマンドを実行する。

左側のコマンドが成功（終了ステータス = 0）した場合、右側のコマンドは実行されない
```

```c
echo $(ls -la | cat > outfile) | grep infile

struct s_ast
{
	t_ast *next_ast: 
		struct s_ast
		{
			t_ast *next_ast;
			t_operator ope; 
			t_ast *down_ast;
			char *cmd; grep
			char *argv; infile
        };
	t_operator ope; | 
	t_ast *down_ast;
		struct s_ast
		{
			t_ast *next_ast;
				struct s_ast
				{
					t_ast *next_ast; ls -la 
					t_operator ope; |
					t_ast *down_ast;  cat > outfile
					char *cmd; NULL
					char *argv; NULL
				};
			t_operator ope;
			t_ast *down_ast;
			char *cmd; echo
			char *argv; NULL
        };
	char *cmd; //= NULL
	char *argv; // = NULL
};

```
