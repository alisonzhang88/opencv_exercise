#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	//image 1
	Mat src1 = Mat::zeros(Size(400,400), CV_8UC3);
	Rect rect(100, 100, 100, 100);
	src1(rect) = Scalar(0,0,255);
	imshow("src1", src1);

	Mat src2 = Mat::zeros(Size(400,400), CV_8UC3);
	rect.x = 150;
	rect.y = 150;
	src2(rect) = Scalar(0,0,255);
	imshow("src2", src2);

	Mat dst1, dst2, dst3, dst4;
	bitwise_and(src1, src2, dst1);
	bitwise_xor(src1, src2, dst2);
	bitwise_or(src1, src2, dst3);
	bitwise_not(src1, dst4);

	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);







	waitKey(0);

	return 0;
}