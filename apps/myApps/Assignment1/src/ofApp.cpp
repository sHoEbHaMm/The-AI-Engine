#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

	boid.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	boid.draw();
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

	if (button == 0)
	{
		boid.targetPos.x = x;
		boid.targetPos.y = y;
		boid.bSeek = true;
		boid.bArrive = false;
		boid.bWander = false;
		boid.bKineMatic = false;
		boid.seek(boid.targetPos);
	}
	else if (button == 2)
	{
		boid.targetPos.x = x;
		boid.targetPos.y = y;
		boid.bArrive = true;
		boid.bWander = false;
		boid.bKineMatic = false;
		boid.bSeek = false;
	}
	else if (button == 1)
	{
		boid.bWander = true;
		boid.bSeek = false;
		boid.bArrive = false;
		boid.bKineMatic = false;
	}

	else
	{
		boid.bKineMatic = true;
		boid.bArrive = false;
		boid.bWander = false;
		boid.bSeek = false;
	}


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
