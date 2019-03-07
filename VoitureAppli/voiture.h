#ifndef VOITURE_H
#define VOITURE_H

#include <QString>

class Voiture
{
public:
    Voiture();
    Voiture(QString modele);
    Voiture(QString modele, int kilometrage, int jaugeCarburant);
    virtual ~Voiture();
    QString modele() const;
    void setModele(const QString &modele);

    int kilometrage() const;
    void setKilometrage(int kilometrage);

    int jaugeCarburant() const;
    void setJaugeCarburant(int jaugeCarburant);

    void rouler(int distance);
private:
    QString mModele;
    int mKilometrage;
    int mJaugeCarburant; // cl
};

#endif // VOITURE_H
