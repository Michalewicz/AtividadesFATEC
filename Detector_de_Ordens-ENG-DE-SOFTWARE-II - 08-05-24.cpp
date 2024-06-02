#include <iostream>

using namespace std;

// NOME: Rafael Michalewicz Rodrigues
// CICLO: 3º
// CURSO: Análise e Desenvolvimento de Sistemas
// DATA: 08/05/2024

int main(){
    // DECLARAÇÃO DE VARIÁVEIS
    int no1 = 0, no2 = 0, con = 0, noP, i;
        /*
        no1 = Número 1 digitado pelo usuário.
        no2 = Número 2 digitado pelo usuário.
        con = Contador, serve como "backup" pra caso o usuário digite o número negativo.
        noP = Número Primeiro, variável que servirá para guardar o primeiro número.
        i = Variável do for. Declarada aqui para poder ser utilizada mais adiante no if.
        */
    
    for (i = 0; i >= 0; i++) {
        cout << "Digite um numero: ";
        if (i % 2 == 0) {
            con = no1;
            cin >> no1;
            if (i == 0) noP = no1;
        } else {
            con = no2;
            cin >> no2;
        }
        if (no1 < 0 || no2 < 0) {
            if (no1 < 0) no1 = con;
            else no2 = con;
            if (i == 1) con = no1;
            break;
        }
    }
    
    if (i > 1) {
        if (noP < no1 || noP < no2) {
            if (con < no1 || con < no2) cout << "Ordem crescente!";
            else cout << "Sem ordem!";
        }
        else if (noP > no1 || noP > no2) {
            if (con > no1 || con > no2) cout << "Ordem decrescente!";
            else cout << "Sem ordem!";
        }
    } else cout << "Sem ordem!";
}
