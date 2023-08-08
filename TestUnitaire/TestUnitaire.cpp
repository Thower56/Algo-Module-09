#include "pch.h"
#include "CppUnitTest.h"
#include "ListeChainee.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestUnitaire
{
	TEST_CLASS(TestUnitaire)
	{
	public:
		
		TEST_METHOD(TesterAjouterUneNouvelleValeurAuDebut)
		{
			ListeChainee<int> listeTest;
			int x = 5;

			listeTest.ajouterDebut(x);
			int nombreAttendu = 1;

			Assert::AreEqual(nombreAttendu, listeTest.capacite());
		}

		TEST_METHOD(TesterAjouterUneNouvelleValeurALaFin)
		{
			ListeChainee<int> listeTest;
			int x = 5;

			listeTest.ajouterFin(x);
			int nombreAttendu = 1;

			Assert::AreEqual(nombreAttendu, listeTest.capacite());
		}

		TEST_METHOD(TesterSupprimerDebut)
		{
			ListeChainee<int> listeTest;
			int x = 5;
			listeTest.ajouterDebut(x);
			int nombreAttendu = 0;

			listeTest.supprimerDebut();

			Assert::AreEqual(nombreAttendu, listeTest.capacite());
		}

		TEST_METHOD(TesterSupprimerFin)
		{
			ListeChainee<int> listeTest;
			int x = 5;
			listeTest.ajouterFin(x);
			int nombreAttendu = 0;

			listeTest.supprimerFin();

			Assert::AreEqual(nombreAttendu, listeTest.capacite());
		}

		TEST_METHOD(TesterSupprimerA)
		{
			ListeChainee<int> listeTest;
			int x = 1;
			int y = 2;
			int z = 3;
			listeTest.ajouterFin(x);
			listeTest.ajouterFin(y);
			listeTest.ajouterFin(z);
			int nombreAttendu = 2;

			listeTest.supprimerA(1);

			Assert::AreEqual(nombreAttendu, listeTest.capacite());
		}

		TEST_METHOD(TesterCapacite)
		{
			ListeChainee<int> listeTest;
			int x = 1;
			int y = 2;
			listeTest.ajouterFin(x);
			listeTest.ajouterFin(y);

			int nombreAttendu = 2;
			int nombreRecus = listeTest.capacite();

			Assert::AreEqual(nombreAttendu, listeTest.capacite());
		}
	};
}
