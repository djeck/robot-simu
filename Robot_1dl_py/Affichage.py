import matplotlib
import matplotlib.pyplot as plt
import numpy as np

def affichage(t, x):
	fig, ax = plt.subplots()
	ax.plot(t, x)

	ax.set(xlabel='time (s)', ylabel='voltage (mV)',
		   title='About as simple as it gets, folks')
	ax.grid()

	fig.savefig("test.png")
	plt.show()
