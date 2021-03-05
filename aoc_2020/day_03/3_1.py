def countTrees(grid: list) -> int:
    x, y = 0, 0
    slope = (3, 1)

    legend = {'.': 0, '#': 1} # empty, tree respectively

    height = len(grid)
    length = len(grid[0]) # rows are of equal length
    nTrees = 0
    while y < height:
        nTrees += legend[grid[y][x%length]]
        x, y = x+slope[0], y+slope[1]
        
    return nTrees

with open('in.txt') as f:
    grid = f.read().split()

print(countTrees(grid))

