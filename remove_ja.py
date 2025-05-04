import re
import os

# コメントから日本語を含むものを削除し、不要な改行を除去
def remove_japanese_comments(c_code: str) -> str:
    jp_char_pattern = re.compile(r'[\u3000-\u303F\u3040-\u309F\u30A0-\u30FF\u4E00-\u9FFF]')
    comment_pattern = re.compile(
        r'(//{1,3}[^\n]*\n?|/\*.*?\*/)',
        re.DOTALL | re.MULTILINE
    )

    def replacer(match):
        comment = match.group(0)
        if jp_char_pattern.search(comment):
            # コメントの後ろに改行があれば削除（ただし改行が複数重複しないように調整）
            return '' if comment.endswith('\n') else ''
        else:
            return comment

    code = comment_pattern.sub(replacer, c_code)

    # 連続した空行を1行にまとめる
    code = re.sub(r'\n{3,}', '\n\n', code)

    # 先頭・末尾の空行も削除
    return code.strip() + '\n'

# ディレクトリ内のすべてのC/Cヘッダファイルを対象に処理
def process_directory(root_dir: str):
    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith(('.c', '.h')):
                path = os.path.join(dirpath, filename)
                with open(path, 'r', encoding='utf-8') as f:
                    code = f.read()
                new_code = remove_japanese_comments(code)
                with open(path, 'w', encoding='utf-8') as f:
                    f.write(new_code)
                print(f"処理完了: {path}")

# 使用例
process_directory('./src')
process_directory('./include')

