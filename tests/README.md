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

