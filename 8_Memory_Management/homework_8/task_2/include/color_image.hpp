#ifndef COLOR_IMAGE_HPP_
#define COLOR_IMAGE_HPP_

#include "strategies.hpp"
#include <vector>
#include <string>
#include <memory>

namespace igg
{

class Image {
public:
    struct Pixel
    {
        int red;
        int green;
        int blue;
    };

    Image() = default;

    Image(int &row, int &col) {
        rows_ = row;
        cols_ = col;
        data_.resize(rows_ * cols_, Pixel{0, 0, 0});
    } 

    Image(const Image &var) = default;
    Image& operator=(Image &var) = default;
    Image(Image &&var) = default;
    Image& operator=(Image &&var) = default;

    int rows() const;
    int cols() const;
    const Pixel& at(const int &row, const int &col) const;
    Pixel& at(const int &row, const int &col);
    void DownScale(const int &scale);
    void UpScale(const int &scale);

    bool ReadFromDisk(const std::string &file);
    void WriteToDisk(const std::string &file);

    void SetIoStrategy(std::shared_ptr<igg::IoStrategy> strategy) {
        io_strategy_ = strategy;
    }

private:
    int rows_ = 0;
    int cols_ = 0;
    std::vector<Pixel> data_;
    std::shared_ptr<igg::IoStrategy> io_strategy_ = nullptr;

};

}

#endif