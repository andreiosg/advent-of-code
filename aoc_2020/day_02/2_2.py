# O(n) 
# n - number of lines

def countValid(lines: list) -> int:
    valid = 0
    for line in lines:
        items = line.strip().split()

        l, r = map(int, items[0].split('-'))
        c = items[1][0]
        pwd = items[2]

        valid += 1 if (pwd[l-1] == c) != (pwd[r-1] == c) else 0

    return valid

with open('in.txt') as f:
    lines = f.readlines()
        
print(countValid(lines))
