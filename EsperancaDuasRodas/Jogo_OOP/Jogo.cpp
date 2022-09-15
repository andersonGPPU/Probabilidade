#include <iostream>
#include <random>
#include "Jogo.h"

Disco::Disco() {
	m_tentativas = 0; 
	for(unsigned short i = 0; i<= 3; ++i){ 
		m_Probabilidade_Parcial[i] = 0.0f;
		m_cd[i] = 0;
	}
}
void Disco::Qt_tentar(long long tentativas) {
	m_tentativas = tentativas;
}
void Disco::SetGirar() {
	std::random_device rd; //gera um n�mero aleat�rio n�o determin�stico
	std::mt19937 mt(rd()); //mersenne twister (mt19937)
	std::uniform_int_distribution<unsigned short> dist(1, 10); //fun��o que gera distribui��es uniformes para uma faixa de n�meros inteiros (1,2,3,4,5,6,7,8,9,10)
	unsigned short rodar = 0;
	for (int N = 1; N <= m_tentativas; ++N) {
		rodar = dist(mt);

		switch (rodar) {
		case 1:
		case 2:
		case 3:
		case 4: m_cd[0]++; //contagem de ma��s
			break;
		case 5:
		case 6:
		case 7: m_cd[1]++; //contagem de bananas
			break;
		case 8:
		case 9: m_cd[2]++; //contagem de peras
			break;
		case 10: m_cd[3]++; //contagem de laranjas
			break;
		}

	}
}
long long* Disco::GetGirar() {
	return m_cd;
}
void Disco::SetProbabilidade() {
	for (unsigned short i = 0; i <= 3; ++i) {
		m_Probabilidade_Parcial[i] = float(m_cd[i]) / m_tentativas;
	}
}
double* Disco::GetProb() {
	return m_Probabilidade_Parcial;
}