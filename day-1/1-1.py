def mass2fuel(m):
    return m//3 - 2


with open('1.txt') as f:
    mass = (int(m) for m in f.readlines())

fuel = 0
for m in mass:
    fuel += mass2fuel(m)

print(fuel)

