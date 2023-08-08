#pragma once
#include "Node.h"

template <class TypeElement>
class ListeChainee
{
public:
	ListeChainee();
	ListeChainee(const ListeChainee& p_listACopier);
	~ListeChainee();
	void ajouterDebut(TypeElement& p_valeur);
	void ajouterFin(TypeElement& p_valeur);
	void inserer(const int& p_valeur, const int& p_indice);
	void supprimerDebut();
	void supprimerFin();
	void supprimerA(const int& p_indice);
	int capacite() const;
	ListeChainee<TypeElement>& operator=(const ListeChainee& p_listeACopier);
	ListeChainee<TypeElement>& operator=(ListeChainee&& p_listeADeplacer);
	void parcourir(void (*p_fonction)(const int&));
	void trier(bool (*p_fonctionTri)(const int&, const int&));


private:
	Node<TypeElement>* valeurs;
	int nombreElement;
	int capacite;
};