#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat image1 = imread("C:/image/add1.jpg", IMREAD_GRAYSCALE);
	Mat image2 = imread("C:/image/add2.jpg", IMREAD_GRAYSCALE);
	CV_Assert(!(image1.empty() || image2.empty()));

	double alpha = 0.6, beta = 0.7;
	Mat add_img1 = image1 + image2;
	Mat add_img2 = image1 * 0.5 + image2 * 0.5;
	Mat add_img3 = image1 * alpha + image2 * (1 - alpha);
	Mat add_img4;

	for (alpha = 0; alpha < 1; alpha += 0.01) {
		Mat add_img3 = image1 * alpha + image2 * (1 - alpha);
		imshow("add_img3", add_img3);
		waitKey(100);
	}
}