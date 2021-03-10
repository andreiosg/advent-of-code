def evolveGrid(grid: list) -> bool:
    movs = ((1, 0),
            (1, -1),
            (0, -1),
            (-1, -1),
            (-1, 0),
            (-1, 1),
            (0, 1),
            (1, 1))

    newGrid = [['' for seat in line] for line in grid]
   
    evolved = False
    length, height = len(grid[0]), len(grid)
    for i, line in enumerate(grid):
        for j, seat in enumerate(line):
            adjOccupied = 0
            for mov in movs:
                x, y = j, i
                while not (x+mov[0] < 0 or x+mov[0] >= length 
                      or y+mov[1] < 0 or y+mov[1] >= height):
                    x, y = x+mov[0], y+mov[1]
                    if grid[y][x] == '#':
                        adjOccupied += 1
                        break
                    elif grid[y][x] == 'L': break

            if seat == 'L' and adjOccupied == 0:
                newGrid[i][j] = '#'
            elif seat == '#' and adjOccupied >= 5:
                newGrid[i][j] = 'L'
            else:
                newGrid[i][j] = seat
                
            if seat != newGrid[i][j]: evolved = True

    for i, line in enumerate(newGrid):
        grid[i] = line

    return evolved

with open('in.txt') as f:
    grid = [line.strip() for line in f]

while evolveGrid(grid): pass

nOccupied = sum(line.count('#') for line in grid)
print(nOccupied)
