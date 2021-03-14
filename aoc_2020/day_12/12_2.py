import math

def navigate(instructions: list) -> int:
    ship = {'x': 0,
            'y': 0}

    waypoint = {'x': 10,
                'y': 1,}

    turn = 90

    for action, val in instructions:
        if action == 'N':
            waypoint['y'] += val
        elif action == 'S':
            waypoint['y'] -= val
        elif action == 'E':
            waypoint['x'] += val
        elif action == 'W':
            waypoint['x'] -= val
        elif action in ['L', 'R']:
            a, b = (-1, 1) if action == 'L' else (1, -1)
            x, y = waypoint['x'], waypoint['y']
            for i in range(val//turn):
                x, y = a*y, b*x
            waypoint['x'], waypoint['y'] = x, y
        elif action == 'F':
            ship['x'] += val*waypoint['x']
            ship['y'] += val*waypoint['y'] 

    return abs(ship['x']) + abs(ship['y'])

with open('in.txt') as f:
    instructions = [(line[0], int(line[1:-1])) for line in f]

print(navigate(instructions))
