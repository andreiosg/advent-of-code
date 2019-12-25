def execute(intcode):
    intcode[1] = 12
    intcode[2] = 2

    pos = 0
    step = 4

    while True:
        opcode = intcode[pos+0]
        if opcode != 1 and opcode != 2 or opcode == 99:
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

print(execute(intcode))
