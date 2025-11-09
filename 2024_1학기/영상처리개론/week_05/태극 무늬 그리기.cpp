#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat image(750, 850, CV_8UC3, Scalar(255, 255, 255));

	ellipse(image, Point(400, 400), Size(300, 300), 0, 0, -180, Scalar(0, 0, 255), -1); // 빨간색 반원
	ellipse(image, Point(400, 400), Size(300, 300), 0, 0, 180, Scalar(255, 0, 0), -1); // 파란색 반원
	ellipse(image, Point(250, 400), Size(150, 115), 0, 0, 180, Scalar(0, 0, 255), -1);
	ellipse(image, Point(550, 400), Size(150, 115), 0, 0, -180, Scalar(255, 0, 0), -1);

	imshow("타원 및 호 그리기", image);
	waitKey(0);
	return 0;
}