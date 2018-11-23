
#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Venta* Venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

void Venta_delete(Venta* this)
{
    free(this);
}

Venta* Venta_newConParametros(char* idVenta,char* fechaVenta,char* codigoProducto,char* cantidad,char* precioUnitario,char* cuitCliente)
{
    Venta* this;
    this=Venta_new();

    if(
    !Venta_setIdVenta(this,atoi(idVenta))&&
    !Venta_setFechaVenta(this,fechaVenta)&&
    !Venta_setCodigoProducto(this,codigoProducto)&&
    !Venta_setCantidad(this,atoi(cantidad))&&
    !Venta_setPrecioUnitario(this,atof(precioUnitario))&&
    !Venta_setCuitCliente(this,cuitCliente))
        return this;

    Venta_delete(this);
    return NULL;
}

int Venta_setIdVenta(Venta* this,int idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idVenta=idVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_getIdVenta(Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_setFechaVenta(Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(this->fechaVenta,fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_getFechaVenta(Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(fechaVenta,this->fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_setCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}

int Venta_getCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(codigoProducto,this->codigoProducto);
        retorno=0;
    }
    return retorno;
}

int Venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_setPrecioUnitario(Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Venta_setCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(this->cuitCliente,cuitCliente);
        retorno=0;
    }
    return retorno;
}

int Venta_getCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(cuitCliente,this->cuitCliente);
        retorno=0;
    }
    return retorno;
}

