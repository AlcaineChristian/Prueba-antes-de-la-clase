#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int parser_parseCompras(FILE* fileName, LinkedList* lista);
int controller_loadFromText(char* path , LinkedList* lista);

#endif // PARSER_H_INCLUDED
