#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture capture(0);

	for (;;) {
		Mat frame;
		capture.read(frame);

		Scalar red(0, 0, 255), green(0, 50, 0);
		Rect rect(200, 100, 100, 200);

		rectangle(frame, rect, red, 3);
		rectangle(frame, rect, green, -1);

		imshow("카메라 영상보기", frame);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}