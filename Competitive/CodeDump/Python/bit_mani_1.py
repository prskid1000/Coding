#imported libraries
import math as mt
import string
import sys

#IO Redirection
sys.stdout = open('./out.txt', 'w')
sys.stdin = open('./in.txt', 'r')
#IO Redirection

#common computation
plist = [[1]]
for i in range(1, 10):
    tlist = [1] + plist[i - 1][:]
    for j in plist[i - 1]:
        tlist.append(j + 1)
    plist.append(tlist)
    #print(plist)

#common computation

# main logic goes here
def main():
    a,b = map(int, input().split(" "))

    clist = plist[a - 1][:]
    #print(clist)
    for i in range(1, b):
        tlist = []
        for j in clist:
            for k in plist[a - 1][:]:
                tlist.append(j + k)
        clist = tlist[:]
    #print(clist)

    sum  = 0
    for i in clist:
        sum = sum + i * i

    den = pow((pow(2, a) - 1), b)
    mod = pow(10, 9) + 7
    #print(sum)
    #print(den)

    print(((sum % mod) / (den % mod) % mod))
    


#main runner program
t = int(input())
for i in range(0 ,t):
    main()
