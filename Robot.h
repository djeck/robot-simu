#ifndef ROBOT_H
#define ROBOT_H

/*
 * Paramètres d'un robot
 */
struct robot_param
{
	double ECART_ROUES; // ecart (en cm) entre les deux roues
	// nombres d'impulsion (odomètres) par tours de roue
	unsigned long int IMP_PAR_TOUR; 
	double DIAMETRE_ROUES; // diametre des roues en cm
	double VOLTAGE_BAT1_MAX; // tension de la batterie chargée
	double VOLTAGE_BAT1_MIN; // tensoin de la batterie déchargée
	double VOLTAGE_BAT2_MAX;
	double VOLTAGE_BAT2_MIN;
	double VOLTAGE_BAT3_MAX;
	double VOLTAGE_BAT3_MIN;
	double CONSO_IR; // consomation des capteurs IR
	double CONSO_ODO; // consomation des odomètres
	double CONSO_DC; // consomation des moteurs DC
};

/*
 * Données des capteurs retournés par le robot
 */
struct robot_data
{
	unsigned long int odo_l; // odométrie, remise à zéro entre deux mesures
	unsigned long int odo_r; // odométrie, remise à zéro entre deux mesures
	unsigned char bat1; // tension de la batterie 1
	unsigned char bat2; // tension de la batterie 2
	unsigned char bat3; // tension de la batterie 3
	unsigned char ir_f_l; // capteur infrarouge avant gauche
	unsigned char ir_f_r; // capteur infrarouge avant droit
	unsigned char ir_b_l; // capteur infrarouge arriere gauche
	unsigned char ir_b_r; // capteur infrarouge arriere droit
};

/*
 * Commandes a envoyer au robot
 */
struct robot_cmd
{
	/*
	 * commande du moteur gauche
	 * le premier bit donne le sens de rotation (bit de poid fort)
	 * bit 8: 1 - sens avant (anti-horaire)
	 */
	unsigned char speed_l;
	/*
	 * commande du moteur droit
	 * le premier bit donne le sens de rotation (bit de poid fort)
	 * bit 8: 1 - sens avant (horaire)
	 */
	unsigned char speed_r;
	/*
	 * Alimentation des capteurs
	 * 1 - activé 0 - désactivé
	 * bit 0 (poid faible): Infrarouge avant gauche
	 * bit 1: Infrarouge avant droit
	 * bit 2: Infrarouge arrière gauche
	 * bit 3: Infrarouge arrière droit
	 * bit 4: Odomètre gauche
	 * bit 5: Odomètre droit
	 */
	unsigned char alim_capteurs;
};

#endif // ROBOT_H
