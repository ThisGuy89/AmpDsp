# Python script for plotting data for Effex

import matplotlib.pyplot as plt

def readfilefunc (filename):    
    # Read file
    file = open(filename, 'r')
    samples = []
    for nsample in file:
        samples.append(nsample)    
    file.close()

    return samples
    
indata = readfilefunc('Inputstream.txt')
outdata = readfilefunc('Outputstream.txt')

plt.figure(1)

plt.subplot(211)
plt.plot(indata)
plt.ylabel('input')

plt.subplot(212)
plt.plot(outdata)
plt.ylabel('output')

plt.show()