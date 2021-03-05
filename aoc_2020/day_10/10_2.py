def countPermutations(joltageBranches: list, joltage: int, memo: dict = {}) -> int:
    if joltage in memo:
        return memo[joltage]
    elif joltageBranches[joltage]:
        memo[joltage] = sum(countPermutations(joltageBranches, j, memo) 
                       for j in joltageBranches[joltage])
        return memo[joltage]

    return 1

with open('in.txt') as f:
    joltages = list(map(int, f.read().split()))

init = {'charging_outlet': 0, 'built_in_adapter': max(joltages) + 3}
joltages.extend(init.values())
joltages.sort()

maxStep = 3
joltageBranches = {joltage: [joltages[i+j] for j in range(1, maxStep+1)
                   if i+j < len(joltages) and joltages[i+j]-joltage <= maxStep]
                   for i, joltage in enumerate(joltages)}

print(countPermutations(joltageBranches, 0))
