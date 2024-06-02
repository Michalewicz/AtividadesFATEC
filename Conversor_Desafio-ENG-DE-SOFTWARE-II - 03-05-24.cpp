#include <iostream>

using namespace std;

// NOME: Rafael Michalewicz Rodrigues
// CICLO: 3º
// CURSO: Análise e Desenvolvimento de Sistemas
// DATA: 30/04/2024

int main(int argc, char** argv) {
	// DECLARAÇÃO DE VARIÁVEIS
	int op, nEsc, conNum, armD = 0, potD;

	// ESCOLHA DE OPERADOR
	cout << "Digite qual operacao voce ira realizar:\n1. DECIMAL PARA BINARIO	2. BINARIO PARA DECIMAL\n";
	cin >> op;
	cout << "\n\n--------------------------------\n";

	// 1. DECIMAL PARA BINÁRIO
	if (op == 1) {
		cout << "Digite um numero DECIMAL para converter para BINARIO: ";
		cin >> nEsc;
		cout << "Numero escolhido em DECIMAL: " << nEsc << "\nBINARIO: ";
		for (int i = 1; i <= nEsc; i *= 2) {
			for (int j = nEsc; j >= 1; j /= 2) {
				if (i <= j) {
					conNum = j % 2;
				}
			}
			cout << conNum;
		}
	}
	// 2. BINÁRIO PARA DECIMAL
	else if (op == 2) {
		cout << "Digite um numero BINARIO para converter para DECIMAL: ";
		cin >> nEsc;
		cout << "Numero escolhido em BINARIO: " << nEsc << "\nDECIMAL: ";
		for (int i = nEsc; i > 0; i/= 10) {
			armD++;
		}
		conNum = 0;
		for (int i = 0; i <= armD; i++) {
			if (nEsc % 10 == 1) {
				potD = 1;
				for (int j = 0; j <= i; j++) {
					if (j == 0) {
						potD += 0;
					}
					else {
						potD *= 2;
					}
				}
				conNum += potD;
			}
			nEsc /= 10;
		}
		cout << conNum;
	}
	// -. OPERAÇÃO INVÁLIDA
	else {
		cout << "OPERACAO INVALIDA!";
	}

	return 0;
}


