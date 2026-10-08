#include <eigen3/Eigen/Dense>
#include <iostream>

int main() {
        Eigen::MatrixXd matrix = Eigen::MatrixXd::Zero(5, 5);
        std::cout << matrix << std::endl;
        matrix.topLeftCorner<3, 3>().setIdentity();
        std::cout << matrix.topLeftCorner<3, 3>() << std::endl;
        std::cout << matrix << std::endl;
        return 0;
}