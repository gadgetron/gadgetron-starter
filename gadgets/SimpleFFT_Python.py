import os
import sys
import numpy as np
from scipy import ndimage

def SimpleFFT(header, data):
    return (data).astype(np.complex64)