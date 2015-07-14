/** @file traceback.c
 *  @brief La funcion Traceback
 *
 *  Este archivo contiene la funcion traceback y todas las funciones
 *	auxiliares adicionales necesarias para la ejecución de traceback. 
 *	las funciones del archivo corresponden a funciones necesarias por  
 * 	el la funcion traceback para operar de forma recursiva a traves de  
 *  la tabla de funciones generada. 
 *	Las busquedas en esta tabla son efectuadas a traves de metodos 
 *	recursivos en base a las especificaciones indicadas en el documento
 *	de requerimiento.
 *
 *  @author Calvo Alfaro, Angelo Alejandro (acalvoa)
 *  @bug No conocidos
 */

#include "traceback_internal.h"
#include "func_aux.h"
#include "ctype.h"
#include "string_aux.h"


/** @brief funcion locate_function
*	
*	funcion que busca de forma iterativa en la tabla de funciones
*	a partir de una direccion de memoria obtenida de las instrucciones
*	previas a la direccion de retorno con respecto a %ebp	
*
*	@param num indica el numero incremental recursivo. Siempre debe ser
*	cero al efectuarse la primera llamada.
*	@param	instruction corresponde a un puntero de 1 byte a la direccion
*	de llamada de la funcion a buscar
*	
*	@return la funcion retorna el indice de coincidencia con la tabla
*	de funciones.
*/
int locate_function(int num, char* instruction){
	if(strlen(functions[num].name) == 0){
		return -1;
	}
	else
	{
		if(functions[num].addr == instruction){
			return num;
		}
		else
		{
			return locate_function((num+1),instruction);
		}
	}
}
/** @brief funcion search_function
*	
*	funcion que busca a que funcion de la tabla corresponde un stack
*	frame determianado.
*
*	@param ebp indica el stack frame a analizar
*	
*	@return la funcion retorna la posicion de la funcion que coincide
*	de la tabla de funciones o un -1 en caso de no existir coincidencias
*/
int search_function(int* ebp){
	char* retorno_func = get_function_return(ebp);
	char* prev_instru = --retorno_func;
	int search = -1;
	int max_size = 0;
	while(search == -1){
		search = locate_function(0,prev_instru);
		if(search == -1){
			if(max_size > MAX_FUNCTION_SIZE_BYTES){
				printf("\nFATAL: NO EXISTEN MAS FUNCIONES EN EL STACK DE LLAMADA DE LA FUNCION TRACEBACK\n\n");
				return -1;
			}
			max_size++;
			char* prev_instru_new = --prev_instru;
			prev_instru = prev_instru_new;
		}
		else
		{
			break;
		}
	}
	return search;
}
/** @brief funcion isprint_string
*	
*	funcion que indica si un string valido apra ser impresa
*
*	@param string provee el string que debe ser analizado
*	
*	@return la funcion retorna un 1 en caso de que el string
*	se pueda imprimir o un 0 en caso de que no pueda ser
*	impreso.
*/
int isprint_string(char* string){
	int retorno = 1;
	int i;
	if(strlen(string) == 0) return 0;
	for(i=0;i<strlen(string);i++){
		if(!isprint(string[i])){
			retorno = 0;
			break;
		} 
	}
	return retorno;
}
/** @brief funcion print_args
*	
*	print_args es una funcion recursiva que se encarga de
*	imprimir en pantalla todos los argumentos de una funcion
*	que ha sido identificada a partir de su stack frame
*	el formato bajo el cual se imprimen dichos parametros
*	corresponde al requerido por el documento de requerimientos.
*
*	@param func es la funcion que ha sido identificada de la tabla
*	@param i corresponde al valor recursivo, siempre debe ser 0
*	@param ebp correponde al puntero hacia el stack frame
*	@param first es un puntero que debe ser siempre 1.
*	
*	@return la funcion no retorna valores.
*/
void print_args(const functsym_t func, int i, int* ebp, int first){
	//printf("%s",func.name);
	argsym_t args = func.args[i];
	if(strlen(args.name) == 0){
		if(first) printf("void");
		return;
	}
	else
	{	
		if(args.type == TYPE_CHAR){
			if(!first) printf(", ");
			char val = get_char_value(ebp,args.offset);
			if(isprint(val)){
				printf("char %s=%c", args.name, val);
			}
			else
			{
				int ascii = (int)val;
				printf("char %s='\\%d'",args.name, ascii);
			}
		}
		else if(args.type == TYPE_INT){
			if(!first) printf(", ");
			int val = get_int_value(ebp,args.offset);
			printf("int %s=%d", args.name, val);
		}
		else if(args.type == TYPE_FLOAT){
			if(!first) printf(", ");
			float val = get_float_value(ebp,args.offset);
			printf("float %s=%f", args.name, val);
		}
		else if(args.type == TYPE_DOUBLE){
			if(!first) printf(", ");
			double val = get_double_value(ebp,args.offset);
			printf("double %s=%lf", args.name, val);
		}
		else if(args.type == TYPE_STRING){
			if(!first) printf(", ");
			char* val = get_string_value(ebp,args.offset);
			if(isprint_string(val)){
				if(strlen(val) >= 25){
					val = substr(val,0,25);
				}
				printf("char* %s=\"%s\"", args.name, val);
			}
			else
			{
				printf("char* %s=%p",args.name, (void *)&val);
			}
		}
		else if(args.type == TYPE_STRING_ARRAY){
			if(!first) printf(", ");
			int fstring = 1;
			char** val = get_string_array_value(ebp,args.offset);
			int i;
			int j;
			char *mainc = "main";
			if(strcmp(func.name,mainc) == 0){
				j=1;	
			} 
			else{
				j=4;
			} 
			printf("{");
			for(i=0;i<j;i++){
				if(!fstring) printf(", ");
				if(i==3){
					printf("...");
					break;
				}
				char *txt = val[i];
				if(ischar(txt)){
					char fe = (int)txt;
					if(isprint(fe)){
						printf("\'%c\'", fe);
					}
					else
					{
						printf("%p", (void*)&txt);
					}
				}
				else
				{
					if(isprint_string(txt)){
						if(strlen(txt) >= 25){
							txt = substr(txt,0,25);
						}
						printf("\"%s\"", txt);
					}
					else
					{
						printf("%p", (void*)&txt);
					}
				}
				fstring = 0;
			}
			printf("}");
		}
		else if(args.type == TYPE_VOIDSTAR){
			if(!first) printf(", ");
			char memory[10];
			sprintf(memory,"%p", get_void_value(ebp,args.offset));
			memory[1] = 'v';
			printf("void* %s=%s",args.name,memory);
		}
		else if(args.type == TYPE_UNKNOWN){
			if(!first) printf(", ");
			int val = get_int_value(ebp,args.offset);
			printf("UNKNOWN=%p", (void *)&val);
		}
		return print_args(func, (i+1), ebp, 0);
	}
}
/** @brief funcion print_func
*	
*	print_func es una funcion que a partir de la posicion
*	de la funcion en la tabla y del stack frame idetificado
*	imprime la funcion de acuerdo al formato planteado en la
*	hoja de requerimientos.
*
*	@param pos correponde a la posicion dentro de la tabla
*	@param ebp correponde al puntero hacia el stack frame
*	@param main es un puntero que indica si ya hubo coicidecia con main
*	siempre debe ser 0
*	@param first es un puntero que debe ser siempre 1.
*	
*	@return la funcion no retorna valores.
*/
void print_func(int pos, int* ebp, int* main, int* first){
	if(pos == -1){
		if(!(*main)){
			if(!(*first)) printf(", in\n");
			printf("function %p(...)",--ebp);
		}
	}
	else{
		if(!(*first)) printf(", in\n");
		printf("function %s(",functions[pos].name);
		//printf("%i\n",pos );
		print_args(functions[pos],0,ebp, 1);
		printf(")");
		if(strcmp(functions[pos].name, "main") == 0){
			*main = 1;
			return;
		}
		if(*main >= 1) *main = *main + 1;
	}
	*first = 0;
}
/** @brief funcion print_func
*	
*	print_func es una funcion recursiva que se encarga de
*	recorrer el stack, recorriendo los stack frames hasta el
*	wrapper. Para esto hace uso del registro %ebp y mueve el
*	puntero hasta que no se enceuntran mas funciones despues
*	del wrapper que corresponde a un indice -1.
*
*	@param *fp correponde al puntero a un stack
*	
*	@return la funcion no retorna valores.
*/
void traceback(FILE *fp)
{
	printf("\n");
	int* ebp = get_ebp();
	int ma = 0;
	int first = 1;
	while(1){
		int pos = search_function(ebp);
		print_func(pos,ebp,&ma,&first);
		ebp = get_next_ebp(ebp);
		if(pos == -1) break;
	}
}

