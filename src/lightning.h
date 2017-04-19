//
//  lightning.h
//  project: avatarlightninground
//

#pragma once

#include "ofMain.h"
#include "lightning.cpp"

void makeBlue() {
    ofSetColor(23, 45, 250);
    //ofColor(23, 45, 250);
}
void makeDarkBlue(){
    ofSetColor(0, 26, 27);
    //fill(0,26,27);
}
void accentColor() {
    ofFill();
    ofSetColor(255, 255, 255);
    ofDrawLine(x, y, x2, y2);
    ofNoFill();
    ofSetColor(0, 0, 255);
    ofDrawLine(<#float x1#>, <#float y1#>, <#float x2#>, <#float y2#>);
}

class MainColorLine {
public:
	// add functions here
    //long story short, this came about so that the accent colors would
    //never be drawn over the main colors
        float x1;
        float y1;
        float x2;
        float y2;
        const int strokeWidth =10;
    
MainColorLine(float x1,float y1,float x2,float y2,int strokeWeight) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
    
        }
        
    void ofPath;


	// add variables here


	// add constants here

};
