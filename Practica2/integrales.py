import random

def f1(x):
    return x**2


def aprox_integral(n, b, a):
    sum  = 0
    for i in range(0, n):
        ui = random.uniform(0, 1)
        sum  = sum + f1(ui*(b-a) + a)
    return (b-a)/n * sum


print('aproximacion f1:', aprox_integral(10000, 1, 0))
