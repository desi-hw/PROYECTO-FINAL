/*Huitrón Was-Szabo Elizabeth Desireé
Proyecto Final*/
#include<stdio.h>
void leerAlmacenarVotos();
void calcularVotos();
void reparticionDePuntos();
int main()
{
  int i, oyentes, votos[][3];
  printf("\tConcurso de Canciones \n");
  printf("Las canciones son: \n");
  for(i=0; i<10; i++)
  {
    printf("Cancion %d \n", i);
  }
  printf("¿Cuantos oyentes son? \n");
  scanf("%d", &oyentes);
  leerAlmacenarVotos(votos, oyentes);
  calcularVotos(votos, oyentes);
  return 0;
}
void leerAlmacenarVotos(int votos[][3], int oyentes)
{ 
  int song1, song2, song3, i=0;
  printf("Para finalizar ingrese un -1 en la primera opcion");
  while(i<=oyentes)
  {
    printf("Oyente %d \n", i);
    printf("Ingrese sus top 3 canciones, separado con espacios: ");
    scanf("%d" "%d" "%d", &song1, &song2, &song3);
    if(song1 == -1)
      break;
    votos[i][0] = song1;
    votos[i][1] = song2;
    votos[i][2] = song3;
    i++;
  } 
}
void calcularVotos(int votos[][3], int oyentes)
{
  int contarVotos[10] = {0}, i, j, cancion, primero, segundo;
  for(i=0; i<=oyentes; i++)
  {
    for(j=0; j<3; j++)
    {
      cancion=votos[i][j];
      if(cancion>=0 && cancion<10)
        contarVotos[cancion] = contarVotos[cancion] + 1;
    }
  }
  primero = contarVotos[0];
  segundo = contarVotos[0];
  for(i=0; i<10; i++)
  {
    if(contarVotos[i]>primero)
      primero = contarVotos[i];
    if(primero>segundo && contarVotos[i]>segundo)
      segundo = contarVotos[i];
  }
}
