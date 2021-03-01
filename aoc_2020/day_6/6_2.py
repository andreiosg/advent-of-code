def countAnswered(group: list) -> int:
    people = group.split()

    answered = set(list(people[0]))
    for person in people[1:]:
        answered.intersection_update(list(person))
    
    return len(answered)

with open('in.txt') as f:
    groups = f.read().split('\n\n')

sum = 0
for group in groups:
    sum += countAnswered(group)

print(sum)
