import matplotlib.pyplot as plt

import numpy as np
from sys import argv

my_data = np.genfromtxt("BSTFind_1000.csv", delimiter=',')
print(my_data)

plt.plot(my_data[:,0], my_data[:,1])
plt.ylabel('czas [s]')
plt.xlabel('liczba elementów w tablicy')
plt.title('Czas znalezienia 10000 losowych elementów w kopcu')
plt.savefig("res.png")