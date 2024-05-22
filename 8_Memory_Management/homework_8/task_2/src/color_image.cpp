#include "color_image.hpp"

int igg::Image::rows() const {
    return rows_;
}

int igg::Image::cols() const {
    return cols_;
}

const igg::Image::Pixel& igg::Image::at(const int& row, const int& col) const
{
    return igg::Image::data_.at(row * igg::Image::cols_ + col);
}

igg::Image::Pixel& igg::Image::at(const int &row, const int &col)
{
    return igg::Image::data_.at(row * igg::Image::cols_ + col);
}

void igg::Image::DownScale(const int &scale)
{
    int downscaled_rows = rows_ / scale;
    int downscaled_cols = cols_ / scale;
    std::vector<igg::Image::Pixel> downscaled_data;
    for(int i = 0; i < rows_; i += scale) {
        for(int j = 0; j < cols_; j += scale) {
            downscaled_data.emplace_back(data_.at(i * cols_ + j));
        }
    }
    data_ = downscaled_data;
    rows_ = downscaled_rows;
    cols_ = downscaled_cols;
}

void igg::Image::UpScale(const int &scale)
{
    int upscaled_rows = rows_ * scale;
    int upscaled_cols = cols_ * scale;
    std::vector<igg::Image::Pixel> upscaled_data(upscaled_rows * upscaled_cols, Pixel{0,0,0});
    for(int i = 0; i < rows_; i++) {
        int row_jump = i * scale;
        for(int j = 0; j < cols_; j++) {
            int col_jump = j * scale;
            for(int u = 0; u < scale; u++) {
                for(int v = 0; v < scale; v++) {
                    upscaled_data[(row_jump + u) * upscaled_cols + (col_jump + v)] = data_[i * cols_ + j];
                }
            }
        }
    }
    data_ = upscaled_data;
    rows_ = upscaled_rows;
    cols_ = upscaled_cols;
}

bool igg::Image::ReadFromDisk(const std::string &file)
{
    if(igg::Image::io_strategy_ == nullptr) 
        exit(1);
    igg::ImageData img = io_strategy_->Read(file);
    std::vector<Pixel> pixels;
    for(int i = 0; i < img.rows; i++) {
        Pixel pix{img.data[i][0], img.data[i][1], img.data[i][2]};
        pixels.emplace_back(pix);
    }
    rows_ = img.rows;
    cols_ = img.cols;
    data_ = pixels;
    return true;
}

void igg::Image::WriteToDisk(const std::string &file)
{
    if(io_strategy_ == nullptr)
        exit(1);

    std::vector<std::vector<int>> data;
    for(int i = 0; i < data_.size(); i++) {
        std::vector<int> pix{data_[i].red, data_[i].green, data_[i].blue};
        data.emplace_back(pix);
    }
    igg::ImageData img_data;
    img_data.rows = rows_;
    img_data.cols = cols_;
    img_data.max_val = 255;
    img_data.data = data;
    io_strategy_->Write(file, img_data);
}
