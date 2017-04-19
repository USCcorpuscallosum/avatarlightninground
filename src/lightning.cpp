//
//  lightning.cpp
//  project: avatarlightninground
//

#include "lightning.h"

// function for movement/path of lightning 
	// INPUT: path? start/end points?
	// OUTPUT: none

// function to color lightning
	// INPUT: none
	// OUTPUT: color pallet?

// other functions...
void setup() {
    ofBackground(0,26,27);
}

vector<ofVec2f> mainlines;
vector<int> x = {100, 200, 300, 400, 500};
vector<int> y = {100, 200, 300, 400, 500};
float thetaMutation = .5;
float offset = 4;
int PX, PY;

//See bottom of file


void ofPath::setStrokeWidth(strokeWidth);
  //  setStrokeWidth(strokeWidth);
 //   ofDrawLine(x1, y1, x2, y2);
 //   ;   }




void draw() {
    ofBackground(0);
    PX=ofGetMouseX();
    PY=ofGetMouseY();
    
    mainlines = new vector<MainColorLine>();
    
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
    mainColor();
    for (MainColorLine line : mainlines) {
        line.drawSegment();
    }
}

//recursive helper function
void drawPath(float x1, float y1, float x2, float y2) {
    float totalDistance = sqrt((float)(Math.pow(x2-x1, 2)+Math.pow(y2-y1, 2)));
    
    recursiveDrawPath(x1, y1, x2, y2, totalDistance, 10);
}

void recursiveDrawPath(float x1, float y1, float x2,
                       float y2, float distance, int counter) {
    
    offset = (float)Math.ceil(counter/4);
    
    //JUST IN CASE
    if (counter == 0) return;
    
    float segmentPath = distance/random(6, 10);
    strokeWeight(counter);
    
    //once fairly close just close the gap
    float currentDistance = sqrt((float)(Math.pow(x2-x1, 2)+Math.pow(y2-y1, 2)));
    if (currentDistance < distance/10) {
        line(x1+offset, y1+offset, x2, y2);
        mainLines.add(new MainColorLine(x1,y1,x2,y2,counter));
        return;
    }
    
    double theta = Math.atan(((y2-y1)/(x2-x1)));
    
    //That's some janky engineering. I don't understand why this was necessary
    //but it fixed the bug flawlessly so I'll just leave it here.
    if (x1>x2) {
        theta += Math.PI;
    }
    
    //randomly mutated angle theta
    double mTheta = theta + random(-thetaMutation, thetaMutation);
    
    //calculate delta-x and delta-y, calculate curr seg endpoint
    double dx = segmentPath * Math.cos(mTheta);
    double dy = segmentPath * Math.sin(mTheta);
    float sx2 = (float)(x1 + dx);
    float sy2 = (float)(y1 + dy);
    
    //draw accent line
    line(x1+offset, y1+offset, sx2+offset, sy2+offset);
    
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
    
    
}//recursiveDrawPath();


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
