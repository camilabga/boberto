#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Motor.hpp"

class Robot {
    private:
        Motor frontLeft{0}, frontRight{1}, backLeft{2}, backRight{3};
    
    public:    
        Robot();
        ~Robot();

        void stop();
        void forward(unsigned long int goal); 
        void backward(unsigned long int goal);
        
        // Movimento lateral
        void sidewaysRight(unsigned long int goal);
        void sidewaysLeft(unsigned long int goal);
        
        // Rotações
        void rotateLeft(unsigned long int goal);
        void rotateRight(unsigned long int goal);

        // Diagonais
        void moveRightForward(unsigned long int goal);
        void moveRightBackward(unsigned long int goal);
        void moveLeftForward(unsigned long int goal);
        void moveLeftBackward(unsigned long int goal);

};

#endif // ROBOT_HPP