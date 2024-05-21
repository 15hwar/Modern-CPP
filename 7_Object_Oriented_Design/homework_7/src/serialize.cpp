#include "homework_7.h"
#include <fstream>

void ipb::serialization::Serialize(const cv::Mat &m, const std::string &filename)
{
    std::ofstream file(filename, std::ios_base::out | std::ios_base::binary);

    int rows = m.rows;
    int cols = m.cols;
    int type = m.type();

    file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
    file.write(reinterpret_cast<char*>(&cols), sizeof(cols));
    file.write(reinterpret_cast<char*>(&type), sizeof(type));
    file.write(reinterpret_cast<char*>(m.data), rows * cols * CV_ELEM_SIZE(type));
}


cv::Mat ipb::serialization::Deserialize(const std::string &filename)
{
    std::ifstream file(filename, std::ios_base::in | std::ios_base::binary);

    int rows, cols, type;

    file.read(reinterpret_cast<char*>(&rows),sizeof(int));
    file.read(reinterpret_cast<char*>(&cols),sizeof(int));
    file.read(reinterpret_cast<char*>(&type),sizeof(int));

    cv::Mat img = cv::Mat::zeros(rows, cols, type);
    file.read(reinterpret_cast<char*>(img.data), rows * cols * CV_ELEM_SIZE(type));
    return img;
}