#ifndef MOTEUR_DC_H
#define MOTEUR_DC_H

#define IA_SAT 10 // à partir de la saturation en A le moteur s'use
#define VIT_SAT 100000 // à partir de la 'saturation' qui est la vitesse maximum recommandée le moteur s'use

class Moteur_DC
{
public:
	Moteur_DC();
    /*
     * @brief calcul de la position vitesse...
     * @arg dt, pas pour le calcul, il est recommandé qu'il soit le plus petit possible
     * au maximum 1e-4
     */
	void process(double dt);
    /*
     * @brief changer la tension de commande
     * @param voltage, nouvelle tension, en V
     */
	void setCommande(double voltage);
    /*
     * @brief changer la charge du moteur
     * @param nouvelle charge, en kg
     */
	void setCharge(double charge);
    /*
     * @return position de la roue, en cm
     * pour obtenir la position angulaire la
     * diviser par le diametre de la roue et modulo 2pi
     */
	double getPosition();
    /*
     * @return retourne la vitesse de rotation du moteur
     * pour obtenir la vitesse angulaire la
     * diviser par le diametre de la roue et modulo 2pi
     */
    double getSpeed();
    /*
     * @return retourne le couple du moteur
     */
    double getCouple();
private:
    /*
     * @brief fonction de calcul de la position... à partir
     * d'un modèle 'complet' de moteur DC
     * TODO: rendre le modèle plus stable
     */
    void modele_complet(double dt);

	// Paramètres du moteur
	double Ka; // gain de l'ampli de puissance
	double Ra; // resistance de l'armature (Ohms)
	double La; // inductance de l'armature (H)
	double Kt; // constante de couple (N.m/A)
	double Tl; // charge du moteur (N.m)
	double Kv; // constante de vitesse (V/rad/s)
	double Jm; // inertie
	double Bm; // coefficient de friction

	// Variables intermediaires du moteur
	double Ec; // tension de commande (V)
	double Ea; // tension appliquée sur l'armature (V)
	double dIa, Ia; // courant dans l'armature
	double Tm; // couple du moteur
	double dVit, Vit; // vitesse angulaire
	double Pos; // position angulaire du rotor

    double usure; // usure arbitraire du moteur
};

#endif // MOTEUR_DC_H
