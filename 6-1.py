def orbit_checksum(orbits):
    checksum = 0
    for orbitee in orbits:
        checksum += traverse(orbits, orbitee)

    return checksum


def traverse(orbits, orbitee):
    if orbitee not in orbits:
        return 0

    return 1 + traverse(orbits, orbits[orbitee])


orbits = {}
with open('data/6.txt') as f:
    for line in f.readlines():
        orbit = line.strip().split(')')
        orbits[orbit[1]] = orbit[0]

print(orbit_checksum(orbits))
