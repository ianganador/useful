import numpy as np
import matplotlib.pyplot as plt
import matplotlib

data= np.loadtxt("1_10000.dat")

N=100
weights = np.ones_like(data)/float(len(data))
plt.hist(data, bins=N, range=(-5.,5.), weights=weights)
#plt.hist(data, normed= True, bins=N, range=(1.,1.), cumulative=True, alpha=.5)
plt.savefig('gaussrand.png')
