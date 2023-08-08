#pragma once

template <class TypeElement>
class Node 
{
public:
	Node() { ; }

	Node(TypeElement p_valeur, Node<TypeElement>& p_next)
	{
		this->m_valeur = p_valeur;
		this->m_next = p_next;
	}

	TypeElement m_valeur;
	Node<TypeElement>* m_next;
};