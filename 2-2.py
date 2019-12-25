def permute(intcode):
    lo, hi = 0, 100
    target = 19690720 

    for i in range(lo, hi+1):
        for j in range(lo, hi+1):
            if execute(intcode.copy(), i, j) == target:
                return 100*i + j


def execute(intcode, noun, verb):
    intcode[1] = noun
    intcode[2] = verb

    pos = 0
    step = 4

    while pos < len(intcode):
        opcode = intcode[pos+0]
        if opcode != 1 and opcode != 2:
            break

        op1 = intcode[intcode[pos+1]]
        op2 = intcode[intcode[pos+2]]
        inew = intcode[pos+3]
        
        if opcode == 1:
            intcode[inew] = op1 + op2
        elif opcode == 2: 
            intcode[inew] = op1 * op2

        pos += step

    return intcode[0]


with open('data/2.txt') as f:
    intcode = [int(val) for val in f.readline().split(',')]

print(permute(intcode))
