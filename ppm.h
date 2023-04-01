//
// Created by Tanmay Gujar on 3/31/23.
//

#ifndef JPEG_BRR_IMGIO_H
#define JPEG_BRR_IMGIO_H

#include <vector>

namespace JpegBrr {
    class PPM {
    public:
        std::vector<uint16_t> r, g, b;
        int height, width, max_color_val;
        PPM();
        ~PPM();
        void readFile(const std::string& fname);
        void writeFile(const std::string& fname);
    };
}


#endif //JPEG_BRR_IMGIO_H
