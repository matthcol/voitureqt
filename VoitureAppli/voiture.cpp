#include "voiture.h"

Voiture::Voiture():Voiture("",0,0)
{

}

Voiture::Voiture(QString modele):Voiture(modele,0,0)
{

}

Voiture::Voiture(QString modele, int kilometrage, int jaugeCarburant):
    mModele(modele), mKilometrage(kilometrage), mJaugeCarburant(jaugeCarburant)
{
}

Voiture::~Voiture()
{

}

QString Voiture::modele() const
{
    return mModele;
}

void Voiture::setModele(const QString &modele)
{
    mModele = modele;
}

int Voiture::kilometrage() const
{
    return mKilometrage;
}

void Voiture::setKilometrage(int kilometrage)
{
    mKilometrage = kilometrage;
}

int Voiture::jaugeCarburant() const
{
    return mJaugeCarburant;
}

void Voiture::setJaugeCarburant(int jaugeCarburant)
{
    mJaugeCarburant = jaugeCarburant;
}

void Voiture::rouler(int distance)
{
    // precalcul de la consommation
    int conso = (kilometrage()<150000) ? distance * 5 : distance * 10;
    // verification trajet possible
    if (conso > jaugeCarburant()) {
        throw std::invalid_argument("pas assez d'essence");
    }

    setKilometrage(kilometrage() + distance);
    setJaugeCarburant(jaugeCarburant() - conso);

}
