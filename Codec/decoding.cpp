#include "window_qcodec.h"

void window_QCodec::decoding(QFile &file_for_decoding)
{
    QString newFileName = QFileDialog::getSaveFileName(0, tr("Save decoding F"), "", ("Address book (*.txt);;All files (*)"));
    if (newFileName.isEmpty())
    {
        QMessageBox::critical(NULL, ("ERROR"), ("Input name!"));
        return;
    }
    QFile newFile(newFileName);
    if(newFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(NULL, ("Unable to open file"), newFile.errorString());
        return;
    }

    QHash<char, cut> cuts_for_coding;
    create_cuts_from_reading_service_info(cuts_for_coding, file_for_decoding);
    write_decoding_file(file_for_decoding, newFile, cuts_for_coding);

}

namespace {
    void create_cuts_from_reading_service_info(QHash<char, cut> &cuts_for_coding, QFile &file_for_decoding)
    {
        uint alphabet = cuts_for_coding.size();
        file_for_decoding.read((char*)&alphabet, sizeof(uint));

        char symbol              = 0;
        udouble left_border_cut  = 0;
        udouble right_border_cut = 0;
        while(alphabet--)
        {
            file_for_decoding.read((char*)&symbol          , sizeof(char)   );
            file_for_decoding.read((char*)&right_border_cut, sizeof(udouble));
            cuts_for_coding[symbol] = { left_border_cut,
                                        right_border_cut };
            left_border_cut         = right_border_cut;
        } //end while
    } //end function

    void write_decoding_file(QFile &file_for_decoding, QFile &newFile,QHash<char, cut> &cuts_for_coding)
    {

    }
}
