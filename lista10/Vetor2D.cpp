#include "Vetor2D.h"

namespace lista10 {
    Vetor2D::Vetor2D(float x, float y) : x(x), y(y) {}

    Vetor2D Vetor2D::operator+(const Vetor2D& other) const {
        return Vetor2D(this->x + other.x, this->y + other.y);
    }

    bool Vetor2D::operator==(const Vetor2D& other) const {
        return this->x == other.x && this->y == other.y;
    }

    std::ostream& operator<<(std::ostream& os, const Vetor2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
}