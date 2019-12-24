import math

def mass2fuel(m):
    return math.floor(m/3) - 2


with open('data/1.txt') as f:
    mass = (int(m) for m in f.readlines())

fuel = 0
for m in mass:
    fuel += mass2fuel(m)

print(fuel)

