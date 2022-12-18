#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSalvar,SIGNAL(triggered()),this,SLOT(salvar()));
    connect(ui->actionCarregar,SIGNAL(triggered()),this,SLOT(carregar()));
}

void MainWindow::atualizarDados()
{
    int mediaQuantidade = quantidade.getQuant();
    int menorQuant = quantidade.getMenorQuant();
    int maiorQuant = quantidade.getMaiorQuant();

    ui->quantidadeQuantidade->setText(QString::number(quantQuantidade));
    ui->menorQuant->setText(QString::number(menorQuant));
    ui->maiorQuant->setText(QString::number(maiorQuant));

}

void MainWindow::atualizarTabela()
{
    ui->tabelaDados->clearContents();
    for(int i=0; i<quantidade.size();i++){
        inserirProdutoNaTabela(quantidade[i],i);
    }

}

void MainWindow::inserirProdutoNaTabela(Produto a, int linha)
{
    ui->tabelaDados->setItem(linha,0,new QTableWidgetItem(a.getNome()));
    ui->tabelaDados->setItem(linha,1,new QTableWidgetItem(QString::number(a.getQuant())));
    ui->tabelaDados->setItem(linha,2,new QTableWidgetItem(a.getStatus()));
}

void MainWindow::salvar()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de produtos","","CSV(*.csv)");
    quantidade.salvarQuantidade(nomeArquivo);
}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de produtos","","CSV(*.csv)");
    quantidade.carregarQuantidade(nomeArquivo);
    for(int i=0;i<quantidade.size();i++){
        ui->tabelaDados->insertRow(i);
        inserirProdutoNaTabela(quantidade[i],i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Produto Produto;
        produto.setNome(ui->entradaNome->text());
        produto.setQuant(ui->entradaQuant->text().toDouble());

        int linha = ui->tabelaDados->rowCount();
        ui->tabelaDados->insertRow(linha);
        inserirProdutoNaTabela(produto,linha);


        quantidade.inserirProduto(produto);
        atualizarDados();
}


void MainWindow::on_pushButton_2_clicked()
{
    quantidade.ordenarPorNome();
        atualizarTabela();
}


void MainWindow::on_pushButton_3_clicked()
{
    quantidade.ordenarPorQuant();
        atualizarTabela();
}

