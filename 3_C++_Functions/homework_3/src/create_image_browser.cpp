#include <iostream>
#include "../include/html_writer.hpp"
#include "../include/image_browser.hpp"

using namespace std;
using image_browser::ImageRow;
using image_browser::ScoredImage;

int main() {
    vector<ImageRow> rows;
    rows.push_back({ScoredImage("web_app/data/000000.png",2.2345F),
            ScoredImage("web_app/data/000100.png",2.2345F),
            ScoredImage("web_app/data/000200.png",2.2345F)});
    rows.push_back({ScoredImage("web_app/data/000300.png",2.2345F),
            ScoredImage("web_app/data/000400.png",2.2345F),
            ScoredImage("web_app/data/000500.png",2.2345F)});
    rows.push_back({ScoredImage("web_app/data/000600.png",2.2345F),
            ScoredImage("web_app/data/000700.png",2.2345F),
            ScoredImage("web_app/data/000800.png",2.2345F)});
    image_browser::CreateImageBrowser("Image Browser","web_app/style.css",rows);
    return 0;
}