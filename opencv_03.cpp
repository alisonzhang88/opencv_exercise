#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	Mat src = imread("./0001.jpg");
	if(src.empty())
	{
		cout<<"could not load image" << endl;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat m1;
	m1 = src.clone();

	Mat m2;
	src.copyTo(m2);

	Mat m3 = src;

	Mat m4 = Mat::zeros(src.size(), src.type());
	Mat m5 = Mat::ones(src.size(), src.type());
	imshow("m1", m1);
	imshow("m2", m2);
	imshow("m3", m3);
	imshow("m4", m4);

	waitKey(0);


	return 0;
}