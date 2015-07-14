/**	@file func_aux.h
 *  @brief Funciones auxiliares assembly
 *
 *	Este archivo consta de las implementacion de las funciones
 *	definidas en los protottipos
 *
 *  @author Calvo Alfaro, Angelo Alejandro (acalvoa)
 *  @bug No conocidos
*/
#ifndef __FUNC_AUX_H
#define __FUNC_AUX_H

/** @brief funcion get_ebp
*	
*	funcion que recupera un puntero a la posicion del stack frame
*
*	@return la funcion retorna un puntero al stack frame que llamo
*	a la funcion traceback
*/
int* get_ebp();
/** @brief funcion get_next_ebp
*	
*	funcion que recupera un puntero al siguiente posicion del stack 
*	frame a partir de uno ya existente
*
*	@param	int* proporciona un puntero al stack frame
*	@return la funcion retorna un puntero al siguiente stack frame
*/
int* get_next_ebp(int*);
/** @brief funcion get_int_value
*	
*	funcion que recupera el valor del parametro relativo
*	a %ebp a partir de un offset
*
*	@param	int* proporciona un puntero al stack frame
*	@param	int  correponde al offset relativo al %ebp
*	@return la funcion retorna el valor int del argumento
*/
int get_int_value(int*, int);
/** @brief funcion get_char_value
*	
*	funcion que recupera el valor del parametro relativo
*	a %ebp a partir de un offset
*
*	@param	int* proporciona un puntero al stack frame
*	@param	int  correponde al offset relativo al %ebp
*	@return la funcion retorna el valor char del argumento
*/
char get_char_value(int*, int);
/** @brief funcion get_float_value
*	
*	funcion que recupera el valor del parametro relativo
*	a %ebp a partir de un offset
*
*	@param	int* proporciona un puntero al stack frame
*	@param	int  correponde al offset relativo al %ebp
*	@return la funcion retorna el valor float del argumento
*/
float get_float_value(int*, int);
/** @brief funcion get_double_value
*	
*	funcion que recupera el valor del parametro relativo
*	a %ebp a partir de un offset
*
*	@param	int* proporciona un puntero al stack frame
*	@param	int  correponde al offset relativo al %ebp
*	@return la funcion retorna el valor double del argumento
*/
double get_double_value(int*, int);
/** @brief funcion get_string_value
*	
*	funcion que recupera el valor del parametro relativo
*	a %ebp a partir de un offset
*
*	@param	int* proporciona un puntero al stack frame
*	@param	int  correponde al offset relativo al %ebp
*	@return la funcion retorna el valor string del argumento
*/
char* get_string_value(int*, int);
/** @brief funcion get_void_value
*	
*	funcion que recupera el valor del parametro relativo
*	a %ebp a partir de un offset
*
*	@param	int* proporciona un puntero al stack frame
*	@param	int  correponde al offset relativo al %ebp
*	@return la funcion retorna el valor void* del argumento
*/
void* get_void_value(int*, int);
/** @brief funcion get_string_array_value
*	
*	funcion que recupera el valor del parametro relativo
*	a %ebp a partir de un offset
*
*	@param	int* proporciona un puntero al stack frame
*	@param	int  correponde al offset relativo al %ebp
*	@return la funcion retorna el valor char** del argumento
*/
char** get_string_array_value(int*, int);
/** @brief funcion get_function_return
*	
*	funcion que recupera el valor de retorno de la funcion
*	de %ebp a partir de un stack frame
*
*	@param	int* proporciona un puntero al stack frame
*	@return la funcion retorna un puntero al vaor de retorno
*/
char* get_function_return(int*);

#endif /* __FUNC_AUX_H */
