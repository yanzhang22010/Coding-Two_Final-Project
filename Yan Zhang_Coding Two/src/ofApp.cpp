#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);// Set the frame rate to 60 frames per second
    ofBackground(127,150, 120);
        
    ofEnableDepthTest();// Enable depth testing for 3D drawing
    this->mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);// Set the primitive mode for the mesh to lines
    }

//--------------------------------------------------------------
void ofApp::update(){
    this->mesh.clear();
     
        for(int i = 0; i < 2; i++){
            // Add new particles to the location and direction lists
            this->location_list.push_back(glm::vec3());
            auto direction = glm::vec3(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
            direction = glm::normalize(direction) * 2;
            this->direction_list.push_back(direction);
        }
     
        for (int i = 0; i < this->location_list.size(); i++) {
     
            this->location_list[i] += this->direction_list[i];// Add a new particle location to the location list
        }
     
    for (int i = static_cast<int>(this->location_list.size()) - 1; i >= 0; i--){
            auto len = glm::length(this->location_list[i]);
            if (len > 600) {
     
                this->location_list.erase(this->location_list.begin() + i);
                this->direction_list.erase(this->direction_list.begin() + i);
            }
            this->mesh.addVertex(this->location_list[i]);
            this->mesh.addColor(ofColor(5, ofMap(len, 0, 3000, 265, 10)));
        }
        for (int i = 0; i < this->mesh.getNumVertices(); i++) {
            for (int k = i + 1; k < this->mesh.getNumVertices(); k++) {
                auto distance = glm::distance(this->mesh.getVertex(i), this->mesh.getVertex(k));
                if (distance < 50) {
                    this->mesh.addIndex(i); this->mesh.addIndex(k);
                }
            }
        }
}

//--------------------------------------------------------------
void ofApp::draw(){
         this->cam.begin();
         ofRotateDeg(ofGetFrameNum() * 3, 1, 0, 1); //rotate around X-axis
         ofRotateDeg(ofGetFrameNum() * 0.25, 0, 1, 0); //rotate around Y-axis
         this->mesh.drawVertices();
         for (int i = 0; i < this->mesh.getNumVertices(); i++) {
             // Generate a random hue in the range of warm colors
             float hue = ofRandom(5, 50);
             // Set the color of the sphere to a random warm hue, full saturation, and full brightness
             ofSetColor(ofColor::fromHsb(hue, 220, 255));
             //
             ofDrawSphere(this->mesh.getVertex(i), 10);
         }
      
         this->cam.end();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
