#ifndef JOGO_H
#define JOGO_H
class Disco {
private:
	double m_Probabilidade_Parcial[4];
	long long m_tentativas, m_cd[4];
public:
	Disco();
	void Qt_tentar(long long tentativas);
	void SetGirar();
	long long* GetGirar();
	void SetProbabilidade();
	double* GetProb();
	
};
#endif
