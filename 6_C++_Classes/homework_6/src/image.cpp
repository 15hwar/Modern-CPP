#include "image.hpp"

#include <fstream>
#include <numeric>

int igg::Image::rows() const
{
    return igg::Image::row_;
}

int igg::Image::cols() const
{
    return igg::Image::col_;
}

const int& igg::Image::at(const int& row, const int& col) const
{
    return igg::Image::data_.at(row * igg::Image::col_ + col);
}

int& igg::Image::at(const int &row, const int &col)
{
    return igg::Image::data_.at(row * igg::Image::col_ + col);
}

bool igg::Image::FillFromPgm(const std::string& file_name)
{
    std::ifstream in(file_name, std::ios_base::in);
    if(!in) return false;

    // Read integers, if we read chars, we get 1 digit instead of the whole number
    std::string type;
    int rows = 0;
    int cols = 0;
    std::vector<int> data;
    in >> type >> rows >> cols;

    data.resize(rows * cols);
    int byte = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
        in >> byte;
        data[r * cols + c] = byte;
        }
    }
    igg::Image::row_ = rows;
    igg::Image::col_ = cols;
    igg::Image::data_ = data;
    return true;
}

void igg::Image::WriteToPgm(const std::string &file_name)
{
    std::ofstream out(file_name);

    out << "P2" << std::endl
        << row_ << " " << col_ << std::endl;
    for (int r = 0; r < row_; ++r) {
        for (int c = 0; c < col_; ++c) {
            out << data_[r * col_ + c] << " ";
        }
        out << std::endl;
    }
}

std::vector<float> igg::Image::ComputeHistogram(int bins) const
{
    float interval = 255. / bins;
    std::vector<float> histogram(bins, 0.);
    for (const auto &pixel : data_) {
        float histogram_val_prev = 0.;
        for (int i = 0; i < bins; i++) {
            float histogram_val_current = (i + 1) * 1. * interval;
            if (pixel - histogram_val_prev >= 0 && pixel - histogram_val_current <= 0)
                histogram[i] += 1. / data_.size();
            histogram_val_prev = histogram_val_current;
        }
    }
    return histogram;
}

void igg::Image::DownScale(int scale)
{
    int row_scaled = igg::Image::row_ / scale;
    int col_scaled = igg::Image::col_ / scale;
    std::vector<int> data_scaled;
    data_scaled.reserve(row_scaled * col_scaled);
    for(int i = 0; i < row_; i+=scale) {
        for(int j = 0; j < col_; j+=scale) {
            data_scaled.emplace_back(igg::Image::data_.at(i * col_ + j)); 
        }
    }
    data_ = data_scaled;
    row_ = row_scaled;
    col_ = col_scaled;
}

void igg::Image::UpScale(int scale)
{
    int row_scaled = igg::Image::row_ * scale;
    int col_scaled = igg::Image::col_ * scale;
    std::vector<int> data_scaled(row_scaled * col_scaled, 0);
    for(int i = 0; i < row_; i++) {
        int row_jump = i * scale;
        for(int j = 0; j < col_; j++) {
            int col_jump = j * scale;
            for(int u = 0; u < scale; u++) {
                for(int v = 0; v < scale; v++) {
                    data_scaled[(row_jump + u) * col_scaled + (col_jump + v)] = igg::Image::data_.at(i * col_ + j);
                }
            }
        }
    }
    data_ = data_scaled;
    row_ = row_scaled;
    col_ = col_scaled;
}
