/*********************************************************
******
******        FileName: videoToPicture.cpp
******          Author: zmant
******      AuthorMail: zmant724@gmail.com
******      CreateTime: 2017-06-01 23:37:05
******   Last Modified: 2017-06-01 23:37:05
******    Description : ----
*********************************************************/

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <dirent.h>
#include <iostream>

class VideoPicture
{
    public:
        VideoPicture();
        ~VideoPicture();

        void SetVideoPath(const std::string& path) { m_videoPath = path; }
        void SetFrameRate(int rate) { m_frameRate = rate; }
        void Process();

    private:
        int                 m_frameRate;
        std::string         m_videoPath;
};

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

int main(int argc, char* argv[])
{
    VideoPicture vp;
    vp.SetVideoPath(argv[1]);
    vp.Process();
    return 0;
}
