def traverse(path, orbits, orbitee):
    if orbitee not in orbits:
        return 
    
    path.append(orbitee)
    traverse(path, orbits, orbits[orbitee])

# works because all orbit paths lead to the center of mass
def dist2santa(orbits):
    you = []
    traverse(you, orbits, orbits['YOU'])
    santa = []
    traverse(santa, orbits, orbits['SAN'])

    for planet in you:
        if planet in santa:
            return you.index(planet) + santa.index(planet)


orbits = {}
with open('6.txt') as f:
    for line in f.readlines():
        orbit = line.strip().split(')')
        orbits[orbit[1]] = orbit[0]

print(dist2santa(orbits))
