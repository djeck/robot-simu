import math
from Control import control
import Initialisation as init

#
# x = [theta, dtheta/dt] = [x1, x2]
#
def dynamique (t, x):
	u = control(t, x) # tau
	x1 = x[0] # en radian
	x2 = x[1]

	dx = [0, 0]
	dx[0] = x2 # dtheta/dt
	dx[1] = -(init.g/init.l) * math.sin(x1) - (init.beta/init.m) * x2 + (1/(init.m*init.l*init.l)) * u

	return dx
