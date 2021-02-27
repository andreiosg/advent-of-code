# O(n*m) 
# n - number of lines, m - average string length

def countValid(lines: list) -> int:
    valid = 0
    for line in lines:
        items = line.strip().split()

        lo, hi = map(int, items[0].split('-'))
        c = items[1][0]
        pwd = items[2]

        cnt = 0
        for pwdC in pwd:
            cnt += 1 if pwdC == c else 0

        valid += 1 if lo <= cnt <= hi else 0

    return valid

with open('in.txt') as f:
    lines = f.readlines()
        
print(countValid(lines))
        




