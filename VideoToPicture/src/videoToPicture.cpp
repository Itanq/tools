/*********************************************************
******
******        FileName: videoToPicture.cpp
******          Author: zmant
******      AuthorMail: zmant724@gmail.com
******      CreateTime: 2017-06-01 23:37:05
******   Last Modified: 2017-06-01 23:37:05
******    Description : ----
*********************************************************/

#include "videoToPicture.hpp"

VideoPicture::VideoPicture()
{
    m_frameRate = -1;
}

VideoPicture::~VideoPicture()
{
}

void VideoPicture::Process()
{
    cv::VideoCapture vcapture(m_videoPath);
    if(!vcapture.isOpened())
    {
        std::cout << " The " << m_videoPath << " Failed !!! " << std::endl;
        return;
    }

    int totalFrame = vcapture.get(CV_CAP_PROP_FRAME_COUNT);
    if(m_frameRate == -1)
        m_frameRate = vcapture.get(CV_CAP_PROP_FPS);

    int curCount=0;
    cv::Mat frame;
    while(curCount < totalFrame)
    {
        vcapture >> frame;
        cv::imwrite(std::to_string(curCount)+".jpg", frame);
        ++curCount;
    }
    vcapture.release();
}

extern "C"
{
    VideoPicture tmp;
    
    void SetVideoPath(const std::string& path)
    {
        tmp.SetVideoPath(path);
    }
}
