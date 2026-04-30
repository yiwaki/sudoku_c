import numpy as np
import numpy.typing as npt

__version__ = "0.1.0"

def check(x: npt.NDArray[np.uint16]) -> bool: ...
def solve(x: npt.NDArray[np.uint16]) -> npt.NDArray[np.uint16]: ...
