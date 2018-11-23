#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include "LinkedList.h"
#include "Parser.h"

int fn1(void* lista);
int fn2(void* lista);
int fn3();
int fn4();

int generarArchivoInforme(char* fileName,LinkedList* listaVentas);

int main()
{
    int ventasTotales;
    int ventasMayores1;
    //int ventasMayores2;
    //int ventasLCD;
    // Definir lista de ventas
    LinkedList* listaVentas;
    LinkedList* listaFiltrada;

    // Crear lista ventas
    listaVentas = ll_newLinkedList();
    listaFiltrada = ll_newLinkedList();

    // Leer ventas de archivo data.csv
    if(controller_loadFromText("data.csv",listaVentas)==1)
    {
        // Filtrar

        // Calcular montos
        printf("Calculando unidades vendidas totales...\n");
        ventasTotales=fn1(listaVentas);
        printf("%d\n",ventasTotales);
        printf("Calculando ventas mayores a $10000...\n");
        ventasMayores1=ll_count(listaVentas,fn2);
        printf("%d\n",ventasMayores1);

        printf("Calculando ventas mayores a $20000...\n");
        //ventasMayores2=ll_count(listaVentas,fn3());
        printf("Calculando ventas de TVs LCD totales...\n");
        //ventasLCD=ll_count(listaVentas,fn4());


        // Generar archivo de salida
        if(generarArchivoInforme("informe.csv",listaFiltrada)==1)
        {
            //printf("%d %d %d %d\n",ventasTotales,ventasMayores1,ventasMayores2,ventasLCD);
        }
        else
            printf("Error generando archivo\n");

    }
    else
        printf("Error leyendo ventas\n");


    return 0;
}

int generarArchivoInforme(char* fileName,LinkedList* listaVentas)
{
    /*int retorno=-1;
    int i=0;
    int len;

    if(fileName != NULL && listaVentas!= NULL)
    {
        fprintf(fileName,"id,nombre,horasTrabajadas,sueldo\n");
        len = ll_len(listaVentas);
        do
        {
            empleado = (Venta*)ll_get(listaVentas,i);
            Venta(empleado,bufferNom);
            Employee_getId(empleado,&bufferId);
            Employee_getSueldo(empleado,&bufferSuel);
            Employee_getHorasTrabajadas(empleado,&bufferHor);
            fprintf(fileName,"\n",);
            i++;
        }
        while(i < len);
        if(i == len)
        {
            retorno=0;
        }
    }
    return retorno;*/
    return 1;
}

int fn1(void* lista)
{
    int ret=0;
    int i=0;
    int len;
    Venta* ventas;
    len = ll_len(lista);
    if(lista!=NULL)
    {
       for(i=0;i<len;i++)
       {
        ventas=ll_get(lista,i);
        ret=ret+ventas->cantidad;

       }
    }
    //printf("\n\n\n%d\n\n\n",ret);
    return ret;
}
static int i=0;
int fn2(void* lista)
{
    int ret=0;
    Venta* ventas;

    if(lista!=NULL)
    {

        ventas=ll_get(lista,i);
        if(ventas->precioUnitario >= 10000.00)
        {
            ret=1;
        }
        i++;
        printf("%d\n",i);
    }
    return ret;
}

/*int* fn3()
{
    Venta* ventas;
    return 0;
}

int* fn4()
{
    Venta* ventas;
    return 0;
}
*/

