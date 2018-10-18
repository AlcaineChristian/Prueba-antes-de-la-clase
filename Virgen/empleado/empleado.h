typedef struct
{
    char nombre[50];
    char apellido[50];
    float altura;
    int idEmpleado;
}Empleado;

//Constructor
Empleado* empleado_new();
//Constructor con parametros
Empleado* empleado_newParametros(char* nombre,char* apellido,float altura);
//Destructor
void empleado_delete(Empleado* this);
//Funciones de nombre
int empleado_setNombre(Empleado* this,char* nombre);
int empleado_getNombre(Empleado* this,char* nombre);
int empleado_compareNombre(Empleado* thisA,Empleado* thisB);
//Funciones de apellido
int empleado_setApellido(Empleado* this,char* apellido);
int empleado_getApellido(Empleado* this,char* apellido);
//Funciones de altura
int empleado_setAltura(Empleado* this,float altura);
int empleado_getAltura(Empleado* this,float* altura);

//Mostrar
int empleado_print(Empleado*this);



