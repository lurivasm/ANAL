/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */


#include "permutaciones.h"
#include <time.h>
#include <stdlib.h>


/***************************************************/
/* Funcion: aleat_num Fecha: 22/09/2017            */
/* Autores:Lucía Rivas Molina y Daniel Santo-Tomás */
/* López                                           */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup)
{
  return inf+(rand()%(sup-inf+1));
}

/***************************************************/
/* Funcion: genera_perm Fecha: 22/09/2017          */
/* Autores: Lucía Rivas y Daniel Santo-Tomás       */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/
int* genera_perm(int N)
{
  int *array = (int*)malloc(sizeof(int)*N);
  if(!array) return NULL;

  int aux, aleat, i;
  for(i = 0; i < N; i++){
	*(array + i) = i;
  }

  for(i = 0; i < N; i++){
	aux = *(array + i);
	aleat = aleat_num(i, N - 1);
  if(aleat == -1){
    free(array);
    return NULL;
  }

	*(array + i) = *(array + aleat);
	*(array + aleat) = aux;
  }

  return array;
}

/***************************************************/
/* Funcion: genera_permutaciones Fecha: 29/09/2017 */
/* Autores: Lucía Rivas y Daniel Santo-Tomás       */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int N: Numero de elementos de cada              */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int N)
{
	if(n_perms<=0 || N <=0) return NULL;
	int **perm=(int**)malloc(sizeof(int*)*n_perms);
	if(!perm) return NULL;
	int i;
	for(i=0;i<n_perms;i++){
		perm[i] = genera_perm(N);
		if(!perm[i]) return NULL;
	}
	return perm;
}
