#pragma once

#include "ofMain.h"
#include "WordParticle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVideoGrabber grabber;
    ofPixels prevPixels;
    ofPixels drawPixels;
    
    ofTexture texture;
    ofTrueTypeFont font;
    
    float threshold = 127;
    int wordIndex = 0;
    
    int spacingValue = 5;
    
    float gw;
    float gh;
    
    std::vector<string> phrase = {"本", "是", "無", "一", "物", "何", "處", "惹", "塵", "埃", "as", "there", "is", "nothing", "from", "the", "first", "where", "does", "the", "dust", "itself", "collect"};
    
    std::vector<WordParticle> wordParticles;
    

		
};
