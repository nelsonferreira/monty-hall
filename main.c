//	Criado: Nelson Ferreira @ 	        13 / 10 / 2014
//          IDE:              CodeBlocks
//          Linguagem:        C
//----------------------------------------------------
//	Upload:			                      	29 / 03 / 2016
//	Comentarios de UPLOAD:
//		(Testado no Windows[10])  Uso de system("cls") 
//    O codigo é implementado todo em main e sao usadas labels e respectivos goto's para controlo de fluxo  ( What ?? )
//		
//		Algoritmo que simula os N casos 
//	possiveis para o problema de Monty-Hall.
//		Para N casos, o algoritmo deve-se confrontado com o jogo:
//	1	O algoritmo escolhe inicialmente uma porta em { A, B, C}; (As probabilidades sao de 1/3 para cada porta)
//	2	O "apresentador" "pergunta" ao algoritmo se este quer mudar ou manter a porta escolhida;
//		(As probabilidades sao de 1/2 para mudar ou manter);
//	3	Ganha ou nao ganhou? Soma 1 unidade nas variaveis correspondentes:  _mudou, _ganhou, _mudou_e_ganhou;
// 	4	Analise dos resultados:
//		Basicamente, apresenta dos resultados no ecra e faz, se necessario, calculos.
//----------------------------------------------------



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
    int _1;
    int _2;
    int _ap;
    int _premio;
    int _N;
    int _cardinal = 0;
    int _mudou = 0;
    int _ganhou = 0;
    int _mudou_e_ganhou = 0;
    char _tecla;
    int _tempo;

    printf(" Indique o numero de simulacoes.");
    printf("\n Note que, quanto maior esse valor,");
    printf("\n mais tempo demorara a processar,");
    printf("\n podendo bloquear o computador.");
    printf("\n Experimente com numeros baixos e va subindo.\n");

    reinicio:

    printf("\n N:");

    //_N = 100000000;
    scanf("%d", &_N);

    _tempo = (_N / 10000000);
    printf(" A operacao demorara cerca de %d segundos. \n", _tempo);
   if (_tempo > 10) {
        printf(" Continuar ou Reintroduzir um valor para N? (C/R): ");
        scanf("%c", &_tecla);
        _tecla = getchar();
        if (_tecla == 'r' || _tecla == 'R') {
            system("CLS");
            goto reinicio;
        }
    }

    simulacao:

        _cardinal ++;
        _premio = (rand() %3) + 1;
        _1 = (rand() %3) + 1;

        if (_1 == 1) {
            _ap = (rand() %2)+2;
            if (_premio == _ap && _ap == 2) {_ap = 3;}
            if (_premio == _ap && _ap == 3) {_ap = 2;}

            if (_ap == 2) {
                _2 = (rand() %2) + 1;
                if (_2 == 2) {_2++;}
            }

            if (_ap == 3) {
                _2 = (rand() %2) + 1;
            }
        }

        if (_1 == 2) {
            _ap = (rand() %2) + 1;
            if (_ap == _1) {_ap = 3;}
            if (_premio == _ap && _ap == 1) {_ap = 3;}
            if (_premio == _ap && _ap == 3) {_ap = 1;}

            if (_ap == 1) {_2 = (rand() %2) + 2;}
            if (_ap == 3) {_2 = (rand() %2) + 1;}

        }

        if (_1 == 3) {
            _ap = (rand() %2) + 1;
            if (_premio == _ap && _ap == 1) {_ap = 2;}
            if (_premio == _ap && _ap == 2) {_ap = 1;}

            if (_ap == 1) {_2 = (rand() %2)+2;}

            if (_ap == 2) {
                _2 = (rand() %2) + 1;
                if (_2 == 2) {_2++;}
            }
        }

        /* Analise dos resultados */

        if (_1 != _2) {
            _mudou++;
            if (_2 == _premio) {_mudou_e_ganhou++;}
        }

        if (_2 == _premio) {_ganhou++;}

        if (_N >= _cardinal) {goto simulacao;}


    float mudou = (float) _mudou / _N * 100;
    float mudou_e_ganhou = (float) _mudou_e_ganhou / _mudou * 100;
    float manteve_e_ganhou = (float) (_ganhou-_mudou_e_ganhou) / (_N - _mudou) * 100;
    float ganhou = (float) _ganhou / _N * 100;


    printf("\n Acontecimento:\t\t%%\t\tN. Casos\n");
    printf(" Mudou: \t\t%f\t%d\n",  mudou, _mudou);
    printf(" Ganhou/Mudou: \t\t%f\t%d\t%d\n", mudou_e_ganhou, _mudou_e_ganhou, _mudou);
    printf(" Ganhou/Manteve: \t%f\t%d\t%d\n", manteve_e_ganhou, _ganhou - _mudou_e_ganhou, _N - _mudou);
    printf(" Ganhou: \t\t%f\t%d\n\n", ganhou, _ganhou);
        sc:
     printf("\r\b Sair ou Reintroduzir um valor para N? (S/R): ");

        //scanf("%c", &_tecla);
        _tecla = getchar();
        if (_tecla == 'r' || _tecla == 'R') {
            _cardinal = 0;
            _mudou = 0;
            _ganhou = 0;
            _mudou_e_ganhou = 0;
            goto reinicio;
        } else {
            if (_tecla != 's' && _tecla != 'S') {
                goto sc;
            }
        }



    return 0;
}
