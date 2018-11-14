#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofTrueTypeFontSettings settings("DuanNingMaoBiXingShuZiTi-1.ttf", 20);
    settings.addRanges(ofAlphabet::Chinese);
    settings.addRanges(ofAlphabet::Latin); // Latin = English
    font.load(settings);
    
    
    ofSetBackgroundAuto(false);
    ofBackground(255);
    
    grabber.setup( 640, 480);
    
    
    gw = grabber.getWidth();
    gh = grabber.getHeight();
    
    prevPixels.allocate(gw, gh, OF_PIXELS_RGB);
    drawPixels.allocate(gw, gh, OF_PIXELS_RGB);
    
    texture.allocate(gw, gh, GL_RGB);
    
    prevPixels.set(255);
    drawPixels.set(255);
    
    for(int i = 0; i < spacingValue*spacingValue; i+=spacingValue)
    {
        WordParticle p;
        p.opacity = 255;
        wordParticles.push_back(p);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update()
{
    threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
    
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        ofPixels currentPixels = grabber.getPixels();
        
        for (int x = 0; x < gw; x++)
        {
            for (int y = 0; y < gh; y++)
            {
                // get current pixels brightness
                // ofColor color = currentPixels.getColor(x, y);
                // brightness = color.getBrightness();
                float currentBrightness = currentPixels.getColor(x, y).getBrightness();
                
                // prev pixels brightness
                float prevBrightness = prevPixels.getColor(x, y).getBrightness();
                
                float brightnessDiff = ofDist(currentBrightness, 0, prevBrightness, 0);
                
                if ( brightnessDiff > threshold)
                {
                    // there is movement!
                    drawPixels.setColor(x, y, ofColor(0));
                }
                else
                {
                    // there is no change - no movement
                    drawPixels.setColor(x, y, ofColor(255));
                }
            }
        }
        
        prevPixels = currentPixels;
        texture.loadData(drawPixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    
    
    
    // draw semi-transparent rectangles to create a fading effect
    ofSetColor(255, 2);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //texture.draw(0, 0);
    
    ofPushMatrix();
    
    // Mirroring
    ofTranslate(grabber.getWidth()*(ofGetWidth()/gw), 0);
    ofScale(-ofGetWidth()/gw, ofGetHeight()/gh);
    std::cout << -ofGetWidth()/gw << std::endl;
    
    for (int x = 0; x < gw; x += spacingValue)
    {
        for (int y = 0; y < gh; y += spacingValue)
        {
            float brightness = drawPixels.getColor(x, y).getBrightness();
            
            if (brightness < 20)
            {
                // draw a letter
                ofPushMatrix();
//                float randomNumEng = ofRandom(.75, 1.5);
//                float randomNumChi = ofRandom(1, 1.5);
//
//                // grab a random word from the phrase vector
//                float randomWord = ofRandom(phrase.size());
                ofTranslate(x, y);
                ofScale(-1, 1);
//
//                // if it's a chinese word
//                if(randomWord < (phrase.size()/2))
//                {
//                    ofSetColor(0, 150);
//                    ofScale(randomNumChi, randomNumChi);
//                }
//                // if it's an english word
//                else
//                {
//                    ofSetColor(0, 150);
//                    ofScale(randomNumEng, randomNumEng);
//                }
                ofSetColor(0, 150);
                ofPushMatrix();
                ofScale(gw/ofGetWidth(), gw/ofGetHeight());
                font.drawString(phrase[ofWrap(y*x/spacingValue*spacingValue, 0, 23)], 0, 0);
                ofPopMatrix();
//                if(wordIndex < phrase.size() - 1)
//                {
//                    wordIndex++;
//                }
//                else
//                {
//                    wordIndex = 0;
//                }
                ofPopMatrix();
            }
        }
    }
//    if(ofGetFrameNum() % 50 == 0)
//    {
//        if(wordIndex < phrase.size() - 1)
//        {
//            wordIndex++;
//        }
//        else
//        {
//            wordIndex = 0;
//        }
//    }
    ofPopMatrix();
    
   
    
    string frameStr = "Framerate:: " + ofToString(ofGetFrameRate());
    ofDrawBitmapStringHighlight(frameStr, 10, 10);
    
    string threshStr = "Threshold:: " + ofToString(threshold);
    ofDrawBitmapStringHighlight(threshStr, 25, 25);
    
    std::cout << phrase.size() << std::endl;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == '.' && spacingValue < 639)
    {
        spacingValue++;
    }
    else if (key == ',' && spacingValue > 1)
    {
        spacingValue--;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
