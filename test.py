import numpy as np
import time
from sudoku import c_brute_force

filepath = "data/evil_3.csv"
x = np.loadtxt(filepath, delimiter=",").astype(np.uint16)
print("Puzzle:")
print(x)

start = time.process_time()
y = c_brute_force(x)
end = time.process_time()
elapsed = end - start

print("Solution:")
print(y)

print(f"elapsed time: {elapsed:.6f}")
