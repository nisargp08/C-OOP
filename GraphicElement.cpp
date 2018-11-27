#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Image.h"
#include "GraphicElement.h"
#include "SystemMemoryImage.h"
#include "GPUMemoryImage.h"

GraphicElement::GraphicElement(const GraphicElement& ge) {
	/*Using type const_iterator for looping variable for vector<Image*> */
	vector<Image*>::const_iterator looper;
	fileName = ge.fileName;
	for (looper = ge.Images.begin(); looper != ge.Images.end(); looper++) {
		if (SystemMemoryImage *smi = dynamic_cast<SystemMemoryImage*>(*looper)) {
			Images.push_back(new SystemMemoryImage(*smi));
		}
		else if (GPUMemoryImage *gmi = dynamic_cast<GPUMemoryImage*>(*looper)) {
			Images.push_back(new GPUMemoryImage(*gmi));
		}
	}

}
ostream& operator<<(ostream& ost, GraphicElement& gl) {
	/*looper is a iterator object to loop through current vector*/
	vector<Image*>::iterator looper;
	int incrementer = 0;
	/*Printing the filename of the element*/
	ost << endl;
	ost << "\tfileName = " << gl.fileName << endl;
	/*Printing total no of Image in the vector*/
	for (looper = gl.Images.begin(); looper != gl.Images.end(); looper++) {
		ost << "Image #" << incrementer << ":" << **looper;
		incrementer++;
	}
	return ost;
}
