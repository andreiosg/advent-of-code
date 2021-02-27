# O(n) 
# n - number of lines

valid = 0
with open('in.txt') as f:
    for line in f:
        items = line.strip().split()

        l, r = map(int, items[0].split('-'))
        c = items[1][0]
        pwd = items[2]

        valid += 1 if (pwd[l-1] == c) != (pwd[r-1] == c) else 0
        
print(valid)
