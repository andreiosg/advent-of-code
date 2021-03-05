def generateSteps(joltages: list) -> dict:
    sJoltages = list(joltages)
    sJoltages.sort()

    return [sJoltages[i+1]-sJoltages[i] for i in range(len(sJoltages)-1)]

with open('in.txt') as f:
    joltages = list(map(int, f.read().split()))

init = {'charging_outlet': 0, 'built_in_adapter': max(joltages) + 3}
joltages.extend(init.values())

steps = generateSteps(joltages)

print(steps.count(1)*steps.count(3))
