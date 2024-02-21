#include "Boid.h"

Boid::Boid()
{
	boidRBD.location.x = 0;
	boidRBD.location.y = ofGetHeight();
	boidRBD.velocity.x = 0;
	boidRBD.velocity.y = 0;
	maxSpeed = 5.0f;

	bSeek = bArrive = bWander = false;
	bKineMatic = true;
	boidRBD.velocity.set(2, 0);
}

void Boid::draw()
{

	ofPushMatrix();	                                 // Save the global coordinates

	ofTranslate(boidRBD.location.x, boidRBD.location.y);             // Translate coords to the boid's position

	if (bWander)
	{
		ofRotateZDeg(atan2(boidRBD.velocity.y, boidRBD.velocity.x) * 180 / PI * wanderAngle);
	}
	ofRotateZDeg(atan2(boidRBD.velocity.y, boidRBD.velocity.x) * 180 / PI);

	ofSetColor(ofColor::black);                      // Stroke is black
	ofDrawCircle(0, 0, DRAW_RADIUS);					
	ofSetColor(color);                               // Fill is this->color
	ofDrawCircle(0, 0, DRAW_RADIUS);                 // Draw the "body" fill
	ofDrawTriangle(0, DRAW_RADIUS + 1, 0, -DRAW_RADIUS - 1, 2.5*DRAW_RADIUS, 0);
	ofSetColor(ofColor::white);
	ofPopMatrix();                                   // Pop the saved global coordinates
}

void Boid::KinematicMotion()
{
	if (boidRBD.location.x >= ofGetWidth() && boidRBD.location.y >= ofGetHeight()) //move upwards
	{
		boidRBD.location.x = ofGetWidth();
		boidRBD.location.y = ofGetHeight();
		boidRBD.velocity.set(0, -2);
	}
	else if (boidRBD.location.x >= ofGetWidth() && boidRBD.location.y <= 0) //move left
	{
		boidRBD.location.x = ofGetWidth();
		boidRBD.location.y = 0;
		boidRBD.velocity.set(-2, 0);
	}
	else if (boidRBD.location.x <= 0 && boidRBD.location.y <= 0) //move down
	{
		boidRBD.location.x = 0;
		boidRBD.location.y = 0;
		boidRBD.velocity.set(0, 2);
	}
}

void Boid::seek(ofVec2f targetLocation)
{
	ofVec2f result;

	result = targetLocation - boidRBD.location;
	if (result.lengthSquared() > 0)
		result.normalize();

	result *= 2;

	boidRBD.velocity = result;
}

void Boid::arrive(ofVec2f targetLocation, float slowRadius)
{
	ofVec2f desiredVelocity = targetLocation - boidRBD.location;
	float distance = desiredVelocity.length();

	desiredVelocity.normalize();

	if (distance < slowRadius)
		desiredVelocity *= maxSpeed * (distance / slowRadius);
	else
		desiredVelocity *= maxSpeed;

	ofVec2f steering = desiredVelocity - boidRBD.velocity;
	boidRBD.velocity += steering;
}

void Boid::wander()
{
	wanderAngle = randomBinomial() * 45.0;
}

void Boid::update()
{	
	if (boidRBD.location.x >= ofGetWidth())
		boidRBD.location.x -= ofGetWidth();
	else if (boidRBD.location.y >= ofGetHeight())
		boidRBD.location.y -= ofGetHeight();


	//if (bSeek)
	//{
	//	seek(targetPos);
	//}
	if (bArrive)
	{
		arrive(targetPos, 50.0);
	}
	else if (bWander)
	{
		wander();
	}
	else
	{
		KinematicMotion();
	}
	boidRBD.location += boidRBD.velocity;
}