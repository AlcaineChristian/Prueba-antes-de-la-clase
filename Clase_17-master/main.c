#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"
#include "empleados.h"

int main()
{
    Empleado* auxiliar;
    auxiliar = empleado_newConParametros("Juan", "Perez", 1.45);
    empleado_print(auxiliar);
}
