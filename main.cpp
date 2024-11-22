#include <iostream>
#include <math.h>
using namespace std;

float funcao(float x){
    return x; 
}


//O polinômio interpolador é uma unidade menor que o número de pontos conhecidos
// polinomio = pontos -1

int lagrange(){
    int qntPontos(0);
    float x(0),numeradorRes(1),denominadorRes(1),res(0);
    float **pontos = NULL;
    pontos = new float*[qntPontos];//Vetores para a quantidade de pontos, um vetor para X e outro para Y;
    float *vetorPolinomiosBasicos = new float[qntPontos];//Vetor para guardar o resultado de cada L;

    cout << "Insira o valor de X: ";
    cin >> x;
    cout << "Insira a quantidade de pontos: ";
    cin >> qntPontos;

    for(int i=0;i<qntPontos;i++){//Inserir pontos
        pontos[i] = new float[2];
        cout << "Insira X do ponto " << i+1 << ": ";
        cin >> pontos[i][0];
        cout << "Insira Y do ponto " << i+1 << ": ";
        cin >> pontos[i][1];
        cout << endl;
    }

    //Limpar console
    system("cls");
    cout << "Valor de X: " << x << endl;
    for(int i = 0; i<qntPontos;i++){//Ver pontos
        cout << "Ponto: " << i+1 << endl;
        cout << "Coordenada X: " << pontos[i][0] << endl;
        cout << "Coordenada Y: " << pontos[i][1] << endl;
        cout << endl;
    }



    //Calculando Li(x)[polinômios básicos de Lagrange]
    //Dois loops, um guia aonde fica a resposta de *vetorPolinomiosBasicos o outro calcula os X e retorna a resposta quando acabar o loop

    for(int i = 0; i < qntPontos;i++){//Guia a resposta do *vetorPolinomiosBasicos
        for(int j = 0;j <qntPontos;j++){//Calcula o numerador
            if(j!=i){//Se meu Li for diferente a Xj calculo normalmente
                numeradorRes *= (x-pontos[j][0]);
            }
        }
        for(int k = 0;k <qntPontos;k++){//Calcula o denominador
            //O calculo vai ficar Xi - Xk
            if(k!=i){
                denominadorRes *= (pontos[i][0]-pontos[k][0]);
            }
        }

        vetorPolinomiosBasicos[i] = (numeradorRes/denominadorRes)*pontos[i][1];
        //Cada casa do vetor terá seu polinomio interpolador multiplicado pelo Y de seu respective ponto

        numeradorRes = 1;
        denominadorRes = 1;
    }

    for(int i = 0; i<qntPontos;i++){
        res += vetorPolinomiosBasicos[i];
    }
    cout << "Resposta: " << res <<endl;
    return 0;
}


int main(){
    lagrange();
    return 0;
}
