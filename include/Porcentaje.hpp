#include <stdexcept>
class Porcentaje
{
private:
    int numero;

public:
    Porcentaje()
    {
        this->numero = 0;
    }
    Porcentaje(int numero)
    {
        if (numero > 100 || numero < 0)
        {
            throw new std ::runtime_error("NUMERO FUERA DE RANGO");
        }
        else
        {
            this->numero = numero;
        }
    }
    ~Porcentaje() {}
    void Incrementar(int numero)
    {
        this-> numero += numero;//incrementa la variable con la variable anterior
    }
    void Disminuir(int numero)
    {
       this-> numero -= numero;
    }

    int  Imprimir()
    {
     return this->numero;
    }   
};