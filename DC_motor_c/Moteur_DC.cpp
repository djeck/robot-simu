#include "Moteur_DC.h"
#include <iostream>

Moteur_DC::Moteur_DC()
{
	// initialisation des constantes
	Ka = 1.0; // pas d'amplification
	Ra = 4;
	La = 2.75e-6;
	Kt = 0.0274;
    Tl = 0.0;//2.75e-6;
	Kv = 0.0274;
	Jm = 3.2284e-6;
	Bm = 3.5077e-6;

	// valeurs initiales des constantes
	Ec = 0;
	Ea = 0;
	dIa = Ia = 0;
	Tm = 0;
	dVit = Vit = 0;
	Pos = 0;
	usure = 0.0;
}

/*
 * Modèle comportant des problèmes de stabilité
 * Basé sur des equations reels
 */
void Moteur_DC::modele_complet(double dt)
{
    // pas fixe pour l'integration
    for (double ddt = 0; ddt <dt; ddt+=1.0e-7) {
        // Entree du system: Ec
        std::cout<<"Ea "<<Ea<<std::endl;
        Ea = Ka * Ec;
        dIa = (Ea - Ia*Ra - Kv*Vit)/La;
        std::cout<<"dIa "<<dIa<<std::endl;
        Ia += ddt*dIa; // integration
        if (Ia>IA_SAT)
            Ia = IA_SAT;
        std::cout<<"Ia "<<Ia<<std::endl;
        Tm = Kt*Ia;
        std::cout<<"Tm "<<Tm<<std::endl;
        std::cout<<"Tl "<<Tm<<std::endl;
        dVit = (Tm - Tl - Bm*Vit)/Jm;
        std::cout<<"dVit "<<dVit<<std::endl;
        Vit += ddt*dVit; // integration
        if (Vit>VIT_SAT)
            Vit = VIT_SAT;
        Pos += ddt*Vit; // integration
    }
}

void Moteur_DC::process(double dt)
{
    Tm = Ec/2.3;
    dVit = Tm*1.02 - 0.5*Vit - 0.01*Vit*Vit-Tl/100;
    if (dVit > 0.8)
        usure += dVit/100;
    Vit += dt*dVit;
    Pos += dt*Vit;
}

void Moteur_DC::setCommande(double voltage)
{
	Ec = voltage;
}

void Moteur_DC::setCharge(double charge)
{
	Tl = charge;
}

double Moteur_DC::getPosition()
{
	return Pos;
}

double Moteur_DC::getSpeed()
{
	return Vit;
}

double Moteur_DC::getCouple()
{
	return Tm;
}
