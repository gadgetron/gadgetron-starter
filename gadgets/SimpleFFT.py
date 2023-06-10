import os
import sys
import numpy as np
from scipy import ndimage, fft

def SimpleFFT(rawData):
    matrixSize = rawData.shape[0:3]
    numCoils = rawData.shape[3]
    coilImages = np.zeros(rawData.shape[0:4], dtype=np.complex64)
    for coil in np.arange(0,numCoils):
        for slice in np.arange(0,matrixSize[2]):
            try:
                coilImages[:,:,slice,coil] = fft.fftshift(fft.fft2(fft.fftshift(rawData[:,:,slice, coil,:].squeeze())))
            except Exception as error:
                print(error)

    coilCombined = np.abs(np.sum(coilImages**2,axis=3))
    return (coilCombined).astype(np.float32)