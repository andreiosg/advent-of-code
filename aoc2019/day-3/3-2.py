import math

def intersection(moves):
    MAX = 25000
    #could be calculated, but oh well
    FIRST_WIRE, SECOND_WIRE = 0, 1
    DIST_CALC = 2
    INTERSECTION = 2
    NWIRES = 2

    min = 2 * MAX * MAX
    #min init could be bigger, the value is derived from the thought that
    #each wire won't have a step bigger than the area of the panel
    markers = ('#', '0', 'X')

    panel = [['.' for i in range(MAX)] for i in range(MAX)]
    panel[MAX//2][MAX//2] = 'S'

    intersections = {}
    for nmove in range(NWIRES+1): 
    #+1 because we repeat iteration 1 since we didn't know the intersections then
        pos = [MAX//2, MAX//2]
        step = 0
        for move in moves[nmove%2]: 
            for i in range(int(move[1:])):
                step += 1

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
                        panel[pos[0]][pos[1]] = markers[INTERSECTION]
                        intersections[str(pos)] = step
                    else:
                        panel[pos[0]][pos[1]] = markers[SECOND_WIRE]
                elif nmove == DIST_CALC:
                    if panel[pos[0]][pos[1]] == markers[INTERSECTION]:
                        cumulative_step = intersections[str(pos)] + step
                        min = min if min <= cumulative_step else cumulative_step

    return int(min)


with open('3.txt') as f:
    moves = [(), ()]
    for i in range(2):
        moves[i] = f.readline().strip().split(',') 

print(intersection(moves))
