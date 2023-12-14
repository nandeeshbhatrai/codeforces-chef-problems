from itertools import permutations

def pal(arr):
    return arr == arr[::-1]

def solve(N, X):
    for perm in permutations(range(1, N+1)):
        perm = list(perm)
        if perm[0] == X and pal([perm[i+1] - perm[i] for i in range(N-1)]):
            return perm
    return -1

T = int(input())
for _ in range(T):
    N, X = map(int, input().split())
    ans = solve(N, X)
    if ans == -1:
        print(-1)
    else:
        print(*ans)  