# testsディレクトリ

## ここでは、実際にsrcに作成した関数が正しく動作するかどうかテストするプログラムがある

基本的には以下のようにする

```bash
make test TEST_FILE=<PATH/TO/TEST>
```

そうすると,rootに`test_`という名前の実行ファイルが生成される

### dummy_test

```bash
make test TEST_FILE=tests/dummy_test.c
```

