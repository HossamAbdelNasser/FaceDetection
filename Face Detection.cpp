#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace cv;


int main(){
    string path = "C:/Users/HP/Desktop/test/";
    string imgName = "Angelina.jpg";
    string vidName = "";
    string imgPath = path + imgName;
    string vidPath = path + vidName;
    Mat img = imread(imgPath);
    Mat imgGrey,imgBlur, imgCanny, imgDil;
    
    CascadeClassifier faceCascade;
    
    faceCascade.load(path+"haarcascade_frontalface_default.xml");
    
    if(faceCascade.empty()){
        cout << "XML file not loaded" << endl;
    }
  
    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);
    
    for (int i; i<faces.size(); i++){
    
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0,255,0),3);
    }
    
    imshow("Image", img);

    waitKey(0);
    
}