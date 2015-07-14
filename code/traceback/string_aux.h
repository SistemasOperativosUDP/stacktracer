
/**	@file string_aux.h
 *  @brief Funciones prototipo auxiliares de String
 *
 *	Este archivo consta de dos funciones auxiliares para la manipulacion
 *  de String que son strlen y substr. Estas funciones son necesarias
 *	para el correcto funcionamiento de traceback.
 *
 *  @author Calvo Alfaro, Angelo Alejandro (acalvoa)
 *  @bug No conocidos
*/

#ifndef __string_aux_h_
#define __string_aux_h_

#include "string.h"
#include "stdlib.h"

/** @brief funcion para contar largo de strings - strlen
 *	
 *	Esta funcion cuenta la cantidad de caracteres validos presentes
 *	en un string.
 *
 *	@param str representa el string que se obtendra su largo.
 *	@return La funcion retorna el largo del string suministrado.
*/
size_t strlen(const char *str);
/** @brief funcion para cortar strings - substr
 *	
 *	Esta funcion corta un string en una cantidad definida por el usuario.
 *
 *	@param cadena: Representa el string a cortar
 *	@param comienzo: Indica la posicion del arreglo char* en donde se comienza
 *	a cortar la cadena.
 *	@param longitud: Indica el largo que tendra la cadena
 *
 *	@return La funcion retorna el string cortado de acuerdo al largo especificado
 *	y se añade al final de este puntos suspensivos.
*/
char* substr(char* cadena, int comienzo, int longitud);
/** @brief funcion para identificar char string
 *	
 *	Esta funcion identifica si el char* es un string
 *
 *	@param cadena: Representa el string a analizar
 *
 *	@return La funcion retorna un 1 si es char o un 0 si es string
*/
int ischar(char* cadena);

#endif /* __string_aux_h_ */