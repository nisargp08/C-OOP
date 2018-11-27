#include <iostream>
#include <string>
using namespace std;
#include "Image.h"
#include "GraphicElement.h"
#include "RasterGraphic.h"

void RasterGraphic::InsertGraphicElement(){
  /* Name of the GraphicElement file*/
  string fName;
  /*Hold number of images*/
  int imgNumber;
  /*To hold ImageObjects*/
  vector<Image*> tempImage;
	
  /*User Inputs*/
  cout << "Insert a GraphicElement in the RasterGraphic" << endl;
  cout << "Please enter the GraphicElement filename : ";
  cin >> fName;
  
  cout << "Entering the GraphicElement Images (the sets of dimensions and durations)" << endl;
  cout << "Please enter the number of Image : ";
  cin >> imgNumber;
  
  /*This loop will push all the data for a image into the vector tempImage*/
  for (int i = 0; i < imgNumber; i++) {
    int tempPixelX, tempPixelY, duration,memoryType;
    string tempName,GPUShaderName;
    cout << "Please enter pixel x-width for Image #" << imgNumber << " pixel_x: ";
    cin >> tempPixelX;
    cout << "Please enter pixel y-width for Image #" << imgNumber << " pixel_y: ";
    cin >> tempPixelY;
    cout << "Please enter the duration for this Image : ";
    cin >> duration;
    cout << "Please enter the name for this Image: ";
    cin >> tempName;
    cout << "Please enter the type for this Image (1 = SystemMemoryImage, 2 = GPUMemoryImage) : ";
    cin >> memoryType;
	  if(memoryType == 2){
	  	cout << "Please enter the file name of the associated GPU Shader: ";
		cin >> GPUShaderName;
		/*Adding the details to the vector by calling GPUMemoryImage class constructor*/  
		tempImage.push_back(GPUMemoryImage(tempPixelX,tempPixelY,duration,tempName,GPUShaderName);
	  }
  }
  /*When the GraphicElement is empty*/
  if(GraphicElements.empty()){
  	
	 cout << "This is the first GraphicElement in the list" << endl;
  }
}

RasterGraphic::DeleteGraphicElement(){
}

ostream& operator<<(ostream&,RasterGraphic&){
}
