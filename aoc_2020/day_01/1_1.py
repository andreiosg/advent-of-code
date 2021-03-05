# O(nlogn)

def sum2020(expenses: list) -> int:
    sExpenses = sorted(expenses)

    l, r = 0, len(sExpenses)-1
    while l < r:
        sum = sExpenses[l] + sExpenses[r]
        if sum == 2020: 
            return sExpenses[l] * sExpenses[r]

        l, r = (l+1, r) if sum < 2020 else (l, r-1)

    return 0

with open('in.txt') as f:
    expenses = list(map(int, f.read().split()))

print(sum2020(expenses))
