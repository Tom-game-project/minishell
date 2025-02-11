# testsディレクトリ

## ここでは、実際にsrcに作成した関数が正しく動作するかどうかテストする

基本的には以下のようにする

```bash
make test TEST_FILE=<PATH/TO/TEST>
```

そうすると,rootに`test_`という名前の実行ファイルが生成され,実行される


`valgrind`を使用したテストは、

```bash
make vtest TEST_FILE=<PATH/TO/TEST>
```

更に自分でオプションを設定したい場合は,

```
make vtest TEST_FILE=<PATH/TO/TEST> VALGRINDFLAGS="--leak-check=full --show-leak-kinds=all --trace-children=yes -q"
```

というふうに書く.

### dummy_test

```bash
make test TEST_FILE=tests/dummy_test.c
```

# tom_exec

parse後のastを入力にとり実行する関数のテスト

## tom_exec_test00

パイプがちゃんと繋げられているかのテスト

```bash
ls -la | grep src
```

## tom_exec_test01

`ls -la`が実行されてから、`sleep 100`が実行されることを確かめる

```bash
sleep 100 | ls -la
```

## tom_exec_test02

```bash
echo hello | echo world
```

## tom_exec_test03

```bash
ls -la | cat | grep src
```

## tom_exec_test04

```bash

```
