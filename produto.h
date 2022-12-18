#ifndef PRODUTO_H
#define PRODUTO_H

#include <QObject>

#define CORTE 30

class Produto
{

private:
    QString Nome;
    double Quant;

public:
    Produto();
    QString getNome() const;
    void setNome(const QString &Quant);
    double getQuant() const;
    void setQuant(double Quant);

    QString getStatus();
};

#endif // PRODUTO_H
