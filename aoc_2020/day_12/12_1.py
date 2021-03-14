def navigate(instructions: list) -> int:
    # ship normal multipliers, represents E, N, W, S respectively
    muls = ((1, 0),
            (0, 1),
            (-1, 0),
            (0, -1))

    ship = {'x': 0,
            'y': 0,
            'dir': muls[0]}

    for action, val in instructions:
        if action == 'N':
            ship['y'] += val
        elif action == 'S':
            ship['y'] -= val
        elif action == 'E':
            ship['x'] += val
        elif action == 'W':
            ship['x'] -= val
        elif action in ['L', 'R']:
            turn = 90
            sign = -1 if action == 'R' else 1
            ship['dir'] = muls[(muls.index(ship['dir'])+sign*val//turn)%len(muls)]
        elif action == 'F':
            ship['x'] += ship['dir'][0] * val
            ship['y'] += ship['dir'][1] * val

    return abs(ship['x']) + abs(ship['y'])

with open('in.txt') as f:
    instructions = [(line[0], int(line[1:-1])) for line in f]

print(navigate(instructions))
