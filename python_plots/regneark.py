import math as m
import matplotlib.pyplot as plt

bufferSize = 256
K = 10
MAX_DLY_TIME_ = K*256
dlySamples = 1000
sample_cntr_ = 0
currpos_array = []
dlypos_array = []
diff_array = []

# Proof of buffer position lagging constantly with delay time
for k in range(2*K):
    for i in range(bufferSize):
        currpos =  bufferSize*sample_cntr_ + i
        dly_pos = currpos - dlySamples
        if (dly_pos < 0):		
            dly_pos = MAX_DLY_TIME_ - (dlySamples - currpos)
            diff_array.append(currpos+(MAX_DLY_TIME_-dly_pos))
        else:
            diff_array.append(currpos-dly_pos)
        currpos_array.append(currpos)
        dlypos_array.append(dly_pos)
        
    sample_cntr_ += 1	
    if (sample_cntr_ >= MAX_DLY_TIME_ / 256):		
        sample_cntr_ = 0


plt.plot(currpos_array)
plt.plot(dlypos_array)
plt.plot(diff_array)
plt.show()