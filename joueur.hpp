#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

// Représente un joueur.
class Joueur
{
private:
    int m_id;
    int m_porteMonnaie;
    std::string m_pion;
    std::string m_casePossedees;
    std::string m_cartePossedees;

public:
    // Fonction permettant au joueur de lancer le dé.
    int jouer();
    bool perdreJeu();
    bool gagnerJeu();
    std::string tirerCarte();

    // Constructeur
    Joueur(int id, int porteMonnaie, std::string pion, std::string casePossedees, std::string cartePossedees);

    // Getters et Setters
    void setId(std::string id);
    int getId() const;

    void setPorteMonnaie(int porteMonnaie);
    int getPorteMonnaie() const;

    void setPion(std::string pion);
    std::string getPion() const;

    void setCasePossedees(std::string casePossedees);
    std::string getCasePossedees() const;

    void setCartePossedees(std::string cartePossedees);
    std::string getCartePossedees() const;
};

#endif