def binaryPartition(lo: int, hi: int, scheme: str, lc: chr) -> int:
    if lo+1 == hi: return lo if scheme[0] == lc else hi
    
    mid = int((hi+lo) / 2)
    lo, hi = (lo, mid) if scheme[0] == lc else (mid+1, hi)

    return binaryPartition(lo, hi, scheme[1:], lc)

def passID(boardPass: list) -> int:
    row = binaryPartition(0, 127, boardPass[:7], 'F') 
    column = binaryPartition(0, 7, boardPass[7:], 'L')

    c = 8
    return row*c + column

with open('in.txt') as f:
    passes = f.read().split()

passIDs = [passID(boardPass) for boardPass in passes]
# account for the non present element with +1
expected = (min(passIDs)+max(passIDs)) * (len(passIDs)+1) / 2 
computed = sum(passIDs)

print(int(expected-computed))
