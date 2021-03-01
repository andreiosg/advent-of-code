def countAnswered(group: list) -> int:
    answered = set()
    for person in group.split():
        answered.update(list(person))
    
    return len(answered)

with open('in.txt') as f:
    groups = f.read().split('\n\n')

print(sum([countAnswered(group) for group in groups]))
