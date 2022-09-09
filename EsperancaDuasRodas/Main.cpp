#include <iostream>
#include <random>
#include <iomanip>
#include <locale>
#include <windows.h>

int main() {
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");

	std::random_device rd; //gera um número aleatório não determinístico
	std::mt19937 mt(rd()); //mersenne twister (mt19937)
	std::uniform_int_distribution<short> dist(1, 10); //função que gera distribuições uniformes para uma faixa de números inteiros (1,2,3,4)

	long long Nmax = 0, cd1[4]{}, cd2[4]{};
	short disco1 = 1, disco2 = 4;
	double CT = 80.0, Pcd1[4]{}, Pcd2[4]{}, PcdT[4]{}, FrutasDiff = 0.0, Result = 0.0;


	std::cout << "Esperança: problema de dois discos independentes com figuras de frutas" << std::endl;

	std::cout << "Quantidade de tentativas: ";
	std::cin >> Nmax;
	
	for (int N = 1; N <= Nmax; ++N) {
		disco1 = dist(mt);
		disco2 = dist(mt);

		switch (disco1) {
		case 1:
		case 2:
		case 3:
		case 4: cd1[0] += 1;
			break;
		case 5:
		case 6:
		case 7: cd1[1] += 1;
			break;
		case 8:
		case 9: cd1[2] += 1;
			break;
		case 10: cd1[3] += 1;
			break;
		}

		switch (disco2) {
		case 1:
		case 2:
		case 3:
		case 4: cd2[0] += 1;
			break;
		case 5:
		case 6:
		case 7: cd2[1] += 1;
			break;
		case 8:
		case 9: cd2[2] += 1;
			break;
		case 10: cd2[3] += 1;
			break;
		}

	}

	for (short i = 0; i <= 3; i++) {
		Pcd1[i] = float(cd1[i]) / Nmax;
		Pcd2[i] = float(cd2[i]) / Nmax;
		PcdT[i] = Pcd1[i] * Pcd2[i];
	}
	FrutasDiff = 1.0 - ((PcdT[0]) + (PcdT[1]) + (PcdT[2]) + (PcdT[3]));
	Result = (0.0 - CT) * FrutasDiff + (40.0 - CT) * PcdT[0] + (80.0 - CT) * PcdT[1] + (140.0 - CT) * PcdT[2] + (180.0 - CT) * PcdT[3];

	std::cout << "Disco 1  |  Disco 2" << std::endl;
	std::cout << "Maçã: " << cd1[0] << " | " << cd2[0] << std::endl;
	std::cout << "Bana: " << cd1[1] << " | " << cd2[1] << std::endl;
	std::cout << "Pera: " << cd1[2] << " | " << cd2[2] << std::endl;
	std::cout << "Lara: " << cd1[3] << " | " << cd2[3] << std::endl;
	std::cout << "Total Disco 1: " << cd1[0] + cd1[1] + cd1[2] + cd1[3] << " e Disco 2: " << cd2[0] + cd2[1] + cd2[2] + cd2[3] << std::endl;
	std::cout << std::setprecision(6) << std::fixed;
	std::cout << "Probabilidades" << std::endl;
	std::cout << "Maçã.....CD1 " << Pcd1[0] << " CD2: " << Pcd2[0] << " MxM: " << PcdT[0] << std::endl;
	std::cout << "Banana...CD1 " << Pcd1[1] << " CD2: " << Pcd2[1] << " BxB: " << PcdT[1] << std::endl;
	std::cout << "Pera.....CD1 " << Pcd1[2] << " CD2: " << Pcd2[2] << " PxP: " << PcdT[2] << std::endl;
	std::cout << "Laranja..CD1 " << Pcd1[3] << " CD2: " << Pcd2[3] << " LxL: " << PcdT[3] << std::endl;
	std::cout << "Frutas diferentes: " << FrutasDiff << std::endl;
	std::cout << "Resultado:" << Result << std::endl;

	return 0;
}