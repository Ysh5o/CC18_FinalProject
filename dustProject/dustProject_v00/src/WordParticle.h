//
//  WordParticle.h
//  DustProject_v00
//
//  Created by Yshao Lin on 11/7/18.
//

#pragma once

#include "ofMain.h"

class WordParticle {
public:
    
    // Constructor
    WordParticle();
    
    // Destructor
    //~WordParticle();
    
    // Functions
    void setup();
    void update();
    
    void draw();
    
    // variables
   
    glm::vec3 position;

    string word;
    
    ofTrueTypeFont font;
    
    int opacity;
};


