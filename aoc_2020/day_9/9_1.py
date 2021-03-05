def isSumNC2(preamble: list, s: int) -> bool:
    nums = set(preamble)     
    for num in preamble: 
        if s-num in nums: return True
    return False

def findInvalid(cypher: str, n: int) -> int:
    for i, num in enumerate(cypher[n:]):
        if isSumNC2(cypher[i:i+n], num): continue
        return num

with open('in.txt') as f:
    cypher = list(map(int, f.read().split()))

nPreamble = 25
print(findInvalid(cypher, nPreamble))
