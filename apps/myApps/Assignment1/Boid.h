#pragma once
#include "ofMain.h"

struct RigidBody
{
public:

	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;

	void applyForce(ofVec2f steering) { acceleration += steering; }
};


class Boid
{
public:
	Boid();

	const float DRAW_RADIUS = 10;
	RigidBody boidRBD;
	ofVec2f targetPos;

	ofColor color;
	float maxSpeed;
	float wanderAngle;

public:
	void seek(ofVec2f targetLocation);
	void arrive(ofVec2f targetLocation, float slowRadius);
	void wander();

	void update();
	void draw();
	float randomBinomial() { return ofRandom(1) - ofRandom(1); }
	void KinematicMotion();

	bool bKineMatic, bSeek, bArrive, bWander;
	
};