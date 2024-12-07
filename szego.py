import numpy as np
from math import *

# F(x) = sin(x)




def Toeplitz(n, lamb):

    T = np.zeros((n, n), dtype = complex)
    for i in range(n):
        for j in range(n):
            T[i, j] = k * exp(-alpha * abs(i - j)) * cos(k * (i - j)) 
    tao, _ = np.linalg.eig(T)

    an = k * exp(-alpha * abs(n)) * cos(k * (n)) 
    flamb = np.zeros(lamb_n, dtype = complex)
    ak = np.append(T[0, n : 0 : -1], T[0, 0 : n])
    ak = np.append(ak, an)
    ak = np.append(an, ak)
    for i in range(lamb_n):
        ekl = np.exp((0+1j) * np.linspace(-n, n, 2 * n + 1, endpoint = True) * lamb[i])
        flamb[i] = sum(ak * ekl)

    return flamb, tao




lamb_n = 10000
n = 100
k = 1
alpha = 1

dlamb = 2 * pi / lamb_n
lamb = np.linspace(0, 2 * pi, lamb_n, endpoint = False)

flamb, tao = Toeplitz(n, lamb)

integ = np.sum(0.5 / pi * dlamb * lamb * np.sin(flamb))
sumg = 1 / n * np.sum(np.sin(tao))
print(integ, sumg)