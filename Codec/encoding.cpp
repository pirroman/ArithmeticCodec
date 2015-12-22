#include "window_qcodec.h"
#include <QHash>

namespace {//prototypes
    void writeFile               (QFile &file_for_compressing, QHash<char, cut> &cuts_for_coding);
    void write_service_info      (QFile &newFile, QHash<char, cut> & cuts_for_coding);
    void write_data              (QFile &file_for_compressing, QFile &newFile, \
                                            QHash<char, cut> &cuts_for_coding);
    uint setFrequency_for_symbols(QHash<char, uint> & pairs_char_and_frequency, QFile &file);
    void setCuts_for_symbols     (QHash<char, uint> & pairs_char_and_frequency, \
                                  QHash<char, cut> & cuts_for_coding, uint amount_symbols_in_file);
}

void window_QCodec::encoding(QFile &file_for_encoding)
{
    QHash<char, uint> pairs_char_and_frequency;
    QHash<char, cut>  cuts_for_coding;

    uint amount_symbols_in_file = setFrequency_for_symbols(pairs_char_and_frequency, file_for_encoding);

    setCuts_for_symbols(pairs_char_and_frequency, cuts_for_coding, amount_symbols_in_file);
    writeFile          (file_for_encoding, cuts_for_coding);
}

namespace {// functions for encoding method
    void write_service_info(QFile &newFile,QHash<char, cut> &cuts_for_coding)
    {
        uint alphabet = cuts_for_coding.size();
        newFile.write((char*) &alphabet, sizeof(uint));

        for(auto iterator = cuts_for_coding.begin(); iterator != cuts_for_coding.end(); ++iterator)
        {
            cut temp = iterator.value();
            newFile.write((char*) &iterator.key(), sizeof(char));
            newFile.write((char*) &temp.hight     , sizeof(udouble));
        }//end for
    }//end function

    void write_data(QFile &file_for_compressing,QFile &newFile,QHash<char, cut> &cuts_for_coding)
    {
        uint low                    = 0;
        uint hight                  = ALL_CUT;
        uint buffer_uint            = 0;
        uint multiple_for_buffer    = MULTIPLE;

        while(!file_for_compressing.atEnd())
        {
            char reading_symbol = 0;
            file_for_compressing.read((char*) &reading_symbol, sizeof(char));
            cut  cut_reading_symbol  = cuts_for_coding.value(reading_symbol);
            uint different_hight_low = hight - low;
            low                      = low + different_hight_low * cut_reading_symbol.low;
            hight                    = low + different_hight_low * cut_reading_symbol.hight - 1;
            if(low / MOD_CONST == hight / MOD_CONST)
            {
                buffer_uint         += (low / MOD_CONST) * multiple_for_buffer;
                multiple_for_buffer /= 10;
                low                  = 0;
                hight                = ALL_CUT;
                if(!multiple_for_buffer)
                {
                    newFile.write((char*) &buffer_uint, sizeof(uint));
                    buffer_uint         = 0;
                    multiple_for_buffer = MULTIPLE;
                }//end insert if

            } // end if
        }//end While

        if(buffer_uint)
            newFile.write((char*) &buffer_uint, sizeof(uint));

        if((low / MOD_CONST != hight / MOD_CONST) && (!low || (hight != ALL_CUT)))
        {
            newFile.write((char*) &low, sizeof(uint));
        }// end if
    } //end function


    setFrequency_for_symbols(QHash<char, uint> &pairs_char_and_frequency, QFile &file)
    {
        file.seek(0);

        char reading_symbol         = 0;
        uint amount_symbols_in_file = 0;

        for(; !file.atEnd(); ++amount_symbols_in_file)
        {
            file.read((char*) &reading_symbol, sizeof(char));
            ++pairs_char_and_frequency[reading_symbol];
        }
        file.seek(0);

        return amount_symbols_in_file;
    }

    setCuts_for_symbols(QHash<char, uint> &pairs_char_and_frequency, QHash<char, cut> &cuts_for_coding, uint amount_symbols_in_file)
    {
        QSet<symbol_and_probability_ptr> sort_probability;
        udouble probability = 0;
        for(auto iterator = pairs_char_and_frequency.begin(); iterator != pairs_char_and_frequency.end(); ++iterator)
        {
            probability                       = iterator->value() / amount_symbols_in_file;
            symbol_and_probability_ptr symbol = new symbol_and_probability(iterator->key(), probability);

            sort_probability.insert(symbol);
        }

        udouble left_border_cut  = 0;
        udouble right_border_cut = 0;
        while(sort_probability.hasNext())
        {
            symbol_and_probability temp = sort_probability.next();

            right_border_cut += temp.getProbability();
            cuts_for_coding[temp.getSymbol()] = {left_border_cut,\
                                             right_border_cut};
            left_border_cut   = right_border_cut;
        }
    }

    writeFile(QFile &file_for_compressing, QHash<char, cut> &cuts_for_coding)
    {
        QString name_for_new_compressing_file = QFileDialog::getSaveFileName(this,tr("Save encoding file"), "",
                                                                 tr("Address Book (*.huf);;All Files (*)"));
        if (name_for_new_compressing_file.isEmpty())
        {
            QMessageBox::critical(NULL, tr("ERROR"), tr("Input name!"));
            return;
        }
        QFile newFile(name_for_new_compressing_file);
        if (!newFile.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("don't work. Push ok."),newFile.errorString());
            return;
        }

        file_for_compressing.seek(0);

        write_service_info(newFile, cuts_for_coding);
        write_data        (file_for_compressing, newFile, \
                                       cuts_for_coding);

        file_for_compressing.seek(0);
        newFile.close();
    }
}//end namespace

