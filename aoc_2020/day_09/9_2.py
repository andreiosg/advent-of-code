def isSumNC2(preamble: list, s: int) -> bool:
    nums = set(preamble)     
    for num in preamble: 
        if s-num in nums: return True
    return False

def findInvalid(cypher: str, n: int) -> int:
    for i, num in enumerate(cypher[n:]):
        if isSumNC2(cypher[i:i+n], num): continue
        return num

# O(n) scaling window algorithm
def invalidSubsum(cypher: list, invalid: int) -> list:
    subsum = 0
    l = 0
    for r, rnum in enumerate(cypher):
        # r isn't inclusive since it's incremented once more
        if subsum == invalid: return cypher[l:r]

        subsum += rnum

        while subsum > invalid:
            subsum -= cypher[l]
            l += 1

with open('in.txt') as f:
    cypher = list(map(int, f.read().split()))

nPreamble = 25
invalid = findInvalid(cypher, nPreamble)

subsum = invalidSubsum(cypher, invalid)

print(min(subsum)+max(subsum))
