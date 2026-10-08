#include <iostream>
#include <chrono>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

int main(int argc, char **argv)
{
        cv:: Mat image;
        image = cv::imread(argv[1]);
        if (image.data == nullptr)
        {
                cerr << "File " << argv[1] << " not found." << endl;
                return 0;
        }
        cout << "Image width: " << image.cols << ", height: " << image.rows << ", channels: " << image.channels() << endl;
        cv::imshow("image", image);
        cv::waitKey(0);
        chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
        for (size_t y = 0; y < image.rows; y++)
        {
                for (size_t x= 0; x < image.cols; x++)
                {
                        unsigned char* col_ptr = image.ptr<unsigned char>(y);
                        unsigned char* row_ptr = &col_ptr[x * image.channels()];
                        for (int c = 0; c != image.channels(); c++)
                        {
                                unsigned char data = row_ptr[c];
                        }
                }

        }
        chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
        cout << "Time taken: " << duration << " microseconds" << endl;

        cv::Mat image_another = image;
        image_another (cv::Rect(0, 0, 100, 100)).setTo(0);
        cv::imshow("image_another", image_another);
        cv::waitKey(0);

        cv::Mat image_clone = image.clone();
        image_clone (cv::Rect(0, 0, 100, 100)).setTo(255);
        cv::imshow("image_clone", image_clone);
        cv::waitKey(0);

        cv::destroyAllWindows();
        return 0;
}