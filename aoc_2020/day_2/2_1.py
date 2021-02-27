# O(n*m) 
# n - number of lines, m - average string length

valid = 0
with open('in.txt') as f:
    for line in f:
        items = line.strip().split()

        lo, hi = map(int, items[0].split('-'))
        c = items[1][0]
        pwd = items[2]

        cnt = 0
        for pwdC in pwd:
            cnt += 1 if pwdC == c else 0

        valid += 1 if lo <= cnt <= hi else 0
        
print(valid)
        




