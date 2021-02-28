def countValid(passports: list) -> int:
    nValid = 0
    delimiter = ':'
    optional = 'cid:'
    for passport in passports:
        items = passport.strip().split()
        entries = 0
        for item in items:
            field, val = item.split(delimiter)
            
            if field == 'byr':
                entries += (1 if len(val) == 4 and 1920 <= int(val) <= 2002 
                            else 0)
            elif field == 'iyr':
                entries += (1 if len(val) == 4 and 2010 <= int(val) <= 2020 
                            else 0)
            elif field == 'eyr':
                entries += (1 if len(val) == 4 and 2020 <= int(val) <= 2030 
                            else 0)
            elif field == 'hgt':
                if val[-2:] == 'cm':
                    entries += 1 if 150 <= int(val[:-2]) <= 193 else 0
                elif val[-2:] == 'in':
                    entries += 1 if 59 <= int(val[:-2]) <= 76 else 0
            elif field == 'hcl':
                entries += 1 if val[0] == '#' and len(val[1:]) == 6 else 0
            elif field == 'ecl':
                colors = ('amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth')
                entries += 1 if val in colors else 0
            elif field == 'pid':
                entries += 1 if len(val) == 9 else 0

        nValid += 1 if entries == 7 else 0
                
    return nValid

with open('in.txt') as f:
    # since entries are delimited by \n + the \n from the previous line
    passports = f.read().split('\n\n')


print(countValid(passports))
