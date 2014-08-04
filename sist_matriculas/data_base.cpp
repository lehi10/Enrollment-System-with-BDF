#include "data_base.h"

data_base::data_base()
{
    try
    {
        alumnos.open("../DB/alumnos.dbf",true);
        profesores.open("../DB/profesores.dbf",true);
        directores.open("../DB/directores.dbf",true);
        matriculas.open("../DB/matriculas.dbf",true);
        notas.open("../DB/notas.dbf",true);
        administrativos.open("../DB/administrativos.dbf",true);
    }
    catch(...)
    {
        cout<<"Error al abrir base de datos"<<endl;
    }
}
