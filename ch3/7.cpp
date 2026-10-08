#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <eigen3/Eigen/Geometry>
int main(){
        Eigen:: Quaterniond q1(0.35, 0.2, 0.3, 0.1);
        q1.normalize();
        Eigen::Quaterniond q2(-0.5, 0.4, -0.1, 0.2);
        q2.normalize();
        Eigen::Quaterniond q;
        Eigen::Vector3d p(0.5, 0, 0.2);
        Eigen::Vector3d t1(0.3, 0.1, 0.1);
        Eigen::Vector3d pw = q1.conjugate() * (p - t1);
        Eigen::Vector3d t2(-0.1, 0.5, 0.3);
        Eigen::Vector3d p2 = q2 * pw + t2;
        
        std::cout << pw.transpose() << std::endl;
        std::cout << p2.transpose() << std::endl;
        return 0;
}