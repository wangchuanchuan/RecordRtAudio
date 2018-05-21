#include "Thread.h"
#include "Recording.h"
#include <QDebug>

pthread::pthread()
{
    //connect(this, &pthread::Signal, this, &pthread::run);
}


int pthread::saw( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData )
{
      unsigned int i, j;
      double *buffer = (double *) outputBuffer;
      double *lastValues = (double *) userData;

      if ( status )
        std::cout << "Stream underflow detected!" << std::endl;

      // Write interleaved audio data.
      for ( i=0; i<nBufferFrames; i++ ) {
        for ( j=0; j<2; j++ ) {
          *buffer++ = lastValues[j];

          lastValues[j] += 0.005 * (j+1+(j*0.1));
          if ( lastValues[j] >= 1.0 ) lastValues[j] -= 2.0;
        }
      }

      return 0;
}

int pthread::record(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData)
{
    if (status)
    {
        cout <<"status = "<<status<< " Stream overflow detected! " << std::endl;//检测到流溢出!
    }

    short* output = static_cast<short*>(outputBuffer);
    short* input = static_cast<short*>(inputBuffer);
    short n = nBufferFrames;

    qDebug()<<"nBufferFrames = "<<n<<endl;

    int i = *(static_cast<int*>(userData));

    if(i == 2)
    {
        for (i = 0; i < nBufferFrames; i += 1)
        {
            output[i] = input[i];
        }
    }
    else
    {
        for (; i < nBufferFrames; i += 2)
        {
            output[i] = input[i];
        }
    }

    qDebug()<<"output:"<<output<<endl;
    qDebug()<<"input:"<<input<<endl;
    qDebug()<<"streamTime:"<<streamTime<<endl;
    qDebug()<<"nBufferFrames:"<<nBufferFrames<<endl;
    qDebug()<<"status:"<<status<<endl;

    return 0;
}

void pthread::ErrorCallback(RtAudioError::Type type, const std::string &errorText)
{
    cout << "errorText："<< errorText << endl;
    RtAudio ra;
    for (;;) {
        int flag = 0;
        for(int i = 0 ; i < ra.getDeviceCount() ; i++)
        {
            QString str = ra.getDeviceInfo(i).name.c_str();
            qDebug() << str;
            if (str.contains("麦克风")) {
                flag = 1;
                break;
            }
        }
        if(flag == 1)break;
    }
    qDebug() << 111;
    return;
    //emit Signal();
    //pthread pThread;
    //pThread.start();
}

void pthread::run()
{

    for(int i = 0 ; i < adc.getDeviceCount() ; i++)
    {
        qDebug()<< i << adc.getDeviceInfo(i).name.c_str();
    }

    if (adc.getDeviceCount() < 1) {
        cout << "\nNo audio devices found!\n";
        exit( 0 );
    }

    input.deviceId = adc.getDefaultInputDevice();
    input.nChannels = 2;
    input.firstChannel = 0;

    output.deviceId = adc.getDefaultOutputDevice();
    output.nChannels = 2;
    output.firstChannel = 0;

    //unsigned int sampleRate = 44100;
    unsigned int bufferFrames = 256; // 256 sample frames

    try {
        adc.openStream(&output, &input, RTAUDIO_SINT16, Recording::m_sampleRate,
                       &bufferFrames, &record, static_cast<void*>(&num),
                       NULL, &ErrorCallback);

        adc.startStream();


    }
    catch (RtAudioError& e) {
        e.printMessage();
        exit(0);
    }
    while (flag);

    try {
        adc.stopStream();
    }
    catch (RtAudioError& e)
    {
        e.printMessage();
    }

    if (adc.isStreamOpen())
    {


        adc.closeStream();
    }

    qDebug()<<"m_sampleRate = "<<Recording::m_sampleRate<<endl;
    qDebug()<<"m_RtDataFormat = "<<Recording::m_RtDataFormat<<endl;

}

