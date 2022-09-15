#include <iostream>
#include <windows.h>
#include <iomanip>
#include <locale.h>
#include "Jogo.h"

struct Lucro {
	double maca = 40.0f, banana = 80.0f, pera = 140.0f, laranja = 180.0f;
} Lfruta;

double* Prob_Total(double* a, double* b) {
	double p_t[4]{};
	for (int i = 0; i <= 3; ++i) {
		*(p_t + i) = *(a + i) * *(b + i);
	}
	return p_t;
}

int main(void) {
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");
	//SetConsoleCP(1252); SetConsoleOutputCP(1252);

	long long tentar = 10000;
	double custo = 80.0f, resultado = 0.0f, f_d = 0.0f; //f_d frutas diferentes


	Disco d1;

	d1.Qt_tentar(tentar);
	d1.SetGirar();
	d1.SetProbabilidade();

	Disco d2;

	d2.Qt_tentar(tentar);
	d2.SetGirar();
	d2.SetProbabilidade();

	std::cout << " *** Frutas Sorteadas ***" << std::setprecision(2) << std::fixed << std::endl;
	std::cout << "Maçã.....: " << d1.GetGirar()[0] << " = " << 100 * d1.GetProb()[0] << "% [*] " << d2.GetGirar()[0] << " = " << 100 * d2.GetProb()[0] << "%" << std::endl;
	std::cout << "Banana...: " << d1.GetGirar()[1] << " = " << 100 * d1.GetProb()[1] << "% [*] " << d2.GetGirar()[1] << " = " << 100 * d2.GetProb()[1] << "%" << std::endl;
	std::cout << "Pera.....: " << d1.GetGirar()[2] << " = " << 100 * d1.GetProb()[2] << "% [*] " << d2.GetGirar()[2] << " = " << 100 * d2.GetProb()[2] << "%" << std::endl;
	std::cout << "Laranja..: " << d1.GetGirar()[3] << " = " << 100 * d1.GetProb()[3] << "% [*] " << d2.GetGirar()[3] << " = " << 100 * d2.GetProb()[3] << "%" << std::endl;
	std::cout << std::endl;
	std::cout << "Cálculo da Probabilidade Total:" << std::setprecision(2) << std::fixed << std::endl;
	std::cout << "Maçã........: " << 100 * Prob_Total(d1.GetProb(), d2.GetProb())[0] << "%" << std::endl;
	std::cout << "Banana......: " << 100 * Prob_Total(d1.GetProb(), d2.GetProb())[1] << "%" << std::endl;
	std::cout << "Pera........: " << 100 * Prob_Total(d1.GetProb(), d2.GetProb())[2] << "%" << std::endl;
	std::cout << "Laranja.....: " << 100 * Prob_Total(d1.GetProb(), d2.GetProb())[3] << "%" << std::endl;
	
	f_d = 1.0 - (Prob_Total(d1.GetProb(), d2.GetProb())[0] + Prob_Total(d1.GetProb(), d2.GetProb())[1] + Prob_Total(d1.GetProb(), d2.GetProb())[2] + Prob_Total(d1.GetProb(), d2.GetProb())[3]);
	std::cout << "Probabilidade de frutas diferentes: " << f_d << std::endl;
	
	resultado = (0.0 - custo) * f_d + (Lfruta.maca - custo) * Prob_Total(d1.GetProb(), d2.GetProb())[0] +
		(Lfruta.banana - custo) * Prob_Total(d1.GetProb(), d2.GetProb())[1] +
		(Lfruta.pera - custo) * Prob_Total(d1.GetProb(), d2.GetProb())[2] +
		(Lfruta.laranja - custo) * Prob_Total(d1.GetProb(), d2.GetProb())[3];
	std::cout << "Resultado do lucro esperado:" << std::endl;
	std::cout << resultado << std::endl;


	return 0;
}