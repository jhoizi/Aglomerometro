#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int tipo(){
  	int tipo = 1 + (rand() % 2);
  	return tipo;
}

int gerar_quantidade(){
  int quantidade = 1 + (rand() % 5);
  return quantidade;
}

void gravar_dados(FILE *arquivo, int dados[2]){
	fprintf(arquivo, "%d,", dados[0]);
	fprintf(arquivo, "%d\n", dados[1]);
}

void sensor(int quant){
	
	FILE *arquivo;
	arquivo = fopen("dadossensores.txt", "w");
	int q, t, cont = 0, dados[2];
	
  while(cont < quant){
 
    q = gerar_quantidade();
	  t = tipo();
    dados[0] = t;
	  dados[1] = q;
    gravar_dados(arquivo, dados);
    cont++; 
  }
  
	fclose(arquivo);
}
/*
extern int tipo();
extern int gerar_quantidade();
extern void gravar_dados(FILE *arquivo, int dados[2]);
extern void sensor();*/