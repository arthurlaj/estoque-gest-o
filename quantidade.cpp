#include "quantidade.h"

Quantidade::Quantidade()
{

}

void Quantidade::inserirProduto(Produto a)
{
    quantidade.push_back(a);
}

Produto Quantidade::operator[](int i)
{
    return quantidade[i];
}

int Quantidade::Quant()
{
    int media = 0;
    for(Produto a : quantidade){
        quant+=a.getQuant();
    }
    return Quant/quantidade.size();
}

int Quantidade::getMaiorQuantidade()
{
    Produto *menor = std::min_element(quantidade.begin(),quantidade.end(),compararPorQuantidade);
    return menor->getQuant();
}

int Quantidade::getMenorQuantidade()
{
    Produto *maior = std::max_element(quantidade.begin(),quantidade.end(),compararPorQuantidade);
    return maior->getQuant();
}

void Quantidade::ordenarPorNome()
{
    std::sort(quantidade.begin(),quantidade.end(),compararPorNome);
}

void Quantidade::ordenarPorQuantidade()
{
    std::sort(quantidade.begin(),quantidade.end(),compararPorQuantidade);
}

int Quantidade::size()
{
    return quantidade.size();
}

bool Quantidade::salvarQuantidade(QString arquivo)
{
    QFile file(arquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly))
        return false;

    for(Produto a : quantidade){
        linha = a.getNome() + ',' + QString::number(a.getQuant()) + '\n';
        file.write(linha.toLocal8Bit());
    }
    return true;

}

bool Quantidade::carregarQuantidade(QString arquivo)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QString linha;
    Produto a;
    while(!file.atEnd()){
        linha = file.readLine();
        QStringList dados = linha.split(",");
        a.setNome(dados[0]);
        a.setQuant(dados[1].toDouble());
        inserirProduto(a);
    }
    return true;
}

bool compararPorQuantidade(Produto a, Produto b)
{
    return a.getQuant()>b.getQuant();
}

bool compararPorNome(Produto a, Produto b)
{
    return a.getNome()<b.getNome();
}
