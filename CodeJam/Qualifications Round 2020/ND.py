def main():

    T = int(input())

    for i in range(T):
        S = input()
        parentheses = ''

        d = int(S[0])
        aux = d
        parentheses = ('('*d) + str(d) + (')'*d)

        for j in range(1, len(S)):
            d = int(S[j])
            l = aux if (aux <= d) else d
            dif = len(parentheses) - l
            left = parentheses[:dif]
            rigth = parentheses[dif:]
            add = ('('*(d-aux)) + str(d) + (')'*(d-aux)) if (aux <= d) else str(d)
            aux = d
            parentheses = left + add + rigth


        print("Case #{}: {}".format(i+1 , parentheses))

if __name__ == '__main__':
    main()