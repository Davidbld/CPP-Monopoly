#ifndef CASE_H
#define CASE_H

#include <string>

// Représente une case générique.
class Case
{
private:
    int m_idCase;
    int m_niveauTaxe;

    std::string m_categorie;

public:
    // Fonction déterminant le montant de la taxe à prélever.
    int taxer();

    // Constructeur
    Case(int idCase, std::string categorie, int niveauTaxe);

    // Getters et Setters
    void setCategorie(std::string categorie);
    std::string getCategorie() const;

    void setNiveauTaxe(int niveauTaxe);
    int getNiveauTaxe() const;
};

// Représente les 4 cases des gares.
class Gare : protected Case
{
private:
    std::string m_direction;

public:
    // Fonction permettant à un joueur de récupérer la case Gare
    int acheter();

    // Constructeur
    Gare(int idCase, std::string categorie, int niveauTaxe, std::string direction);

    // Getters et Setters
    void setDirection(std::string direction);
    std::string getDirection() const;
};

// Représente les 2 compagnies d'eau et d'éléctricité.
class Compagnie : protected Case
{
private:
    std::string m_service;

public:
    // Fonction permettant à un joueur de récupérer la case Compagnie
    int acheter();

    // Constructeur
    Compagnie(int idCase, std::string categorie, int niveauTaxe, std::string service);

    // Getters et Setters
    void setService(std::string service);
    std::string getService() const;
};

// Représente les terrains achetables.
class Terrains : protected Case
{
private:
    std::string m_adresse;
    std::string m_couleur;
    int m_prix;
    std::string m_niveau;

public:
    // Fonction permettant à un joueur de récupérer le Terrains
    int acheter();
    int ameliorer();
    int hypothequer();

    // Constructeur
    Terrains(int idCase, std::string categorie, int niveauTaxe, std::string adresse, std::string couleur, int prix, std::string niveau);

    // Getters et Setters
    void setAdresse(std::string adresse);
    std::string getAdresse() const;

    void setCouleur(std::string couleur);
    std::string getCouleur() const;

    void setPrix(int prix);
    int getPrix() const;

    void setNiveau(std::string niveau);
    std::string getNiveau() const;
};

class Evenement : protected Case
{
private:
    std::string m_categorieEvenement;

public:
    // Constructeur
    Evenement(int idCase, std::string categorie, int niveauTaxe, std::string categorieEvenement);

    // Getters et Setters
    void setCategorieEvenement(std::string categorieEvenement);
    std::string getCategorieEvenement() const;
};

class Communaute : protected Evenement
{
private:
    std::string m_instruction;

public:
    // Fonction exécutant l'instruction marqué sur la case
    std::string faireInstruction();

    // Constructeur
    Communaute(int idCase, std::string categorie, int niveauTaxe, std::string categorieEvenement);

    // Getters et Setters
    void setInstruction(std::string instruction);
    std::string getInstruction() const;
};

// To Do

class Prison : protected Evenement
{

};

class ParkingGratuit : protected Evenement
{

};

class Chance : protected Evenement
{

};

class TaxeDeLuxe : protected Evenement
{

};

class Depart : protected Evenement
{

}; 

#endif