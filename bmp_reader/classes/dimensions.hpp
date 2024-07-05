#pragma once

class point2 {
    public:
        double x_d, y_d;
        int x_i, y_i;
        point2() : x_i(0), y_i(0), x_d(0.0), y_d(0.0) {}
        point2(int x, int y) : x_i(x), y_i(y) {}
        point2(double x, double y) : x_d(x), y_d(y) {}

        bool operator==(const point2& other) const {
            return this->x_i == other.x_i && this->y_i == other.y_i;
        }
};

class point3 : public point2 {
    public:
        double z_d;
        int z_i;
        point3() : z_i(0), z_d(0.0), point2() {}
        point3(int x, int y, int z) : z_i(z), point2(x, y) {}
        point3(double x, double y, double z) : z_d(z), point2(x, y) {}

        bool operator==(const point3& other) const {
            return point2::operator==(other) && this->z_i == other.z_i;
        }
};
