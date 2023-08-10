#pragma once

template <class TypeElement>
class Node 
{
public:
	Node() { ; }

	Node(TypeElement p_valeur)
	{
		this->m_valeur = p_valeur;
		this->m_next = nullptr;
	}

	TypeElement m_valeur;
	Node<TypeElement>* m_next;
};