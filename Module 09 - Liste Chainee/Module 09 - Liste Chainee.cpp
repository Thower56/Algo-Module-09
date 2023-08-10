#include <iostream>
#include "ListeChainee.h" 

int main()
{
    ListeChainee<int> listeTest;
    ListeChainee<int> listeTest2;

    int x = 5;
    int y = 4;
    int z = 6;

    listeTest.ajouterDebut(x);
    listeTest.ajouterDebut(y);
    listeTest.ajouterFin(z);

    listeTest2 = listeTest;

    y = listeTest2[2];

    std::cout << y << std::endl;

}
