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

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	imshow("gray", gray);
	waitKey(0);


	return 0;
}