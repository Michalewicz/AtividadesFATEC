#include <iostream>

using namespace std;

// NOME: Rafael Michalewicz Rodrigues
// CICLO: 3º
// CURSO: Análise e Desenvolvimento de Sistemas
// DATA: 30/04/2024

int main(int argc, char** argv) {
	// DECLARAÇÃO DE VARIÁVEIS
	int op, nEsc, conNum, armD = 0, potD;
	/*
		op = Operação que o usuário irá escolher na primeira entrada de dados, sendo usada exclusivamente para isso.
		nEsc = Número Escolhido pelo usuário. Pode ser tanto um número binário quanto decimal, depende apenas do op (operador que o usuário escolheu).
		conNum = Contador Númerico, utilizado para realizar as operações e mostrar os resultados finais das operações. É usado tanto na conversão para binário, quanto na conversão para decimal.
		armD = Armazenamento Decimal, utilizado como contador de casas que o nEsc terá ao usar a conversão de decimal para binária. Ele é inicializado no começo para poder servir como um contador no primeiro for da operação binário para decimal.
		potD = Potência do Decimal, utilizado para realizar a operação de potência em cada casa binária para encontrar o número decimal. Ela é inicializada mais adiante no código.
	*/

	// ESCOLHA DE OPERADOR
	cout << "Digite qual operacao voce ira realizar:\n1. DECIMAL PARA BINARIO	2. BINARIO PARA DECIMAL\n";
	cin >> op;
	cout << "\n\n--------------------------------\n";
	/*
	   Ao digitar o número 1, será escolhido a opção "1. DECIMAL PARA BINÁRIO", que como o próprio nome diz, irá captar um número decimal e converterá para binário.
	   Ao digitar o número 2, será escolhido a opção "2. BINÁRIO PARA DECIMAL", que como o próprio nome diz, irá captar um número binário e converterá para decimal.
	   Ao digitar qualquer outro número que não seja 1 ou 2, será escolhido a opção "-. OPERACAO INVÁLIDA", mostrando ao usuário que ele selecionou uma operação inválida.
	*/

	// 1. DECIMAL PARA BINÁRIO
	if (op == 1) {

		// CAPTAÇÃO DE DADOS PARA A REALIZAÇÃO DA OPERAÇÃO
		cout << "Digite um numero DECIMAL para converter para BINARIO: ";
		cin >> nEsc;

		// RESPOSTA DA OPERAÇÃO SEMI-COMPLETA, FALTANDO APENAS REALIZAR A OPERAÇÃO DO NÚMERO BINÁRIO
		cout << "Numero escolhido em DECIMAL: " << nEsc << "\nBINARIO: ";

		// O "for" abaixo servirá para ir colocando o resultado ao qual o segundo "for" que está dentro deste "for" definir se o número é 0 ou 1, ele também ditará o tamanho da operação com o nEsc. A cada repetição do "for", o i será multiplicado por 2.
		for (int i = 1; i <= nEsc; i *= 2) {

			// O "for" abaixo servirá para definir o escopo do número. Ou seja, enquanto o "for" com o "i" vai aumentando, o "for" com "j" irá diminuir, já que ele irá dividir por 2 a cada repetição. Esse escopo será mais explicado detalhadamente no "if" a seguir.
			for (int j = nEsc; j >= 1; j /= 2) {

				// O "if" irá comparar se "i" é menor ou igual a "j", se sim, ele executará a operação. Caso contrário, ele não irá executar a operação, com isso dito, ele terá como principal propósito reduzir o escopo da operação.
				if (i <= j) {

					// Esta operação irá definir se o resto de "j" é 0 ou 1 a cada repetição do "for" de "j" e irá atribuir esse valor para conNum. Ao reduzir o escopo do número binário, e por se tratar de um "for" com uma saída de dados fora do "for" de "j", ele irá captar o último número do escopo.
					conNum = j % 2;
				}
			}

			// APÓS REALIZAR A OPERAÇÃO, O NÚMERO SERÁ SENDO COLOCADO A CADA VEZ QUE O FOR REINICIAR. QUANDO ACABAR O FOR, O RESULTADO FINAL APARECERÁ
			// A saída SEMPRE será o ´número da última repetição do "for" de "j" e por ser o último número sempre que ele irá captar, ao sair do "for" de "j", ele irá imprimir na tela o primeiro número do número binário, mas que seria o último da operação do "for" de "j" e assim uma nova repetição pode se iniciar ou finalizar por aqui, dependendo do número.
			cout << conNum;
		}
	}
	// 2. BINÁRIO PARA DECIMAL
	else if (op == 2) {

		// CAPTAÇÃO DE DADOS PARA A REALIZAÇÃO DA OPERAÇÃO
		cout << "Digite um numero BINARIO para converter para DECIMAL: ";
		cin >> nEsc;

		// RESPOSTA DA OPERAÇÃO SEMI-COMPLETA, FALTANDO APENAS REALIZAR A OPERAÇÃO DO NÚMERO DECIMAL
		cout << "Numero escolhido em BINARIO: " << nEsc << "\nDECIMAL: ";

		// Este primeiro "for" é simples, seu objetivo é definir quantas casas o número binário que o usuário digitou tem, ele irá finalizar quando o número for igual ou menor que 0. A cada repetição ele irá dividir o "i" por 10, por contar a quantidade de casas que o número tem. armD irá acumular as casas, como se fosse um parâmetro "len" ou "size", mas sendo apenas uma variável inteira.
		for (int i = nEsc; i > 0; i/= 10) {
			armD++;
		}

		// A variável conNum é inicializada aqui com 0 para ter um valor que não seja nulo e com isso possa somar mais adiante ou simplesmente apareça o resultado "0" caso o usuário tenha colocado 0 em nEsc antes.
		conNum = 0;

		// Este "for" servirá para definir qual casa do número binário que o usuário digitou estamos realizando a operação mais adiante.
		for (int i = 0; i <= armD; i++) {

			// Este "if" servirá para identificar se a casa de nEsc é 1 ou 0, mesmo utilizando mod de 10, só aparecerá esses valores, devido as opções de entrada de dados de nEsc ser 0's e 1's. Um exemplo, supondo que eu use o número binário: 101 (que seria 5 em decimal), ele irá dividir por 10 que sobrára resto 1, satisfazendo então a condição do "if".
			if (nEsc % 10 == 1) {

				// A variável potD será inicializada com 1 e antes do "for" de "j", pois o valor mínimo de uma potência sempre será 1 se elevado a 0 (2^0 = 1) e a cada repetição do for ela será reinicializada com este valor.
				potD = 1;

				// Este "for" servirá como uma função math de potência, seu único objetivo é potencializar os números. Um detalhe importante, é que o "j" ele deve ser menor ou igual a "i" e "i" como dito antes, ele é utilizado para definir a casa do binário que está sendo calculada, caso "i" seja 3 (ou seja, a quarta casa) por exemplo, ele irá executar 1*2 = 2; 2*2 = 4 e 4*2 = 8. Por padrão, potD será igual a 1, então se "j" for igual a 0, ele não irá alterar o valor de potD (ou seja: potD+=0).
				for (int j = 0; j <= i; j++) {
					if (j == 0) {
						potD += 0;
					}
					else {
						potD *= 2;
					}
				}

				// O conNum ao final do "for", ele irá acumular os resultados das potências de de cada repetição do "for" de "i", que consequentemente irá repetir o "for" de "j" várias vezes. Como conNum é inicializado fora dos "for", ele irá armazenar os valores das potências, sem reinicializar para um valor específico, diferente de potD.
				conNum += potD;
			}

			// nEsc irá dividir o valor que o usuário forneceu por 10 ao final do "for" de "i", possibilitando então o funcionamento da verificação que o "if" de antes faz para ver se o número é 1 ou 0.
			nEsc /= 10;

		}

		// APÓS REALIZAR TODAS AS OPERAÇÕES, O RESULTADO SERÁ EXIBIDO NA TELA
		cout << conNum;
	}
	// -. OPERAÇÃO INVÁLIDA
	else {
		cout << "OPERACAO INVALIDA!";
	}

	return 0;
}


