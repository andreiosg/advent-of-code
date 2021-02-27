# O(n^3)

def sum2020(expenses : list):
    n = len(expenses)
    for i in range(n):
            for j in range(n):
                for k in range(n):
                    # 3C2 = 3 combinations for comparison 
                    sum = (expenses[i] + expenses[j] + expenses[k]
                    if i != j and j != k and i != k else None)

                    if sum == 2020: 
                        return expenses[i] * expenses[j] * expenses[k]

with open('in.txt') as f:
    expenses = [int(expense) for expense in f.read().split()]

print(sum2020(expenses))
