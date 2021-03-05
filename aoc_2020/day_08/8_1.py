def findLoopAcc(program: list) -> int:
    acc = 0

    pc = 0
    executed = [False] * len(program)
    while True:
        if executed[pc]: return acc

        executed[pc] = True

        instruction = program[pc].split()
        op, arg = instruction[0], int(instruction[1])

        if op == 'acc': acc += arg
        elif op == 'jmp': pc += arg - 1

        pc += 1

with open('in.txt') as f:
    program = f.readlines()

print(findLoopAcc(program))
