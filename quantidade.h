#ifndef QUANTIDADE_H
#define QUANTIDADE_H

#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>
#include "produto.h"

class Quantidade
{
private:
    QVector<Produto> quantidade;

public:
    Quantidade();
    void inserirProduto(Produto a);
    Produto operator[](int i);
    int getQuant();
    int getMaiorQuant();
    int getMenorQuant();
    void ordenarPorNome();
    void ordenarPorQuant();
    int size();
    bool salvarQuantidade(QString arquivo);
    bool carregarQuantidade(QString arquivo);
};

bool compararPorQuant(Produto a, Produto b);
bool compararPorNome(produto a, Produto b);

#endif // QUANTIDADE_H
