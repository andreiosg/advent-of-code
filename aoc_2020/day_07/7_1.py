import re

def hasShinyGold(bags: dict, key: str) -> bool:
    # shiny gold was found
    if 'shiny gold' in bags[key]: return True
    # innermost bag
    if not bags[key]: return False
    
    innersContain = False
    for bag in bags[key]:
        innersContain = innersContain or hasShinyGold(bags, bag)

    return innersContain

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
        # unnecessarily complex, multiple bag instances don't affect part 1
        # bags[key].append({'name': innerBag, 'n': n}) 
        bags[key].append(innerBag)

print(sum(hasShinyGold(bags, key) for key in bags))
