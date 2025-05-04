export MAX_NUM=10
python3 << EOF | cat | wc -l
# is prime

def is_prime(n: int):
    for i in range(2, n):
        if n%i == 0:
            return False
    return True

for i in range(2,$MAX_NUM):
    if is_prime(i):
        print(i)

EOF
export MAX_NUM=100
python3 << EOF | cat | wc -l
# is prime

def is_prime(n: int):
    for i in range(2, n):
        if n%i == 0:
            return False
    return True

for i in range(2,$MAX_NUM):
    if is_prime(i):
        print(i)

EOF
export MAX_NUM=1000
python3 << EOF | cat | wc -l
# is prime

def is_prime(n: int):
    for i in range(2, n):
        if n%i == 0:
            return False
    return True

for i in range(2,$MAX_NUM):
    if is_prime(i):
        print(i)

EOF
export MAX_NUM=10000
python3 << EOF | cat | wc -l
# is prime

def is_prime(n: int):
    for i in range(2, n):
        if n%i == 0:
            return False
    return True

for i in range(2,$MAX_NUM):
    if is_prime(i):
        print(i)

EOF
