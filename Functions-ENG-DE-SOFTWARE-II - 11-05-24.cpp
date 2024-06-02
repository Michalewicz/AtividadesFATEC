#include <iostream>

using namespace std;

// NOME: Rafael Michalewicz Rodrigues
// CICLO: 3º
// CURSO: Análise e Desenvolvimento de Sistemas
// DATA: 10/05/2024



bool detectarPrimo(int num) {
    if (num > 2) {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    } else if (num == 2) return true;
    else return false;
}

int indice(int num) {
    int indCon = 0;
    for (int i = num; i > 0; i /= 10) {
        indCon++;
    }
    return indCon;
}

bool detectarFragmento(int x, int y) {
    int fragX = x, fragY = y;

    for (int i = 0; i < indice(y); i++) {
        if (fragX % 10 == fragY % 10) {
            fragX /= 10;
        } else {
            fragX = x;
            if (fragX % 10 == fragY % 10) {
                fragX /= 10;
            }
        }
        fragY /= 10;
        
        
        if (fragX == 0) return true;
    }
    return false;
}

int inversao(int num, int ind) {
    int inve = 0, con = num;
    for (int i = ind; i > 0; i--) {
        int rst = con%10, pot = 1;
        for (int dez = 1; dez < i; dez++) {
            pot *= 10;
        }
        inve += rst * pot;
        con /= 10;
    }
    return inve;
}

void somaIndice(int num, int ind) {
    int par = 0, impar = 0, op, numInv;

    numInv = inversao(num, ind);
    for (int i = 1; i < ind+1; i++) {
        if (i % 2 == 0) {
            op = numInv%10;
            numInv /= 10;
            par += op;
        } else {
            op = numInv % 10;
            numInv /= 10;
            impar += op;
        }
    }
    cout << "\tPar: " << par << "\tImpar: " << impar;
}

void palindromoNum(int num) {
    cout << "Palindromo Numerico: " << num << inversao(num, indice(num));
}



int main() {
    int x, y, soma;

    for (int i = 0; i >= 0;) {
        cout << "X = ";
        cin >> x;
        cout << "Y = ";
        cin >> y;

        if (x > -1 && y > -1) break;
        else {
            cout << "\nNumero invalido! Tente novamente!\n\n";
            i++;
        }
    }

    if(x < y){
        if (detectarFragmento(x, y) == true) cout << "O numero: " << x << " e um fragmento de: " << y;
        else cout << "Nao e fragmento!";
    } else {
        soma = x + y;
        int ind = indice(soma);
        if (detectarPrimo(soma) == true) {
            cout << "Soma Indice";
            somaIndice(soma, ind);
        }
        else if (soma % 2 == 0) {
            int inverso = inversao(soma, ind);
            cout << "Inverso: " << inverso;
        } else {
            palindromoNum(soma);
        }
    }

}