import os
import sys
import numpy as np
import torch
from scipy import ndimage, fft

def SimpleFFT(rawData, device=None):
    try:
        if(device==None):
            if torch.cuda.is_available():
                device = torch.device("cuda")
            else:
                device = torch.device("cpu")
        print(device)
        matrixSize = rawData.shape[0:3]
        numCoils = rawData.shape[3]
        coilImages = torch.zeros(rawData.shape[0:4], dtype=torch.complex64).to(device)
        rawData_dev = torch.tensor(rawData).to(device)
        for coil in np.arange(0,numCoils):
            for slice in np.arange(0,matrixSize[2]):
                    coilImages[:,:,slice,coil] = torch.fft.fftshift(torch.fft.fft2(torch.fft.fftshift(rawData_dev[:,:,slice, coil,:].squeeze())))
        coilCombined = torch.abs(torch.sum(coilImages**2,axis=3))
        return (coilCombined.cpu().numpy()).astype(np.float32)
    except Exception as error:
        print(error)
        return np.zeros((256,256,1))