#ifndef DATA_BASE_H
#define DATA_BASE_H
#include "libraries.h"
#include "dbf.h"
typedef  string location;
typedef DBF dataB;

class data_base
{
private:
    dataB alumnos;
    dataB profesores;
    dataB directores;
    dataB matriculas;
    dataB notas;
public:
    data_base();
};

#endif // DATA_BASE_H
