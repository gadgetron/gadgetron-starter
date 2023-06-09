import os
import sys
import numpy as np
from scipy import ndimage

def SimpleFFT(header, data):
    #print(header)
    #print(np.shape(data))
    return (data).astype(np.complex64)