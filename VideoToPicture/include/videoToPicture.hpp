/*********************************************************
******
******        FileName: VideoToPicture/videoToPicture.hpp
******          Author: zmant
******      AuthorMail: zmant724@gmail.com
******      CreateTime: 2017-06-02 19:09:20
******   Last Modified: 2017-06-02 19:09:20
******    Description : ----
*********************************************************/

#ifndef _VIDEO_TO_PICTURE_H_
#define _VIDEO_TO_PICTURE_H_

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

        void SetVideoPath(const std::string& path) { std::cout<<"FSF"<<std::endl;m_videoPath = path; }
        void SetFrameRate(int rate) { m_frameRate = rate; }
        void Process();

    private:
        int                 m_frameRate;
        std::string         m_videoPath;
};

#endif
