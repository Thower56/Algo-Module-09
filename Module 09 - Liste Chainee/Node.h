#pragma once

template <class TypeElement>
class Node 
{
public:
	TypeElement valeur;
	Node<TypeElement>* next;
};