def fixCorrupt(program: list) -> int:
    corrupt = {'nop': 'jmp', 'jmp': 'nop'}

    for i, instruction in enumerate(program):
        op  = instruction.split()[0]

        if op in corrupt:
            fixedProgram = list(program)
            fixedProgram[i] = fixedProgram[i].replace(op, corrupt[op])

            acc = checkTerminable(fixedProgram)

            if acc == None: continue

            return acc

def checkTerminable(program: list) -> int:
        acc = 0

        pc = 0
        executed = [False] * len(program)
        while True:
            # last instruction was executed
            if pc == len(program): return acc
            # loop continues
            if executed[pc]: return None

            executed[pc] = True

            instruction = program[pc].split()
            op, arg = instruction[0], int(instruction[1])

            if op == 'acc': acc += arg
            elif op == 'jmp': pc += arg - 1

            pc += 1

with open('in.txt') as f:
    program = f.readlines()

print(fixCorrupt(program))
