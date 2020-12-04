def count_matching(lo, hi):
    cnt = 0
    for n in range(lo, hi+1):
        inc = 0
        while n // 10 > 0:
            ones = n % 10
            n //= 10
            tens = n % 10
            if ones == tens:
                inc = 1
            if ones < tens:
                inc = 0
                break
        cnt += inc

    return cnt


with open('4.txt') as f:
    interval = tuple(int(n) for n in f.readline().split('-'))

print(count_matching(*interval))



