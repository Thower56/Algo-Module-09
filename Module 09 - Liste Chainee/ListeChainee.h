#pragma once
#include "Node.h"
#include <stdexcept>

template <class TypeElement>
class ListeChainee
{
public:
	ListeChainee():
		debut(nullptr), fin(nullptr), nombreElement(0)
	{
		;
	};

	ListeChainee(const ListeChainee& p_listACopier)
		:debut(nullptr), fin(nullptr), nombreElement(0)
	{
		for (size_t i = 0; i < nombreElement; i++)
		{
			this->ajouterFin(p_listACopier[i]);
		}
	};

	ListeChainee(ListeChainee&& p_listACopier)
		:debut(p_listACopier.debut), fin(p_listACopier.fin), nombreElement(0)
	{
		p_listACopier.debut = nullptr;
		p_listACopier.fin = nullptr;
		p_listACopier.nombreElement = nullptr;
	};

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
		if (nombreElement == 0)
		{
			debut = nouvelleValeur;
			fin = nouvelleValeur;
		}
		parcourir_rec(debut, (capacite()-1))->m_next = nouvelleValeur;
		fin = nouvelleValeur;
		this->nombreElement++;
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
		valeur = parcourir_rec(debut, p_indice);
		return valeur->m_valeur;
	}

	ListeChainee<TypeElement>& operator=(const ListeChainee<TypeElement>& p_listeACopier)
	{
		for (size_t i = 0; i < p_listeACopier.capacite(); i++)
		{
			Node<TypeElement>* node = parcourir_rec(p_listeACopier.debut, i);
			this->ajouterFin(node->m_valeur);
		}
		return *this;
	};

	ListeChainee<TypeElement>& operator=(ListeChainee<TypeElement>&& p_listeADeplacer)
	{
		if (this != &p_listeADeplacer)
		{
			this->debut = p_listeADeplacer.debut;
			this->fin = p_listeADeplacer.fin;
			this->nombreElement = p_listeADeplacer.nombreElement;

			p_listeADeplacer.debut = nullptr;
			p_listeADeplacer.fin = nullptr;
			p_listeADeplacer.nombreElement = nullptr;
		}
		return *this;
	};

	void parcourir(void (*p_fonction)(const TypeElement&))
	{
		Node<TypeElement> node = debut;
		while (node != nullptr)
		{
			p_fonction(node.m_valeur);
			node = node.m_next;
		}
	};

	void trier(bool (*p_fonctionTri)(const TypeElement&, const TypeElement&))
	{
		while (p_fonctionTri)
		{
			p_fonctionTri(debut->m_valeur, fin->m_valeur);
		}
	};


private:

	Node<TypeElement>* parcourir_rec(Node<TypeElement>* p_node, int p_compteur)
	{

		if (p_compteur <= 0)
		{
			return p_node;
		}
		else
		{
			parcourir_rec(p_node->m_next, --p_compteur);
		}
	};
	Node<TypeElement>* debut;
	Node<TypeElement>* fin;
	int nombreElement;
};
