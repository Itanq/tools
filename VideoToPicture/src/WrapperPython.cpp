
#include "videoToPicture.hpp"

#include <boost/python.hpp>
#include <boost/python/module.hpp>

BOOST_PYTHON_MODULE(libvtp)
{
    using namespace boost::python;
    class_<VideoPicture>("VideoPicture")
        .def("SetVideoPath", &VideoPicture::SetVideoPath)
        .def("SetFrameRate", &VideoPicture::SetFrameRate)
        .def("Process", &VideoPicture::Process)
        ;
}

