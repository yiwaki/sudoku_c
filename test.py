import numpy as np
from sudoku import c_brute_force

filepath = "data/evil_3.csv"
x = np.loadtxt(filepath, delimiter=",").astype(np.uint16)
print("Puzzle:")
print(x)

y = c_brute_force(x)

print("Solution:")
print(y)
