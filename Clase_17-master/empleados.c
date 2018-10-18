#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"
#include "empleados.h"

static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);
static int isValidAltura(float altura);

/**
*@brief Reserva un espacio de memoria capaz de guardar un empleado
*@return
*/
Empleado* empleado_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
}

/**
*@brief Libera el espacío de memoria que estaba reservado por un empleado
*@param this El empleado a ser borrado
*/
void empleado_delete(Empleado* this)
{
    free (this);
}

/**
*@brief Asigna un nombre a un empleado
*@param this El empleado al cual se le asignará el nombre
*@param nombre El nombre que se asignará al empleado
*@return Retorna 0 en caso de que el nombre se haya cambiado correctamente, caso contrario retorna -1.
*/
int empleado_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && isValidNombre(nombre))
    {
        strcpy(this -> nombre, nombre);
        retorno = 0;
    }
    return(retorno);
}

/**
*@brief
*@param
*@return
*/
int empleado_getNombre(Empleado* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && isValidNombre(nombre))
    {
        strcpy(nombre, this -> nombre);
        retorno = 0;
    }
    return(retorno);
}

/**
*@brief
*@param
*@return
*/
static int isValidNombre(char* nombre)
{
    return(true);
}

/**
*@brief Asigna un apellido a un empleado
*@param this El empleado al cual se le asignará el apellido
*@param apellido El apellido que se asignará al empleado
*@return Retorna 0 en caso de que el apellido se haya cambiado correctamente, caso contrario retorna -1.
*/
int empleado_setApellido(Empleado* this, char* apellido)
{
    int retorno = -1;

    if(this != NULL && isValidApellido(apellido))
    {
        strcpy(this -> apellido, apellido);
        retorno = 0;
    }
    return(retorno);
}

/**
*@brief
*@param
*@return
*/
int empleado_getApellido(Empleado* this, char* apellido)
{
    int retorno = -1;

    if(this != NULL && isValidApellido(apellido))
    {
        strcpy(apellido, this -> apellido);
        retorno = 0;
    }
    return(retorno);
}

/**
*@brief
*@param
*@return
*/
static int isValidApellido(char* apellido)
{
    return(true);
}

/**
*@brief Asigna un altura a un empleado
*@param this El empleado al cual se le asignará la altura
*@param altura La altura que se asignará al empleado
*@return Retorna 0 en caso de que el altura se haya cambiado correctamente, caso contrario retorna -1.
*/
int empleado_setAltura(Empleado* this, float altura)
{
    int retorno = -1;

    if(this != NULL && isValidAltura(altura))
    {
        this -> altura = altura;
        retorno = 0;
    }
    return(retorno);
}

/**
*@brief
*@param
*@return
*/
int empleado_getAltura(Empleado* this, float altura)
{
    int retorno = -1;

    if(this != NULL && isValidAltura(altura))
    {
        altura = this -> altura;
        retorno = 0;
    }
    return(retorno);
}

/**
*@brief
*@param
*@return
*/
static int isValidAltura(float altura)
{
    return(true);
}

/**
*@brief
*@param
*@return
*/
int empleado_compareNombre (Empleado* thisA, Empleado* thisB)
{
    return (strcmp(thisA -> nombre, thisB -> nombre));
}

/**
*@brief
*@param
*@return
*/
Empleado* empleado_newConParametros(char* nombre, char* apellido, float altura)
{
    Empleado* this = empleado_new();
    if(this == NULL ||
       empleado_setNombre(this, nombre)||
       empleado_setApellido(this, apellido)||
       empleado_setAltura(this, altura))
    {
        empleado_delete(this);
        this = NULL;
    }
    return(this);
}

/**
*@brief Imprime en pantalla los datos del empleado.
*@param this Es el empleado.
*/
void empleado_print(Empleado* this)
{
    if(this != NULL)
    {
        printf("Nombre: %s\nApellido: %s\nAltura: %.2f", this -> nombre, this -> apellido, this -> altura);
    }
}
