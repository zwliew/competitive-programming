A = set(input().split(' '))
N = int(input())
is_superset = True
for i in range(N):
    B = set(input().split(' '))
    if not B < A:
        is_superset = False
        break
if is_superset:
    print('True')
else:
    print('False')
