import numpy as np

from Affichage import affichage
from Dynamique import dynamique
import Initialisation as init

init.initialisation()

log_x = []
log_dx = []
t = np.arange(0.0, init.tf, init.ts)
x = [init.theta_0, init.dtheta_0]
for dt in t:
	log_x.append([x[0]*init.R2D])
	log_dx.append(x[1])
	dx = dynamique(dt, x)
	x = [x[0] + dx[0]*init.ts, x[1] + dx[1]*init.ts]

affichage(t, log_x)
