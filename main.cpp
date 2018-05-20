
/**
  @Author: wangchuanchuan
  @Email:wangchuanchuan@iyunxiao.com
  @Date: 2018.05.19
  @Description: 利用第三方库RtAudio，在录制的时候播放声音，播放的声音可以分离出左右声道，也可以单声道播放。
                采用多线程来防止录制声音的时候主界面卡死
**/

#include "Recording.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Recording record;
    record.setWindowTitle("RecordRdAudio");
    record.show();

    return a.exec();
}
