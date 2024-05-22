#ifndef STRATEGIES_HPP_
#define STRATEGIES_HPP_

#include <vector>
#include <string>

namespace igg 
{

struct ImageData {
    int rows;
    int cols;
    int max_val;
    std::vector<std::vector<int>> data;
};

class IoStrategy {
public:
    virtual ImageData Read(const std::string &file) const = 0;
    virtual bool Write(const std::string &file, const ImageData &img_data) const = 0;
};

class PngIoStrategy : public IoStrategy {
public:
    ImageData Read(const std::string &file) const override;
    bool Write(const std::string &file, const ImageData &img_data) const override;
};

class PpmIoStrategy : public IoStrategy {
public:
    ImageData Read(const std::string &file) const override;
    bool Write(const std::string &file, const ImageData &img_data) const override;
};

}

#endif