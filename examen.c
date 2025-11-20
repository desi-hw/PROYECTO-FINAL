/*Huitrón Was-Szabo Elizabeth Desireé
Proyecto Final*/
#include<stdio.h>
void leerAlmacenarVotos(int votos[][3], int *oyentes);
void calcularVotos(int votos[][3], int oyentes);
void reparticionDePuntos(int votos[][3], int oyentes, int cancionPrimero, int cancionSegundo);

int main()
{
  int i, oyentes, votos[100][3];
  printf("\t Concurso de Canciones \n");
  printf("Las canciones son: \n");
  for(i=0; i<10; i++)
  {
    printf("Cancion %d \n", i);
  }
  leerAlmacenarVotos(votos, &oyentes);
  calcularVotos(votos, oyentes);
  return 0;
}

void leerAlmacenarVotos(int votos[][3], int *oyentes)
{ 
  int song1, song2, song3, i=0;
  printf("Para finalizar ingrese un -1 en la primera opcion \n");
  while(i<=100)
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
  *oyentes = i;
}

void calcularVotos(int votos[][3], int oyentes)
{
  int contarVotos[10] = {0}, i, j, cancion, primero=-1, segundo=-1;
  int cancionPrimero=-1, cancionSegundo=-1;
  for(i=0; i<=oyentes; i++)
  {
    for(j=0; j<3; j++)
    {
      cancion=votos[i][j];
      if(cancion>=0 && cancion<10)
        contarVotos[cancion] = contarVotos[cancion] + 1;
    }
  }
  for(i=0; i<10; i++)
  {
    if(contarVotos[i]>primero)
    {
      segundo = primero;
      cancionSegundo = cancionPrimero;
      primero = contarVotos[i];
      cancionPrimero = i;
    }
    else
    {
      if(contarVotos[i]>segundo)
      {
        segundo = contarVotos[i];
        cancionSegundo = i;
      }
    }
  }
  for(i=0; i<10; i++)
  {
    printf("Cancion %d: %d votos \n", i, contarVotos[i]);
  }
  printf("La cancion mas votada es la %d con %d con votos \n", cancionPrimero, primero);
  printf("La segunda cancion mas votada es la %d con %d votos \n", cancionSegundo, segundo);
}

void reparticionDePuntos(int votos[][3], int oyentes, int cancionPrimero, int cancionSegundo)
{
  int i, j, puntosOyentes[100]={0}, puntosGanador=-1, ganador=-1;
  printf("Mostrar los puntos de los oyentes: \n");
  for(i=0; i<oyentes; i++)
  {
    int estaLaPrimera = 0, estaLaSegunda = 0;
    for(j=0; j<3; j++)
    {
      if(votos[i][j] == cancionPrimero)
        estaLaPrimera = 1;
      if(votos[i][j] == cancionSegundo)
        estaLaSegunda == 1;
    }
    if(estaLaPrimera == 1)
      puntosOyentes[i] = puntosOyentes[i] + 30;
    if(estaLaSegunda == 1)
      puntosOyentes[i] = puntosOyentes[i] +10;
    if(estaLaPrimera == 1 && estaLaSegunda == 1)
      puntosOyentes[i] = puntosOyentes[i] +10;
    printf("Oyente %d: %d puntos \n", i, puntosOyentes[i]);
    if(puntosOyentes[i] > puntosGanador)
    {
      puntosGanador = puntosOyentes[i];
      ganador = i;
    }
  }
  printf("Ganador: el oyente numero %d", ganador);
}
