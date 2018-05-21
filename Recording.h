#ifndef RECORDING_H
#define RECORDING_H

#include <QDialog>
#include <QComboBox>

#include "Thread.h"

namespace Ui {
class Recording;
}

class Recording : public QDialog
{
    Q_OBJECT

public:
    explicit Recording(QWidget *parent = 0);
    ~Recording();

private:
    QComboBox combo_rates;

public:
    static unsigned int m_sampleRate;//采样率4000, 5512, 8000, 9600, 11025, 16000, 22050,
                                           //32000, 44100, 48000, 88200, 96000, 176400, 192000

    static unsigned int m_RtDataFormat;//RTAUDIO_SINT8,RTAUDIO_SINT16,RTAUDIO_SINT24,RTAUDIO_SINT32
                                       //RTAUDIO_FLOAT32,RTAUDIO_FLOAT64
    int m_endian;//字节序
    int m_channel;//通道
    int m_byteWide;//位宽

private slots:

    void on_btnLeftChannel_clicked();

    void on_btnRightChannel_clicked();

    void on_btnSingleChannel_clicked();

    void on_btnStop_clicked();

    void on_btnSetting_clicked();


private:
    Ui::Recording *ui;
    pthread Thread;




};

#endif // RECORDING_H
