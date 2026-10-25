#ifndef VETOR2D_H
#define VETOR2D_H
#include <iostream>


namespace lista10 {
    class Vetor2D {
        private:
            float x, y;
        public:
            Vetor2D(float x = 0, float y = 0);
            
            Vetor2D operator+(const Vetor2D& other) const;

            bool operator==(const Vetor2D& other) const;

            friend std::ostream& operator<<(std::ostream& os, const Vetor2D& v);
    };
}

#endif