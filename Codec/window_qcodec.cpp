#include "window_qcodec.h"
#include "ui_window_qcodec.h"

window_QCodec::window_QCodec(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_QCodec)
{
    ui->setupUi(this);
}

window_QCodec::~window_QCodec()
{
    delete ui;
}

void window_QCodec::on_button_for_encoding_clicked()
{
    QString fileName_for_encoding = QFileDialog::getOpenFileName(this,tr("Select file"), "",tr("Text file (*.txt);;All Files (*)"));

    if (fileName_for_encoding.isEmpty())
    {
        QMessageBox::critical(NULL, tr("ERROR"), tr("selest file"));
        return;
    }
    QFile file_for_encoding(fileName_for_encoding);

    if(!file_for_encoding.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(NULL, tr("File don't reading!"), file_for_encoding.errorString());
        return;
    }

    encoding(file_for_encoding);
    file_for_encoding.close();
}

void window_QCodec::on_button_for_decoding_clicked()
{
    QString fileName_for_decoding = QFileDialog::getOpenFileName(this, tr("Selecct file for decoding"), "", tr("arifmethic file (*.arf);;All Files (*)"));
    if (fileName.isEmpty())
    {
        QMessageBox::critical(NULL, tr("ERROR"), tr("select file!"));
        return;
    }
    QFile file_for_decoding(fileName_for_decoding);

    if (!file_for_decoding.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(NULL, tr("File not reading"), file_for_decoding.errorString());
        return;
    }

    decoding(file_for_decoding);
    file_for_decoding.close();
}
