import re

def cumulativeBags(bags: dict, key: str) -> int:
    # innermost bag
    if not bags[key]: return 1
    
    # itself + all the others it contains, recursively
    n = 1
    for bag in bags[key]:
        n += bag['n'] * cumulativeBags(bags, bag['name'])

    return n

with open('in.txt') as f:
    description = f.readlines()

bags = {}
for line in description:
    # the first 2 words represent the key bag
    key = ' '.join(line.split()[:2])
    bags[key] = []
    # all the bags the key bag contains, single digit bag multiplier
    items = re.findall(r'[1-9] [a-z]+ [a-z]+', line)
    for item in items:
        n = int(item[0])
        innerBag = item[2:]
        bags[key].append({'name': innerBag, 'n': n}) 

# -1 since we don't count shiny gold itself
print(cumulativeBags(bags, 'shiny gold') - 1)
