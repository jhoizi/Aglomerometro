#include <stdio.h>

int calculo(float area, float restricao, int empregados){
  return (((area * restricao)/2.25)/100) - empregados;
}

void mostrar_informacoes(float area, float restricao, int empregados, int pessoas)
{
  system("clear");
  printf("O estabelecimento possui uma área de %.2fm²\n", area);
  printf("Operarando com %.0f%% da capacidade\n", restricao);
  printf("Com %d funcionários\n", empregados);
  printf("Podendo receber até %d pessoas em sua dependência\n", pessoas);
}

void capacidade(){
  float arealocal, capa;
  int empregados, pessoas;
  
  printf("Digite a área total do local em metros quadrados: ");
  scanf("%f", &arealocal);

  printf("Digite a capacidade máxima em que o estabelecimento pode operar (%%): ");
  scanf("%f", &capa);
  printf("Digite o número total de empregados presentes: ");
  scanf("%d", &empregados);

  pessoas = calculo(arealocal, capa, empregados);

  mostrar_informacoes(arealocal, capa, empregados, pessoas);
  //printf("%d", calculo(arealocal, capa, empregados));
}