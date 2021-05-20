#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>



void dados(char arquivo[], int dados[4]){
  FILE *arq = fopen(arquivo, "w");
  for(int i = 0; i < 3; i++){
    fprintf(arq, "%d\n" ,dados[i]);
  } 
  fclose(arq);
}

void ler_sensor(int sinais[10][2]){
  int a, c, cont1 = 0;
  
  FILE *arq;
  arq = fopen("dadossensores.txt", "r");
	
	while((fscanf(arq, "%d, %d\n", &a, &c)) != EOF){
		sinais[cont1][0] = a;
		sinais[cont1][1] = c;
		cont1++;
	}
	
  fclose(arq);
}

int nivel(float nag){
 if(nag > 1.0){
   printf("\033[0;32m");
   printf("\n\nNível de aglomeração aceitável\n\n");
   printf("\033[0m");
   return 0; 
 }
 else if(nag == 1.0){
   printf("\033[0;33m");
   printf("\n\nNível máximo de aglomeração aceitável\n\n");
   printf("\033[0m");
   return 1;
 }
 else{
   printf("\033[1;31m");
   printf("\nNível de aglomeração extrapolado\n\n");
   printf("\033[0m");
   return 2;
 } 
}

float calcular_aglomeracao(float area, float capacidade ,int pessoas){
  float nag;
  nag = (area * capacidade)/(pessoas * 2.25);
  return nag;
}

void consultar_informacoes(int dados[4]){
	FILE *arquivo;
	int cont = 0, temp;
	arquivo = fopen("dados.txt", "r");
	
	while((fscanf(arquivo,"%d\n", &temp)) != EOF){
		dados[cont] = temp;
		cont++;
	}
	fclose(arquivo);
}

void emitir_alerta(){
  printf("\033[1;31m"); 
  printf("\n\n### Entrada de pessoas bloqueada ###\n\n");
  printf("\033[0m");
}

void atualizar_dados(int sinais[2], int dado[3],float capacidade){
  char arq[10];
  strcpy(arq,"dados.txt");
	consultar_informacoes(dado);
	int pessoas, empregados, area, total,ni, t = 0;
	float nag;
  area = dado[0];
	empregados = dado[1];
	pessoas = dado[2];
  int c = (((area * capacidade)/2.25));
	total = pessoas + empregados;
  printf("Pessoas presentes no estabelecimento: %d\n", total);
  printf("Funcionários: %d\n", empregados);
  printf("Clientes: %d\n", pessoas);
  printf("Capacidade: %d\n", c);
	nag = calcular_aglomeracao(area, capacidade, total);
	ni = nivel(nag);
	
  if(ni == 2 || ni == 1){
    emitir_alerta();
  }

	if(sinais[0] == 1){
		if(ni == 0){
      printf("Entrada: ");
      printf("%d pessoa(s)\n", sinais[1]);
			pessoas += sinais[1];
			t = 1;
		}
    else{
      printf("\033[1;31m");
      printf("\n\nEntrada negada\n\n");
      printf("\033[0m");
    }
  }
	else{
		if(dado[2] >= sinais[1]){
      printf("Saída: ");
    	printf("%d pessoa(s)\n", sinais[1]);
			pessoas -= sinais[1];
			t = 1;
		}
  }
	
 	if(t == 1){
 		dado[2] = pessoas;
 		dados(arq, dado);
	}
 	
}

void gerenciador(int tam) {
  float arealocal, restricao, capa;
  int empregados, pessoas = 0, cont = 0,sin[tam][2], sinal[2];
  int dado[4], dados_txt[3];
  char arquivo[10]; 
  strcpy(arquivo, "dados.txt");

  printf("Digite a área total do local em metros quadrados: ");
  scanf("%f", &arealocal);

  printf("Digite a capacidade máxima em que o estabelecimento pode operar (%%): ");
  scanf("%f", &capa);
  
  printf("Digite o número total de empregados presentes: ");
  scanf("%d", &empregados);

  capa = capa/100;
  

  dado[0] = arealocal;
  dado[1] = empregados;
  dado[2] = pessoas;

  dados(arquivo, dado);
  ler_sensor(sin);

  while(cont < tam){
    sinal[0] = sin[cont][0];
    sinal[1] = sin[cont][1];
    system("cls");
    atualizar_dados(sinal, dados_txt, capa);
    cont++;
    sleep(4);
  }
  system("cls");
  printf("Fim da simulação");
}
/*
extern void ler_sensor();
extern void gerenciador();
extern float calcular_aglomeracao(float area, float capacidade, int pessoas);
extern int nivel(float nag);
extern void dados();
extern void atualizar_dados(int sinais[2], int dado[3],float capacidade);
extern void consultar_informacoes();
extern void emitir_alerta();*/
