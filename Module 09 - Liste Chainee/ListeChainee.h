#pragma once
#include "Node.h"
#include <stdexcept>

template <class TypeElement>
class ListeChainee
{
public:
	ListeChainee();

	ListeChainee(const ListeChainee& p_listACopier);

	~ListeChainee();

	void ajouterDebut(TypeElement& p_valeur)
	{
		Node<TypeElement> nouvelleValeur = new Node<TypeElement>(p_valeur, nullptr);
		if (nombreElement == 0)
		{
			debut = nouvelleValeur;
			fin = nouvelleValeur;
		}
		else 
		{
			nouvelleValeur->m_next = &debut;
			debut = nouvelleValeur;
		}
		this->nombreElement++;
	};

	void ajouterFin(TypeElement& p_valeur) 
	{
		Node<TypeElement>* nouvelleValeur = new Node<TypeElement>(p_valeur, nullptr);
		fin->m_next = nouvelleValeur;
	};

	void inserer(const TypeElement& p_valeur, const int& p_indice)
	{
		if (p_indice - 1 > this->nombreElement)
		{
			std::invalid_argument("Indice trop eleve");
		}

		Node<TypeElement>* nouvelleValeur = new Node<TypeElement>(p_valeur, nullptr);
		if (p_indice == 0)
		{
			ajouterDebut(nouvelleValeur->m_valeur);
		}
		else 
		{
			Node<TypeElement> valeurPrecedente = inserer_rec(debut->m_next, --p_indice);
			nouvelleValeur->m_next = valeurPrecedente.m_next;
			valeurPrecedente->m_next = nouvelleValeur;
		}


	};

	void supprimerDebut()
	{
		if (this->nombreElement > 0)
		{
			Node<TypeElement>* temp = debut;
			
		}
	};

	void supprimerFin();

	void supprimerA(const int& p_indice);

	int capacite() const;

	ListeChainee<TypeElement>& operator=(const ListeChainee& p_listeACopier);

	ListeChainee<TypeElement>& operator=(ListeChainee&& p_listeADeplacer);

	void parcourir(void (*p_fonction)(const int&));

	void trier(bool (*p_fonctionTri)(const int&, const int&));


private:

	Node inserer_rec(const Node<TypeElement>& p_node, const int& p_compteur)
	{

		if (p_compteur == 0)
		{
			return p_node;
		}
		else
		{
			inserer_rec(p_node.m_next, --p_compteur);
		}
	};
	Node<TypeElement>* debut;
	Node<TypeElement>* fin;
	int nombreElement;
};