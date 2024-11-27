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
    enum m_direction {
        Nord,
        Sud,
        Est,
        Ouest
    };

public:
    // Fonction permettant à un joueur de récupérer la case Gare
    int acheter();

    // Constructeur
    Gare(int idCase, std::string categorie, int niveauTaxe, m_direction direction);

    // Getters et Setters
    void setDirection(m_direction direction);
    m_direction getDirection() const;
};

// Représente les 2 compagnies d'eau et d'éléctricité.
class Compagnie : protected Case
{
private:
    enum m_service{
        Eau,
        Electricite
    };

public:
    // Fonction permettant à un joueur de récupérer la case Compagnie
    int acheter();

    // Constructeur
    Compagnie(int idCase, std::string categorie, int niveauTaxe, m_service service);

    // Getters et Setters
    void setService(m_service service);
    m_service getService() const;
};

// Représente les terrains achetables.
class Terrains : protected Case
{
private:
    std::string m_adresse;
    enum m_couleur{
        Fushia,
        BleuClaire,
        Violet,
        Orange,
        Rouge,
        Jaune,
        Vert,
        BleuFonce
    };
    int m_prix;
    enum m_niveau{
        terrainNu,
        UneMaison,
        DeuxMaisons,
        TroisMaisons,
        Hotel
    };

public:
    // Fonction permettant à un joueur de récupérer le Terrains
    int acheter();
    int ameliorer();
    int hypothequer();

    // Constructeur
    Terrains(int idCase, std::string categorie, int niveauTaxe, std::string adresse, m_couleur couleur, int prix, m_niveau niveau);

    // Getters et Setters
    void setAdresse(std::string adresse);
    std::string getAdresse() const;

    void setCouleur(m_couleur couleur);
    m_couleur getCouleur() const;

    void setPrix(int prix);
    int getPrix() const;

    void setNiveau(m_niveau niveau);
    m_niveau getNiveau() const;
};

class Evenement : protected Case
{
private:
    enum m_categorieEvenement{
        Communaute,
        Prison,
        ParkingGratuit,
        Chance,
        TaxeDeLuxe,
        Depart
    };

public:
    // Constructeur
    Evenement(int idCase, std::string categorie, int niveauTaxe, m_categorieEvenement categorieEvenement);

    // Getters et Setters
    void setCategorieEvenement(m_categorieEvenement categorieEvenement);
    m_categorieEvenement getCategorieEvenement() const;
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