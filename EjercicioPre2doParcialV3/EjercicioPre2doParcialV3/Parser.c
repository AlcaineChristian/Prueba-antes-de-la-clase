#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Compra.h"


int parser_parseCompras(FILE* fileName, LinkedList* lista)
{
    int ret=-1;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferPrecio[1024];
    char bufferUnidades[1024];
    char bufferIva[1024];
    int flagOnce = 0;
    Compra* compras;
    if(fileName != NULL && lista != NULL)
    {
        ret=1;
        do
        {
            if(flagOnce == 0)
            {
                fscanf(fileName,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferNombre, bufferId, bufferPrecio, bufferUnidades, bufferIva);
                flagOnce = 1;
            }
            fscanf(fileName,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferNombre, bufferId, bufferPrecio, bufferUnidades, bufferIva);
            compras = Compra_newConParametros(bufferNombre, bufferId, bufferPrecio, bufferUnidades, bufferIva);
            if(compras != NULL)
            {
                ll_add(lista, compras);
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
            ret = parser_parseCompras(pArchivo, lista);
            fclose(pArchivo);
        }
        ret=1;
    }
    return (ret);
}
