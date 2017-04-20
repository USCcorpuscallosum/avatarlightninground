//
//  lightning.cpp
//  project: avatarlightninground
//

#include "lightning.h"
#include <math.h>

#define PI 3.14159265


// MAIN ERROR: many of the functions/variables in MainColorLine class are not recognized
    // Use of undeclared identifier "MainColorLine" "strokeWeight" "thetaMutation" "mainLines"

// constructor
MainColorLine::MainColorLine(float x1,float y1,float x2,float y2,int strokeWeight) {
    
}

//color of lightning
void MainColorLine::accentColor() {
    ofFill();
    ofSetColor(255, 255, 255);
    ofDrawLine(x1, y1, x2, y2);
    ofNoFill();
    ofSetColor(0, 0, 255);
    ofDrawLine(x1, y1, x2, y2);
}

//draw lightning segment
void MainColorLine::draw() {
    
    ofBackground(0);

    mainlines = vector <ofVec2f> MainColorLine();
    
    //draw up to 5 lines
    int numBolts = int(ofRandom(0,5));
    for (int i=0; i<numBolts; i++) {
        int xDestination = x[numBolts];
        int yDestination = y[numBolts];
        
        accentColor();
        
        //A COUPLE DIFFERENT VERSIONS
        ofDrawLine(PX,PY,xDestination,yDestination);
        //drawPath((float)PX, (float)PY, x[xDestination], (float)500);
        
        //above draws the accent lines and determines the main lines for future drawing
    }
    
    //now draw the main lines
    for (MainColorLine line : mainlines) {
        line.drawSegment();
    }
    
}

//recursive helper function
void MainColorLine::drawPath(float x1, float y1, float x2, float y2) {
    float totalDistance = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    
    recursiveDrawPath(x1, y1, x2, y2, totalDistance, 10);
}

// determine start/end points of lightning segment
void MainColorLine::recursiveDrawPath(float x1, float y1, float x2,
                       float y2, float distance, int counter) {
    
    float offset = round(counter/4);
    
    strokeWeight = counter;
    
    //JUST IN CASE
    if (counter == 0) return;
    
    float segmentPath = distance/ofRandom(6, 10);
    
    
    //once fairly close just close the gap
    float currentDistance = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    if (currentDistance < distance/10) {
        ofDrawLine(x1+offset, y1+offset, x2, y2);
        mainLines.add(new MainColorLine(x1,y1,x2,y2,counter));
        return;
    }
    
    double theta = atan(((y2-y1)/(x2-x1)));
    
    //That's some janky engineering. I don't understand why this was necessary
    //but it fixed the bug flawlessly so I'll just leave it here.
    if (x1>x2) {
        theta += PI;
    }
    
    //randomly mutated angle theta
    double mTheta = theta + ofRandom(-thetaMutation, thetaMutation);
    
    //calculate delta-x and delta-y, calculate curr seg endpoint
    double dx = segmentPath * cos(mTheta);
    double dy = segmentPath * sin(mTheta);
    float sx2 = (float)(x1 + dx);
    float sy2 = (float)(y1 + dy);
    
    //draw accent line
    ofDrawLine(x1+offset, y1+offset, sx2+offset, sy2+offset);
    
    //add line segment to list of main lines to draw after all accent lines are drawn
    mainLines.add(new MainColorLine(x1,y1,sx2,sy2,counter));
    
    counter--;
    
    
    //call recursively with new startpoints but same endpoints
    recursiveDrawPath(sx2, sy2, x2, y2, distance, counter);
    
    //uncomment below section for lightning branches
    /*
     if (int(random(10))==0) {
     recursiveDrawPath(sx2,sy2,x[int(random(x.length))],y2,distance,counter);
     }
     */
}

//recursiveDrawPath();


// ***** COLORS *****
// pretty pretty colors

/*
 void makeYellow() {
 stroke(255, 255, 0);
 }
 */
/*
 void makeGrey() {
 stroke(50);
 }
 
 void makeBlack() {
 stroke(0);
 }
 */
