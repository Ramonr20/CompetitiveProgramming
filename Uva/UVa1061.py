from sys import stdin

comb = {
    'A A':'A',
    'A B':'AB',
    'A O':'A',
    'B B':'B',
    'B O':'B',
    'O O':'O'
}

def readTypes():
    return stdin.readline()

def findLetters(f, m):
    lettersF = ''
    lettersM = ''
    for l,t in comb.items():
        if f == t:
            lettersF = lettersF + l + ' '
        if m == t:
            lettersM = lettersM + l + ' '
    return lettersF,lettersM

def findChildLetters(c):
    letter = list()
    for l,t in comb.items():
        if c == t:
            letter.append(l)
    return letter

def searchParent(lettersM, lettersC):
    possible = list()
    for allelef in lettersM:
        for li in comb:
            allelel, alleler = li.split()
            combination1 = chr(min(ord(allelef),ord(allelel))) + ' ' + chr(max(ord(allelef), ord(allelel)))
            combination2 = chr(min(ord(allelef),ord(alleler))) + ' ' + chr(max(ord(allelef), ord(alleler)))
            for co in lettersC:
                if combination1 == co:
                    possible.append(comb[li])
                if combination2 == co:
                    possible.append(comb[li])
    return possible

def replace(s):
    typ = s
    for ch in ['-','+']:
        if ch in s:
            typ = s.replace(ch,'')
    return typ

def getPossibleForChild(possible, f, m): 
    LIST = '{'
    fl = f[-1]
    ml = m[-1]
    if fl == '-' and ml == '-':
        if len(possible) == 1:
            return possible[0] + '-'
            
        for i, t in enumerate(possible):
            if i == 0:
                LIST = LIST + t + '-'
            else:
                LIST = LIST + ', ' + t + '-'
        LIST = LIST + '}'
        return LIST
    else:
        for i, t in enumerate(possible):
            if i == 0:
                LIST = LIST + t + '-'
                LIST = LIST + ', ' + t + '+'
            else:
                LIST = LIST + ', ' + t + '-'
                LIST = LIST + ', ' + t + '+'
        LIST = LIST + '}'
        return LIST

def getPossibleForPartents(possible, p, c):
    LIST = '{'
    if p[-1] == '-' and c[-1] == '+':
        if len(possible) == 1:
            return possible[0] + '+'
        else:
            for i, t in enumerate(possible):
                if i == 0:
                    LIST = LIST + t + '+' 
                else:
                    LIST = LIST + ', ' + t + '+'
            LIST = LIST + '}'
            return LIST
    else:
        for i, t in enumerate(possible):
            if i == 0:
                LIST = LIST + t + '-'
                LIST = LIST + ', ' + t + '+'
            else:
                LIST = LIST + ', ' + t + '-'
                LIST = LIST + ', ' + t + '+'
        LIST = LIST + '}'
        return LIST

def main():

    I = 1
    while True:
        possible = list()        
        lettersF = list()
        lettersM = list()
        lettersC = list()
        LIST = ''

        # F, M, C = readTypes()
        types = readTypes()
        if types == '\n':
            continue
        else:
            F, M, C = types.split()
            f = replace(F)
            m = replace(M)
            c = replace(C)

            if f == 'E':
                break

            if c == '?':
                lettersF, lettersM = findLetters(f,m)
                lettersF = list(set(lettersF.split()))
                lettersM = list(set(lettersM.split()))

                for alleleF in lettersF:
                    for alleleM in lettersM:
                        if ord(alleleF) < ord(alleleM):
                            combination = alleleF + ' ' + alleleM
                        else: 
                            combination = alleleM + ' ' + alleleF
                        for c,t in comb.items():
                            if c == combination:
                                possible.append(t)
                                possible.append(t)    
                possible = list(set(possible))
                LIST = getPossibleForChild(possible, F, M)
                print("Case {}: {} {} {}".format(I,F,M,LIST))

            if f == '?' or m == '?':
                lettersC = findChildLetters(c)   
                if m == '?':
                    lettersF, lettersM = findLetters(f,'N')
                    lettersF = list(set(lettersF.split()))
                    possible = searchParent(lettersF, lettersC)
                    if len(possible) == 0:
                        print("Case {}: {} IMPOSSIBLE {}".format(I,F,C))
                    else:                
                        possible = set(possible)
                        LIST = getPossibleForPartents(possible, F, C)
                        print("Case {}: {} {} {}".format(I,F,LIST,C))

                if f == '?':
                    lettersF, lettersM = findLetters('N',m)
                    lettersM = list(set(lettersM.split()))
                    possible = searchParent(lettersM, lettersC)
                    if len(possible) == 0:
                        print("Case {}: IMPOSSIBLE {} {}".format(I,M,C))
                    else:
                        possible = set(possible)
                        LIST = getPossibleForPartents(possible, M, C)
                        print("Case {}: {} {} {}".format(I,LIST,M,C))
            I = I + 1
if __name__ == '__main__':
    main()