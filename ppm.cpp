//
// Created by Tanmay Gujar on 3/31/23.
//

#include "ppm.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

namespace JpegBrr {
    using namespace std;
    PPM::PPM(): height(0), width(0){}
    PPM::~PPM(){}

    void PPM::readFile(const string& fname) {

        ifstream f(fname, ios::in | ios::binary);
        auto skip_comments = [&f]() {
            string comment;
            while(f.peek() == '#') getline(f, comment);
        };
        if (f.is_open()) {
            string magic;
            f >> magic;
            if (magic != "P6") {
                throw runtime_error("Invalid file format, magic number" + magic + "found, required P6");
            }

            skip_comments();

            string w, h, mv;
            f >> w; f >> h; f >> mv;
            try {
                this->width = stoi(w);
                this->height = stoi(h);
                this->max_color_val = stoi(mv);
            } catch (exception &e) {
                stringstream ss;
                ss << "Error parsing width, height, max color value to integers, " << e.what();
                throw runtime_error(ss.str());
            }

            this->r.reserve(this->height*this->width);
            this->g.reserve(this->height*this->width);
            this->b.reserve(this->height*this->width);


            int bytes_to_read = this->max_color_val < 256 ? 1 : 2;

            auto read_into_int = [&bytes_to_read, &f](vector<uint16_t>& v, int idx) {
                char* color_val;
                f.read(color_val, bytes_to_read);
                v[idx] = (uint8_t)color_val[0];
                if (bytes_to_read == 2) {
                    v[idx] << 8;
                    v[idx] |= (uint8_t)color_val[1];
                }
            };
            for (int i = 0; i < this->height*this->width; i++) {
                read_into_int(this->r, i);
                read_into_int(this->g, i);
                read_into_int(this->b, i);
            }
        } else {
            throw runtime_error("Unable to open file: " + fname);
        }
        f.close();
    }
    void write(const PPM& ppm);
}


