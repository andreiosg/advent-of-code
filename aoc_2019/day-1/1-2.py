def mass2fuel(m):
    f = m//3 - 2

    return 0 if f <= 0 else f + mass2fuel(f)


with open('1.txt') as f:
    mass = (int(m) for m in f.readlines())

fuel = 0
for m in mass:
    fuel += mass2fuel(m)

print(fuel)

