#ifndef CASE_H
#define CASE_H

#include <string>
#include <vector>

// Représente une case générique.
class Case
{
private:
    int m_idCase;
    int m_niveauTaxe;

    enum m_categorie{
        Gare,
        Evenement,
        Compagnie,
        Terrain
    };

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
    enum m_direction
    {
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
    enum m_service
    {
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
    enum m_couleur
    {
        Fushia,
        Bleu_Claire,
        Violet,
        Orange,
        Rouge,
        Jaune,
        Vert,
        Bleu_Fonce
    };
    int m_prix;
    enum m_niveau
    {
        terrain_nu,
        Une_maison,
        Deux_maisons,
        Trois_maisons,
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
protected:
    enum m_categorieEvenement
    {
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
    std::vector<std::string> m_instruction;

public:
    // Fonction exécutant l'instruction marqué sur la case
    std::string faireInstruction();

    // Constructeur
    Communaute(int idCase, std::string categorie, int niveauTaxe, m_categorieEvenement categorieEvenement, std::vector<std::string> instruction);

    // Getters et Setters
    void setInstruction(std::vector<std::string> instruction);
    std::vector<std::string> getInstruction() const;
};

class Prison : protected Evenement
{
private:
    int m_nbrTourPrison;

public:
    // Fonctions permettant de raccourcir la peine de prison
    int payerAmende();
    int passerTour();
    int utiliseCarte();

    // Constructeur
    Prison(int idCase, std::string categorie, int niveauTaxe, m_categorieEvenement categorieEvenement, int m_nbrTourPrison);

    // Getters et Setters
    void setNbrTourPrison(int m_nbrTourPrison);
    int getNbrTourPrison() const;
};

class ParkingGratuit : protected Evenement
{
private:
    int m_montantPlateau;

public:
    int donnerArgent();

    // Constructeur
    ParkingGratuit(int idCase, std::string categorie, int niveauTaxe, m_categorieEvenement categorieEvenement, int montantPlateau);

    // Getters et Setters
    void setMontantPlateau(int m_montantPlateau);
    int getMontantPlateau() const;
};

class Chance : protected Evenement
{
private:
    std::vector<std::string> m_instructionChance;

public:
    std::string faireInstructionChance();

    // Constructeur
    Chance(int idCase, std::string categorie, int niveauTaxe, m_categorieEvenement categorieEvenement, std::vector<std::string> instructionChance);

    // Getters et Setters
    void setInstructionChance(std::vector<std::string> instructionChance);
    std::vector<std::string> getInstructionChance() const;
};

class TaxeDeLuxe : protected Evenement
{
private:
    int m_montantTaxeLuxe;

public:
    int payerTaxe();

    // Constructeur
    TaxeDeLuxe(int idCase, std::string categorie, int niveauTaxe, m_categorieEvenement categorieEvenement, int montantTaxeLuxe);

    // Getters et Setters
    void setMontantTaxeLuxe(int montantTaxeLuxe);
    int getMontantTaxeLuxe() const;
};

class Depart : protected Evenement
{
public:
    // A chaque passage par la case départ, le joueur reçois un bonus fixe.
    int bonus();
};

#endif