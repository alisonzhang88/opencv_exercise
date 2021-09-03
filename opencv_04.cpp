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

	int height = src.rows;
	int width = src.cols;
	int ch = src.channels();
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			Vec3d bgr = src.at<Vec3d>(i, j);
			bgr[0] = 255 - bgr[0];
			bgr[1] = 255 - bgr[1];
			bgr[2] = 255 - bgr[2];
			src.at<Vec3d>(i, j) = bgr;
		}
	}

	imshow("output", src);


	waitKey(0);


	return 0;
}