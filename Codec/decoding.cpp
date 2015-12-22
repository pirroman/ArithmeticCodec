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
        uint reading_code    = 0;
        udouble code         = 0;
        udouble low_code     = 0;
        udouble hight_code   = 0;

        while(!file_for_decoding.atEnd())
        {
            file_for_decoding.read((char*) &reading_code, sizeof(uint));
            code = reading_code / ALL_CUT;
            while(reading_code)
            {
                for(auto iterator = cuts_for_coding.begin(); iterator != cuts_for_coding.end(); ++iterator)
                {
                    if(iterator->value().isOwn_cut(code))
                    {
                        newFile.write((char*) &iterator->key());
                        low_code    = (iterator->value().low);
                        hight_code  = (iterator->value().hight);
                        break;
                    }
                } //end for iter
                code = (code - low_code)/(hight_code - low_code);
            } //end while reading_code
        } //end while file_for_decoding
    }
}
