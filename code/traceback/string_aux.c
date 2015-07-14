
/**	@file string_aux.c
 *  @brief Funciones auxiliares de String
 *
 *	Este archivo consta de las implementacion de las funciones
 *	definidas en los protottipos
 *
 *  @author Calvo Alfaro, Angelo Alejandro (acalvoa)
 *  @bug No conocidos
*/

#include "string.h"
#include "stdlib.h"
size_t strlen(const char *str)
{
    const char *s;
    for (s = str; *s; ++s);
    return(s - str);
}
char* substr(char* cadena, int comienzo, int longitud)
{
	if (longitud == 0) longitud = strlen(cadena)-comienzo-1;
	
	char *nuevo = (char*)malloc(sizeof(char) * longitud);
	
	strncpy(nuevo, cadena + comienzo, longitud);
	
	strcat(nuevo,"...");
	return nuevo;
}
int ischar(char* cadena)
{
	int ascii = (int)cadena;
	if(ascii >= 0 && ascii <= 127){
		return 1;
	}
	else
	{
		return 0;
	}
}