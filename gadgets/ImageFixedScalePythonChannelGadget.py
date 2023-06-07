import os
import sys
import numpy as np
from scipy import ndimage

def scaleImageData(header, data, scaleFactor):
    return (data*scaleFactor).astype(np.float32)