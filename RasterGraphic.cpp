#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Image.h"
#include "GraphicElement.h"
#include "RasterGraphic.h"
#include "GPUMemoryImage.h"
#include "SystemMemoryImage.h"

void RasterGraphic::InsertGraphicElement() {
	/* Name of the GraphicElement file*/
	string fName;
	/*Hold number of images*/
	int imgNumber;
	/*To hold ImageObjects*/
	vector<Image*> tempImage;
	/*To store the position of the GraphicElement*/
	int position;
	/*Total number of elements in the forward list GraphicElemetns*/
	int totalElements = distance(GraphicElements.begin(), GraphicElements.end());
	/*This will store the img data depending on the memoryType*/
	Image *imgStore;

	/*User Inputs*/
	cout << "Insert a GraphicElement in the RasterGraphic" << endl;
	cout << "Please enter the GraphicElement filename : ";
	cin >> fName;

	cout << "Entering the GraphicElement Images (the sets of dimensions and durations)" << endl;
	cout << "Please enter the number of Image : ";
	cin >> imgNumber;

	/*This loop will push all the data for a image into the vector tempImage*/
	for (int i = 0; i < imgNumber; i++) {
		int tempPixelX, tempPixelY, duration, memoryType;
		string tempName, GPUShaderName;
		cout << "Please enter pixel x-width for Image #" << i << " pixel_x: ";
		cin >> tempPixelX;
		cout << "Please enter pixel y-width for Image #" << i << " pixel_y: ";
		cin >> tempPixelY;
		cout << "Please enter the duration for this Image : ";
		cin >> duration;
		cout << "Please enter the name for this Image: ";
		cin >> tempName;
		cout << "Please enter the type for this Image (1 = SystemMemoryImage, 2 = GPUMemoryImage) : ";
		cin >> memoryType;
		/* If GPU MemoryImage is selected then following code is executed*/
		if (memoryType == 2) {
			cout << "Please enter the file name of the associated GPU Shader: ";
			cin >> GPUShaderName;
			/*Adding the details to the vector by calling GPUMemoryImage class constructor*/
			imgStore = new GPUMemoryImage(tempPixelX, tempPixelY, duration, (char*)tempName.c_str(), GPUShaderName);
			/*Details are stored in imgStore image pointer which then is added to tempImage vector*/
			tempImage.push_back(imgStore);
		}
		else {
		/*When SystemMemoryImage is selected*/
			/*Details are stored in imgStore image pointer which then is added to tempImage vector*/
			imgStore = new SystemMemoryImage(tempPixelX, tempPixelY, duration, (char*)tempName.c_str());
			tempImage.push_back(imgStore);
		}
	}
	/*When the GraphicElement is empty*/
	if (GraphicElements.empty()) {
		GraphicElements.push_front(GraphicElement(fName, tempImage));
		/*Adding the created Image object to the GraphicElement forward list at the beginning*/
		cout << endl;
		cout << "This is the first GraphicElement in the list" << endl;
		cout << endl;
	}
	/* When the list has one or more than one element*/
	else {
		/*This condition will be satisfied when there are two or more elements in the forward list*/
		if (totalElements > 1) {
			forward_list<GraphicElement>::iterator looper;
			/*Storing the first element of the list in looper variable*/
			looper = GraphicElements.begin();
			cout << "There are " << totalElements << " GraphicElement(s) in the list" << endl;
			cout << "Please specify the position, between 0 and " << totalElements - 1 << " to insert after : ";
			cin >> position;
			/*This will iterate untill user decided position is reached*/
			advance(looper, position);
			/* Insert after given two arguments starting position and the value of the element itself*/
			GraphicElements.insert_after(looper, GraphicElement(fName, tempImage));
		}
		else {
			/*Meaning there is only one element at the beginning of the list and this will insert it after first element*/
			GraphicElements.insert_after(GraphicElements.begin(), GraphicElement(fName, tempImage));
		}
	}/*Else ends*/
}/*Insert function ends*/

void RasterGraphic::DeleteGraphicElement() {
	if (!GraphicElements.empty()) {
	/* If the list is not empty then delete the first element from the list*/
	cout << "Delete the first GraphicElement from the RasterGraphic" << endl;
	GraphicElements.erase_after(GraphicElements.before_begin());
	cout << "GraphicElement Deleted" << endl;
	}
	else
		/*When the list is empty printing the message*/
		cout << "RasterGraphic is empty" << endl;
}

ostream& operator<<(ostream& ost, RasterGraphic& rg) {
	/*Looping variable to iterate through forwardlist*/
	forward_list<GraphicElement>::iterator looper;
	int incrementer = 0;
	/*If the GrpahicElements list is not empty*/
	if (!rg.GraphicElements.empty()) {
		/*Printing content*/
		ost << "RasterGraphic " << rg.name << endl;
		ost << "Run the RasterGraphic" << endl;
		for (looper = rg.GraphicElements.begin(); looper != rg.GraphicElements.end(); looper++) {
			ost << "GraphicElement #" << incrementer << ":" << *looper;
			incrementer++;
		}
	}
	else {
		/*When list is empty*/
		ost << "No GraphicElements in the RasterGraphic" << endl;
	}
	ost << "Output Finished" << endl;
	/*Returning the ostream object*/
	return ost;
}
