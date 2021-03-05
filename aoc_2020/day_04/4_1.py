def countValid(passports: list) -> int:
    nValid = 0
    delimiter = ':'
    optional = 'cid:'
    for passport in passports:
        # if we assume the same field won't reappear 
        entries = passport.count(delimiter)
        nValid += (1 if entries == 8 or entries == 7 and optional not in passport
                   else 0)

    return nValid

with open('in.txt') as f:
    # since passports are delimited by \n + the \n from the previous line
    passports = f.read().split('\n\n')


print(countValid(passports))
