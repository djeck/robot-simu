def initialisation():
	global l, m, b, g, pi, R2D, D2R, beta
	l = 0.5
	m = 0.2
	b = 1
	g = 9.8
	beta = 0.05 # coefficient d'amortissement
	pi = 3.141592658358
	R2D = 180/pi
	D2R = pi/180

	global theta_0, dtheta_0, x0, tf, ts
	theta_0 = 75*D2R
	dtheta_0 = 0
	x0 = [theta_0, dtheta_0]
	tf = 4
	ts = 0.0001

	global K, theta_d
	K = 1000
	theta_d = -75*D2R
