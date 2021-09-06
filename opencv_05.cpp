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
			cout << "bgr" << bgr << endl;
			bgr[0] = 255 - bgr[0];
			bgr[1] = 255 - bgr[1];
			bgr[2] = 255 - bgr[2];
			src.at<Vec3d>(i, j) = bgr;
		}
	}

	Mat result = Mat::zeros(src.size(), src.type());

	int blue, green, red;
	int gray;

	//cout << src << endl;
	cout << src.at<Vec3d>(0, 0) << endl; 
	// for(int row = 0; row < height; row++)
	// {
	// 	 for(int col=0; col<width; col++)
	// 	 {
	// 	 	result.at<Vec3d>(row, col)[0] = saturate_cast<uchar>(src.at<Vec3d>(row, col)[0] );
	// 	 	result.at<Vec3d>(row, col)[1] = saturate_cast<uchar>(src.at<Vec3d>(row, col)[1] );
	// 	 	result.at<Vec3d>(row, col)[2] = saturate_cast<uchar>(src.at<Vec3d>(row, col)[2] );
	// 	 	//cout << src.at<Vec3d>(row, col)[0] << "   " << result.at<Vec3d>(row, col)[0] << endl;
	// 	 	//result.at<Vec3d>(row, col)[0] = (src.at<Vec3d>(row, col)[0] );
	// 	 	//result.at<Vec3d>(row, col)[1] = (src.at<Vec3d>(row, col)[1] );
	// 	 	//result.at<Vec3d>(row, col)[2] = (src.at<Vec3d>(row, col)[2] );
	// 	 }
	// }

	imshow("source", src);
	imshow("output", result);


	waitKey(0);


	return 0;
}