#ifndef THREAD_H
#define THREAD_H

#include "./rtaudio/RtAudio.h"

#include <QThread>
#include <QStringList>
#include <QString>
#include <iostream>
#include <cstdlib>
#include <QDebug>
#include <cstring>
#include <QObject>

using namespace std;

class pthread :public QThread
{
//    Q_OBJECT
public:
    pthread();
    static void ErrorCallback(RtAudioError::Type type, const std::string &errorText);
    static int record(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
               double streamTime, RtAudioStreamStatus status, void *userData);

    static int saw( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
             double streamTime, RtAudioStreamStatus status, void *userData );
    bool flag;
    int num;//通过num进行判断是使用左声道、右声道、双声道


protected:
    void run();

private:
    RtAudio adc;
    RtAudio::StreamParameters input;
    RtAudio::StreamParameters output;
};

#endif // THREAD_H
