//
//  WordParticle.cpp
//  DustProject_v00
//
//  Created by Yshao Lin on 11/7/18.
//

#include "WordParticle.h"


// Constructor
WordParticle::WordParticle()
{
    position = {ofGetWidth()/2, ofGetHeight()/2, 0};
}


void WordParticle::update()
{
    //number means the spead of fading away. each second 60 frames. RGB(255-1)=254/60=4
    opacity-=5;
    
    
    // THESE ARE ALL THE SAME THING, just different syntax.
//    opacity--;
//    opacity-=1;
//    opacity = opacity - 1;
}


// fade away
// exist in a certain position
// write out a complete sentence



