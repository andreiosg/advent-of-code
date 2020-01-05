import math

def intersection(moves):
    MAX = 25000
    #could be calculated, but oh well
    FIRST_WIRE, SECOND_WIRE = 0, 1
    INTERSECTION = 2
    NWIRES = 2

    min = 2 * MAX
    #can't be bigger than the init value since we're talking manhattan distances
    #if MAX is a 'well' chose value xd
    markers = ('#', '0', 'X')

    panel = [['.' for i in range(MAX)] for i in range(MAX)]
    panel[MAX//2][MAX//2] = 'S'

    for nmove in range(NWIRES):
        pos = [MAX//2, MAX//2]
        for move in moves[nmove]:
            for i in range(int(move[1:])):
                if move[0] == 'U':
                    pos[0] += -1
                elif move[0] == 'D':
                    pos[0] += 1
                elif move[0] == 'L':
                    pos[1] += -1
                elif move[0] == 'R':
                    pos[1] += 1

                if nmove == FIRST_WIRE:
                    panel[pos[0]][pos[1]] = markers[FIRST_WIRE]
                elif nmove == SECOND_WIRE:
                    if panel[pos[0]][pos[1]] == markers[FIRST_WIRE]:
                        manhattan = math.fabs(pos[0]-MAX//2) + math.fabs(pos[1]-MAX//2)
                        min = min if min <= manhattan else manhattan
                        panel[pos[0]][pos[1]] = markers[INTERSECTION]
                    else:
                        panel[pos[0]][pos[1]] = markers[SECOND_WIRE]

    return int(min)


with open('3.txt') as f:
    moves = [(), ()]
    for i in range(2):
        moves[i] = f.readline().strip().split(',') 

print(intersection(moves))
