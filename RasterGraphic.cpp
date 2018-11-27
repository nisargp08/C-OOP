#include <iostream>
#include <string>
#include "RasterGraphic.h"
using namespace std;

void RasterGraphic::InsertGraphicElement(){
  /* Name of the GraphicElement file*/
	string fName;
	/*Hold number of images*/
	int imgNumber;
  
  /*User Inputs*/
  cout << "Insert a GraphicElement in the RasterGraphic" << endl;
  cout << "Please enter the GraphicElement filename : ";
  cin >> fName;
  
  cout << "Entering the GraphicElement Images (the sets of dimensions and durations)" << endl;
  cout << "Please enter the number of Image : ";
  cin >> imgNumber;
  
  /*This loop will push all the data for a image into the vector tempImage*/
	for (int i = 0; i < imgNumber; i++) {
    int tempPixelX, tempPixelY, duration;
		string tempName;
    cout << "Please enter pixel x-width for Image #" << imgNumber << " pixel_x: ";
    cin >> tempPixelX;
    cout << "Please enter pixel y-width for Image #" << imgNumber << " pixel_y: ";
    cin >> tempPixelY;
    cout << "Please enter the duration for this Image : ";
    cin >> duration;
    cout << "Please enter the name for this Image: ";
    cin >> tempName;
    cout << "Please enter the type for this Image (1 = SystemMemoryImage, 2 = GPUMemoryImage) : ";
    cin >> 
  }
}

RasterGraphic::DeleteGraphicElement(){
}

ostream& operator<<(ostream&,RasterGraphic&){
}
