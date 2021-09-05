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

	Mat result = Mat::zeros(src.size(), src.type());

	int blue, green, red;
	int gray;

	for(int row = 0; row < height; row++)
	{
		 uchar* curr_row = src.ptr<uchar>(row);
		 uchar* result_row = result.ptr<uchar>(row);
		 for(int col=0; col<width; col++)
		 {
		 	blue = *curr_row++;
		 	green = *curr_row++;
		 	red = *curr_row++;

		 	*result_row++ = blue;
		 	*result_row++ = green;
		 	*result_row++ = red;
		 }
	}


	imshow("output", result);


	waitKey(0);


	return 0;
}