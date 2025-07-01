def solve():
    n = int(input())
    a = list(map(int, input().split()))

    # If n == 1, we can't form a valid AP with two distinct points
    if n < 2:
        print("NO")
        return

    # Compute d from the endpoints; must divide evenly among n−1 intervals
    total_diff = a[-1] - a[0]
    if total_diff % (n - 1) != 0:
        print("NO")
        return
    d = total_diff // (n - 1)

    # Verify it's really an AP
    for i, val in enumerate(a):
        if val != a[0] + i * d:
            print("NO")
            return

    # Now check the y and x numerators
    # y = (a0 − d) / (n + 1),  x = (a0 + n*d) / (n + 1)
    denom = n + 1
    y_num = a[0] - d
    x_num = a[0] + n * d

    if y_num >= 0 and x_num >= 0 and y_num % denom == 0 and x_num % denom == 0:
        print("YES")
    else:
        print("NO")

t = int(input())
for _ in range(t):
    solve()
