import numpy as np
import time
from sudoku_c import solve

filepath = "data/evil_3.csv"
x = np.loadtxt(filepath, delimiter=",").astype(np.uint16)
print("Puzzle:")
print(x)

start = time.process_time()
y = solve(x)
end = time.process_time()
elapsed = end - start

print("Solution:")
print(y)

print(f"elapsed time: {elapsed:.6f}")
