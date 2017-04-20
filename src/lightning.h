//
//  lightning.h
//  project: avatarlightninground
//

#pragma once

#include "ofMain.h"
#include "lightning.cpp"


class MainColorLine {
    
public:

	// variables for position (used in constructor)
    float x1 = 1;
    float y1 = 1;
    float x2 = 2;
    float y2 = 2;
    volatile int strokeWeight;

    // variables used in other functions
    vector<ofVec2f> mainlines;
    vector<int> x = {100, 200, 300, 400, 500};
    vector<int> y = {100, 200, 300, 400, 500};
    float thetaMutation = 0.5;
    float offset = 4;
    float PX = ofGetMouseX();
    float PY = ofGetMouseY();

    // constructor
    MainColorLine(float x1,float y1,float x2,float y2,int strokeWeight);
    
    // other functions
    //void mainColor();
    void accentColor();
    void draw();
    void drawPath(float x1, float y1, float x2, float y2);
    void recursiveDrawPath(float x1, float y1, float x2, float y2, float distance, int counter);


    //long story short, this came about so that the accent colors would
    //never be drawn over the main colors
};

//void makeBlue() {
//    ofSetColor(23, 45, 250);
//    //ofColor(23, 45, 250);
//}
//void makeDarkBlue(){
//    ofSetColor(0, 26, 27);
//    //fill(0,26,27);
//}
