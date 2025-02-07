/// exportは子プロセスを読んでいるようにみえて、親で実行する
///
/// 保持しているenvpのディクショナリ構造を、リスト構造に直してもう一度envpに渡す
///
///
/// 与えられた引数で、exportを試みられたものの環境変数をすべて設定する
///
/// ```bash
/// ❱ export hello=hello
/// ❱ export hello
/// ❱ echo $hello
/// hello
/// ```
///
///
/// ```bash
/// export hello=hello world=world
/// ```
///
/// 環境変数に使えない文字が入る場合は
/// 以下のようなエラーが出力される
/// exit status は1を返却する
/// ```
/// ❱ export =hello
/// bash: export: `=hello': not a valid identifier
/// ```

