#include <stdio.h>

#define fileiras 7
#define assentos 10

char sala[fileiras][assentos];
int reservas=0;
float ingresso=0;

void visualizarSala () {
    int i=-1, j=0, x;
    printf("\n");
    for (i=-1; i < fileiras; i++) {
        for (j=0; j < assentos; j++) {
            if (i == -1) {
                printf("%d---", j+1);
                x=1;
            } else {
                printf("%c   ", sala[i][j]);
            }
        }
        printf("  %d", i+1);
        printf("\n");
    }
    for (j=0; j < assentos; j++) {
        printf("----");
    }
    printf("\n\n\n");
}

void cancelarCadeira(int n, int h){
	if(sala[n-1][h-1] == 'X'){
		sala[n-1][h-1] = '|';
		reservas = reservas -1;
		printf("Reserva cancelada!\n\n");
	}
	else{
		printf("Lugar ainda nao foi reservado.\n\n");
	}
}

void situacaoSala(){
	int resta = (70-reservas);
	printf("\nForam reservados %d lugares", reservas);
	printf("\nRestam %d lugares\n\n", resta);
}

void reservarCadeira(int n, int h){
	if(sala[n-1][h-1] == 'X')
		printf("Lugar ja reservado!\n\n");
	else{
		sala[n-1][h-1] = 'X';
		reservas++;
		printf("Lugar reservado com sucesso!\n\n");
	}
}

void criarsala(){
    int i, j;
	for (i=0; i < fileiras; i++) {
        for (j=0; j < assentos; j++) {
            sala[i][j] = '|';
        }
    }
}

float faturamentoCinema(){
	float fatur = (ingresso * reservas);
	return fatur;
}

void main()
{ 
	criarsala();
    int a=0;
    float faturamento;
    int fil, cad;
	    printf("\nDigite o preco do ingresso: ");
	    while(!scanf("%f",&ingresso)){
			while(getchar()!='\n'){
				printf("Preco invalido!");
			}
			printf("\nDigite o preco do ingresso novamente: ");
		}
	
    int op;
    do {
        printf("1 - Visualizar a sala\n");
        printf("2 - Situacao da sala\n");
        printf("3 - Reservar cadeira\n");
        printf("4 - Cancelar cadeira\n");
        printf("5 - Preco do ingresso\n");
        printf("6 - Faturamento\n");
        printf("0 - Sair\n");
        printf("Insira a opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                visualizarSala();
                break;
            case 2:
				situacaoSala();
				break; 
            case 3:
            	printf("Digite a a fileira: ");
            	scanf("%d", &fil);
            	printf("Digite a a cadeira: ");
            	scanf("%d", &cad);
            	printf("\n\n");
            	reservarCadeira(fil, cad);
            	break;
            case 4:
            	printf("Digite a a fileira: ");
            	scanf("%d", &fil);
            	printf("Digite a a cadeira: ");
            	scanf("%d", &cad);
            	printf("\n\n");
            	cancelarCadeira(fil, cad);
            	break;
            case 5:
            	printf("\nDigite o preco do ingresso: ");
	    		while(!scanf("%f",&ingresso)){
					while(getchar()!='\n'){
						printf("Preco invalido!");
					}
					printf("\nDigite o preco do ingresso novamente: ");
				}
				break;
			case 6:
				faturamento = faturamentoCinema();
				printf("Faturamento total eh de R$ %.1f", faturamento);
				break;
            case 0:
                op = 0;
                break;
            default:
                printf("Opcao invalida");
                break;
        }
    } while(op != 0);
}