#ifndef WINDOW_QCODEC_H
#define WINDOW_QCODEC_H

#include <QMainWindow>
#include "cut_low_hight.h"

typedef std::shared_ptr<symbol_and_probability> symbol_and_probability_ptr;

enum{ ALL_CUT   = 1_000_000,
      MOD_CONST = 100_000,
      MULTIPLE  = 100_000_000
};

namespace Ui {
class window_QCodec;
}

class window_QCodec : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_QCodec(QWidget *parent = 0);
    ~window_QCodec();

public slots:
    void on_button_for_encoding_clicked();
    void on_button_for_decoding_clicked();

private:
    Ui::window_QCodec *ui;
    void encoding(QFile &file_for_encoding);
    void decoding(QFile &file_for_decoding);
};

#endif // WINDOW_QCODEC_H
