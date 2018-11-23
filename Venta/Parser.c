#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Venta.h"


int parser_parseVentas(FILE* fileName, LinkedList* lista)
{
    int ret=-1;
    char bufferId[1024];
    char bufferFecha[1024];
    char bufferCodigo[1024];
    char bufferCantidad[1024];
    char bufferPrecio[1024];
    char bufferCuit[1024];
    int flagOnce = 0;
    Venta* ventas;
    if(fileName != NULL && lista != NULL)
    {
        ret=1;
        do
        {
            if(flagOnce == 0)
            {
                fscanf(fileName,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferFecha, bufferId, bufferCodigo, bufferCantidad, bufferPrecio,bufferCuit);
                flagOnce = 1;
            }
            fscanf(fileName,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferFecha, bufferId, bufferCodigo, bufferCantidad, bufferPrecio,bufferCuit);
            ventas = Venta_newConParametros(bufferFecha, bufferId, bufferCodigo, bufferCantidad, bufferPrecio,bufferCuit);
            if(ventas != NULL)
            {
                ll_add(lista, ventas);
            }
            else
            {
               break;
            }
        }while(!feof(fileName));
    }



    return ret;
}

int controller_loadFromText(char* path , LinkedList* lista)
{
    int ret = -1;
    FILE* pArchivo;

    if(path != NULL && lista != NULL)
    {
        pArchivo = fopen(path, "r");
        if(pArchivo != NULL)
        {
            ret = parser_parseVentas(pArchivo, lista);
            fclose(pArchivo);
        }
        ret=1;
    }
    return (ret);
}
