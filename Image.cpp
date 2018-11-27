using namespace std;
#include <iostream>
#include <string>
#include "Image.h"
#include <time.h>
#include "SystemMemoryImage.h"
#include "GPUMemoryImage.h"

Image::Image(int x, int y, int duration, char *name) {
	this->pixel_x = x;
	this->pixel_y = y;
	this->duration = duration;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, (strlen(name) + 1), name);
}

Image::Image(const Image& img) {
	this->pixel_x = img.pixel_x;
	this->pixel_y = img.pixel_y;
	this->duration = img.duration;
	this->name = new char[strlen(img.name) + 1];
	strcpy_s(this->name, strlen(img.name) + 1, img.name);
}

ostream& operator<<(ostream& ost, Image& img) {
	/* Time objects to print the image according the duration*/
	time_t startsec, oldsec, newsec;
	startsec = oldsec = time(nullptr);
	/*Used as a counter*/
	int incrementer = 0;
	try {
		SystemMemoryImage &smi = dynamic_cast<SystemMemoryImage&>(img);
		ost << "System Memory Image" << endl;
	}
	/*Meaning the current img element in the vector is of GPUMemoy class so not printing anything in the exception*/
	catch (exception& e) {}
	try {
		GPUMemoryImage &gmi = dynamic_cast<GPUMemoryImage&>(img);
		ost << "GPU Memory Image. Shader = " << gmi.GetShader() << endl;
	}
	/*Meaning the current img element in the vector is of SystemMemory class so not printing anything in the exception*/
	catch (exception& e) {}
	/*Displaying the infromation for the Image vector*/
	ost << "\tImage name = " << img.name << "; pixel_x = " << img.pixel_x << "; pixel_y = " << img.pixel_y << "; duration : " << img.duration << endl;
	/*Looping to display the duration of the Image*/
	ost << "\tCounting the seconds for this Image : ";
	/*While duration is not reached this will print the value of duration at an interval of second*/
	while (incrementer < img.duration) {
		newsec = time(nullptr);
		if (newsec > oldsec)
		{
			ost << newsec - startsec << ", ";
			oldsec = newsec;
			incrementer++;
		}
	}
	ost << endl;
	/*Printing Memory requiremenets*/
	ost << "\tMemory requirements = " << img.BufferSize() << " bytes" <<endl;
	/*Returning the object to ostream*/
	return ost;
}
