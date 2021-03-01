def countAnswered(group: list) -> int:
    answered = set()
    for person in group.split():
        answered.update(list(person))
    
    return len(answered)

with open('in.txt') as f:
    groups = f.read().split('\n\n')

sum = 0
for group in groups:
    sum += countAnswered(group)

print(sum)
