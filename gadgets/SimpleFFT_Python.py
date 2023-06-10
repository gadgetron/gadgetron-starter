import os
import sys
import numpy as np
from scipy import ndimage

def SimpleFFT(header, data):
    print(header)
    print(np.shape(data))
    newImage = np.zeros((256,256,60))
    return (newImage).astype(np.complex64)