import scipy.integrate as si
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(1, 10, 0.1)
dy = lambda y, x : -2 * y + x * x + 2 * x
sol = si.odeint(dy, 2, x)
plt.plot(x, sol)
plt.show()
