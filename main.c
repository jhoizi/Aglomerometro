#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sensor.h"
#include "gerenciador.h"
#include "capacidade.h"

#define TAMANHO 30

void espera(){
  char c;
  printf("\n\n\n\n\n\n\n\n\n\nPressione qualquer tecla para ir ao menu\n");
  setbuf(stdin, NULL);
  scanf("%c", &c);
}

void inicio(){
  system("cls");
  printf("Seja bem vindo ao Aglomerômetro!\n\nSistema de controle de aglomeração em estabelecimentos");
  espera();
}

void informacoes(){
  printf("O Aglomerômetro tem como finalidade controlar a quantidade de pessoas nos estabelecimentos.\nUsando os dados de sensores infravermelhos e câmeras de seguranças dos estabelecimentos.\nO sistema gerencia a entrada e saída de pessoas de acordo com a capacidade de ocupação do local.");
}

void ops(){
  printf("MENU\n\n");
  printf("1 - Calcular capacidade\n");
  printf("2 - Simular funcionamento\n");
  printf("3 - Informações\n");
  printf("4 - Sair\n");
}

void Menu(){
  system("cls");
  int op = 0;
  ops();
  scanf("%d",&op);
  system("cls");
  while(op != 4){
    if (op == 1){
      system("cls");
      capacidade();
      espera();
    }else if (op == 2){
        system("cls");
      	sensor(TAMANHO);
        gerenciador(TAMANHO);
        espera();
    }else if (op == 3){
      system("cls");
      informacoes();
      espera();
    }else if (op == 4){
      break;
    }
    system("cls");
    ops();
    scanf("%d",&op);
  }
  system("cls");
}


int main(void) {
	
  srand(time(NULL)); 
  inicio();
  Menu();
  return 0;
}
