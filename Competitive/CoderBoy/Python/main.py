#imported libraries
import math as mt
import string
import sys
from copy import deepcopy

#IO Redirection
sys.stdout = open('./out.txt', 'w')
sys.stdin = open('./in.txt', 'r')
#IO Redirection

#common computation
is_prime = [1] * 900001
is_prime[0] = 0
is_prime[1] = 0
for i in range(2, 900001):
    if(is_prime[i] == 1):
        for j in range(i + i, 900001, i):
            is_prime[j] = 0
prime = []
for i in range(2, 900001):
    if(is_prime[i] == 1):
        prime.append(i)
#common computation

def factors(n):
    fact = []
    for i in prime:
        if(n % i == 0):
            fact.append(i)
    return fact

# main logic goes here
def main():
    a,b = map(int, input().split(" "))

    x=factors(a)
    y=factors(b)

    print(x)
    print(y)

    for i in range(len(x)):
        for j in range(len(y)):
            if x[i] == y[j]:
                val = len(x)-i + len(y)-j - 1;
                #break;



#main runner program
t = int(input())
for i in range(0 ,t):
    main()
