#include "produto.h"

QString Produto::getNome() const
{
    return Nome;
}

void Produto::setNome(const QString &value)
{
    Nome = value;
}

double Produto::getQuant() const
{
    return Quant;
}

void Produto::setQuant(double value)
{
    Quant = value;
}

QString Produto::getStatus()
{
    return Quant >= CORTE ? "Estoque alto" : "Estoque baixo";
}

Produto::Produto()
{

}
