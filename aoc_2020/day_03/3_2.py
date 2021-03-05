def countTrees(grid: list, slope: tuple) -> int:
    x, y = 0, 0

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

slopes = ((1, 1),
          (3, 1),
          (5, 1),
          (7, 1),
          (1, 2))

product = 1
for slope in slopes:
    product *= countTrees(grid, slope)

print(product)
    

          


