def binaryPartition(lo: int, hi: int, scheme: str, lc: chr) -> int:
    if lo+1 == hi: return lo if scheme[0] == lc else hi
    
    mid = int((hi+lo) / 2)
    lo, hi = (lo, mid) if scheme[0] == lc else (mid+1, hi)

    return binaryPartition(lo, hi, scheme[1:], lc)

def passID(boardPass: list) -> int:
    # F, L are for row, column lower halves respectively
    row = binaryPartition(0, 127, boardPass[:7], 'F') 
    column = binaryPartition(0, 7, boardPass[7:], 'L')

    c = 8
    return row*c + column

with open('in.txt') as f:
    passes = f.read().split()

maxID = 0
for boardPass in passes:
    val = passID(boardPass)
    maxID = val if val > maxID else maxID

print(maxID)

