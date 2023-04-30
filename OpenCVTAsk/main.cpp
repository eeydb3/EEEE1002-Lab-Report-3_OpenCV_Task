
#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc.hpp>



using namespace cv;

int main()
{
    namedWindow("OpenCV RGB Color Checker");   // Create a GUI window called photo

    int lowH = 0, highH = 179, lowS = 0, highS = 255, lowV = 0, highV = 255;    // Initialise some variables for HSV limits

    while(1)
    {

        Mat comparison;     // Join the two into a single image

        Mat Image = imread("BlueApple.BMP");// Read the image files
        lowH = 80, highH = 150;
        Mat ImageHSV1;       // Convert the frame to HSV and apply the limits
        cvtColor(Image, ImageHSV1, COLOR_BGR2HSV);
        inRange(ImageHSV1, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), ImageHSV1);
        Mat kernel = cv::getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
        cv::morphologyEx(ImageHSV1, ImageHSV1, MORPH_OPEN, kernel);
        cvtColor(ImageHSV1, ImageHSV1, COLOR_GRAY2BGR);
        cv::hconcat(Image, ImageHSV1, comparison);
        imshow("HSV Tester", comparison);

        Mat Image2 = imread("BlueCar.BMP");
        lowH = 80, highH = 150;
        Mat ImageHSV2;       // Convert the frame to HSV and apply the limits
        cvtColor(Image2, ImageHSV2, COLOR_BGR2HSV);
        inRange(ImageHSV2, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), ImageHSV2);
        cv::morphologyEx(ImageHSV2, ImageHSV2, MORPH_OPEN, kernel);
        cvtColor(ImageHSV2, ImageHSV2, COLOR_GRAY2BGR);
        // In range returns the equivalent of a grayscale image so we need to convert this before concatenation
        hconcat(Image2, ImageHSV2, comparison);
        imshow("HSV Tester", comparison);

        Mat Image3 = imread("GreenApple.BMP");
        lowH = 20, highH = 100;
        Mat ImageHSV3;       // Convert the frame to HSV and apply the limits
        cvtColor(Image3, ImageHSV3, COLOR_BGR2HSV);
        inRange(ImageHSV3, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), ImageHSV3);
        cv::morphologyEx(ImageHSV3, ImageHSV3, MORPH_OPEN, kernel);
        cvtColor(ImageHSV3, ImageHSV3, COLOR_GRAY2BGR);
        hconcat(Image3, ImageHSV3, comparison);
        imshow("HSV Tester", comparison);

        Mat Image4 = imread("GreenCar.BMP");
        lowH = 20, highH = 80;
        Mat ImageHSV4;       // Convert the frame to HSV and apply the limits
        cvtColor(Image4, ImageHSV4, COLOR_BGR2HSV);
        inRange(ImageHSV4, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), ImageHSV4);
        cv::morphologyEx(ImageHSV4, ImageHSV4, MORPH_OPEN, kernel);
        cvtColor(ImageHSV4, ImageHSV4, COLOR_GRAY2BGR);
        hconcat(Image4, ImageHSV4, comparison);
        imshow("HSV Tester", comparison);

        Mat Image5 = imread("RedApple.BMP");
        lowH = 0, highH = 34, lowS = 30;
        Mat ImageHSV5;       // Convert the frame to HSV and apply the limits
        cvtColor(Image5, ImageHSV5, COLOR_BGR2HSV);
        inRange(ImageHSV5, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), ImageHSV5);
        cv::morphologyEx(ImageHSV5, ImageHSV5, MORPH_OPEN, kernel);
        cvtColor(ImageHSV5, ImageHSV5, COLOR_GRAY2BGR);
        hconcat(Image5, ImageHSV5, comparison);
        imshow("HSV Tester", comparison);

        Mat Image6 = imread("RedCar.BMP");
        lowH = 0, highH = 20, lowS = 30;
        Mat ImageHSV6;       // Convert the frame to HSV and apply the limits
        cvtColor(Image6, ImageHSV6, COLOR_BGR2HSV);
        inRange(ImageHSV6, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), ImageHSV6);
        cv::morphologyEx(ImageHSV6, ImageHSV6, MORPH_OPEN, kernel);
        cvtColor(ImageHSV6, ImageHSV6, COLOR_GRAY2BGR);
        hconcat(Image6, ImageHSV6, comparison);
        imshow("HSV Tester", comparison);



        Mat Final1, Final2, Final3, FFinal;
        cv::hconcat(ImageHSV1, ImageHSV2, Final1); // Combine horizontally
        cv::hconcat(ImageHSV3, ImageHSV4, Final2); // Combine horizontally
        cv::hconcat(ImageHSV5, ImageHSV6, Final3); // Combine horizontally
        cv::vconcat(Final1, Final2, FFinal); // Combine vertically
        cv::vconcat(FFinal, Final3,FFinal);


            putText(FFinal, "Blue", Point(300,100), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 4);

            putText(FFinal, "Green", Point(300,350), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 4);

            putText(FFinal, "Red", Point(300,600), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 4);


        imshow("FinalHSV Values", FFinal);
        cv::imwrite("photo.jpg", FFinal); // Write the frame to a JPG

        int key = cv::waitKey(1);
        key = (key==255) ? -1 : key;    // Check if the esc key has been pressed
        if (key == 27)
            break;

    }


    destroyAllWindows();

    return 0;

}
