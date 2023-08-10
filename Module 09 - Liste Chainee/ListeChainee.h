#pragma once
#include "Node.h"
#include <stdexcept>

template <class TypeElement>
class ListeChainee
{
public:
	ListeChainee() 
	{
		;
	};

	/*ListeChainee(const ListeChainee& p_listACopier)
	{
		;
	};*/

	~ListeChainee()
	{
		;
	};

	void ajouterDebut(TypeElement& p_valeur)
	{
		Node<TypeElement>* nouvelleValeur = new Node<TypeElement>(p_valeur);
		if (nombreElement == 0)
		{
			debut = nouvelleValeur;
			fin = nouvelleValeur;
		}
		else 
		{
			nouvelleValeur->m_next = debut;
			debut = nouvelleValeur;
		}
		this->nombreElement++;
	};

	void ajouterFin(TypeElement& p_valeur) 
	{
		Node<TypeElement>* nouvelleValeur = new Node<TypeElement>(p_valeur);
		fin->m_next = nouvelleValeur;
	};

	void inserer(const TypeElement& p_valeur, const int& p_indice)
	{
		if (p_indice - 1 > this->nombreElement)
		{
			std::invalid_argument("Indice trop eleve");
		}

		Node<TypeElement>* nouvelleValeur = new Node<TypeElement>(p_valeur);
		if (p_indice == 0)
		{
			ajouterDebut(nouvelleValeur->m_valeur);
		}
		else 
		{
			Node<TypeElement>* valeurPrecedente = parcourir_rec(debut->m_next, --&p_indice);
			nouvelleValeur->m_next = valeurPrecedente.m_next;
			valeurPrecedente->m_next = nouvelleValeur;
		}


	};

	void supprimerDebut()
	{
		if (this->nombreElement > 0)
		{
			delete debut;
			debut = debut->m_next;
		}
	};

	void supprimerFin()
	{
		delete parcourir_rec(this->debut, this->nombreElement - 1);
		parcourir_rec(this->debut, this->nombreElement - 1) = nullptr;
	};

	void supprimerA(const int& p_indice)
	{
		delete parcourir_rec(this->debut, p_indice);
		parcourir_rec(this->debut, this->nombreElement - 1) = nullptr;
	};

	int capacite() const
	{
		return this->nombreElement;
	};

	TypeElement operator[](const int& p_indice)
	{
		Node<TypeElement>* valeur;
		valeur = parcourir_rec(debut->m_next, p_indice);
		return valeur.m_valeur;
	}

	/*ListeChainee<TypeElement>& operator=(const ListeChainee& p_listeACopier);

	ListeChainee<TypeElement>& operator=(ListeChainee&& p_listeADeplacer);*/

	void parcourir(void (*p_fonction)(const int&));

	void trier(bool (*p_fonctionTri)(const int&, const int&));


private:

	Node<TypeElement>* parcourir_rec(Node<TypeElement>& p_node, int p_compteur)
	{

		if (p_compteur == 0)
		{
			return p_node;
		}
		else
		{
			parcourir_rec(p_node.m_next, --p_compteur);
		}
	};
	Node<TypeElement>* debut;
	Node<TypeElement>* fin;
	int nombreElement;
};
