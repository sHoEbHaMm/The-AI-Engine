# EAE6610: Assignment1-MovementAI

## Instructions
Your task for this assignment is to explore various movement algorithms. Using [openFrameworks](https://openframeworks.cc), you will implement various Dynamic Movement algorithms and be able to appreciate their performance. You will submit your code via [our Github Classroom portal](https://classroom.github.com/classrooms/156158200-sp24-classroom) by ensuring that your code is **pushed to your repository by the assignment deadline**. You will also hand in a 1 to 2-page [process letter](#About-Ungrading-and-Process-Letters) placed in the top-level directory of your git repository.

This is an individual assignment; you are to work alone. As always, you are expected to abide by the University of Utah Code of Conduct, explicitly outlined in the class syllabus, which includes providing appropriate attribution for all external sources of information consulted while working on this assignment.

### Overview
1. [Setup](#Setup)
2. [Assignment Deliverables](#assignment-deliverables)
    1. [First Steps](#first-steps)
    2. [Kinematic Motion](#kinematic-motion)
    3. [Dynamic Steering Behaviours](#dynamic-steering-behaviours)
    4. [Wander Steering Behaviours](#wander-steering-behaviours)
    5. [Flocking Behavior and Blending](#flocking-behavior-and-blending)
    6. [Process Letter](#process-letter)

### Setup
Before you are able to get started with the assignment, go to [SETUP.md](SETUP.md) and configure your working environment. Once you have done that, return to this file.

### Assignment Deliverables

#### First Steps
You should begin by familiarizing yourself with [openFrameworks](http://openframeworks.cc). openFrameworks is "an open source C++ toolkit designed to assist the creative process by providing a simple and intuitive framework for experimentation."

For your first steps, draw a circle and triangle to the screen to make the shape depicted below.
Make sure your shape is sufficiently small relative to the canvas size so that when you begin moving it around the screen it has a place to go.

![Screenshot of a Boid: a black circle with a black triangle overlain, where one of the triangle's tips points to the east.](/README/boid.png)

A Boid.

#### Kinematic Motion
Create a Rigidbody data structure like the one we discussed in class.  Make sure you include methods for getting the new orientation from direction and for updating position. Make sure to leave breadcrumbs as your shape traverses the screen.

Using kinematic motion (i.e., velocity-based movement), have your shape start at the bottom left corner of the screen and traverse around the edge until it returns to its starting location. 

> [!TIP]
> If it would help, you could include a screenshot of your shape and the breadcrumbs after it completes its tour for inclusion in your [process letter](#process-letter).

#### Dynamic Steering Behaviours 
First, implement the Dynamic Seek algorithm we covered in class. Have your shape seek the location of mouse clicks. Make sure your shape is oriented in the direction of travel. Recall that you can accomplish this by implementing an orientation matching steering behavior. 

> [!TIP]
> You can implement mouse clicks by using openFramework’s [`mousePressed(...)`](https://openframeworks.cc/documentation/application/ofBaseApp/#show_mousePressed) method.

Next, test out at least two different methods for implementing arriving. 

> [!TIP]
> Things you may want to ask yourself as you draft your process letter: which arrival method looks better? why? which is more successful? why? (and again, if it would help, it is probably a good idea to take a series of screenshots to illustrate your results).

#### Wander Steering Behaviours  
First, implement the wander algorithm we covered in class. Make sure your shape is oriented in the direction of travel and to handle window boundary violations gracefully.  

> [!TIP]
> While there are many ways to handle boundary violations, one way to do it is implementing a "toroidal" map (a 2D wrap around the world).

Next, implement at least two different methods for changing orientation. 

> [!TIP]
> Things you may want to ask yourself as you draft your process letter: which method for changing wandering orientation looks better? why? (and again, if it would help, it is probably a good idea to take a series of screenshots to illustrate your results.

#### Flocking Behavior and Blending
Using multiple independent shapes, implement flocking behavior. Elect one of your shapes as a leader and have them wander the screen. 

> [!WARNING]
> You must make clear which Boid is the leader. For example, you might draw it in a different color or change its shape.

Let every other shape seek the leader, avoid collisions, and seek the center-of-mass of the flock (or some subset). You may additionally implement other steering behaviors of your choosing, or invent your own. 

> [!TIP]
> Things you may want to ask yourself as you draft your process letter: what did you observe during implementation? did you have to make any changes to the algorithms to make flocking work? Did you experiment with more or fewer followers? Are things easier or harder with more followers? What happens if you have two wanderers and followers follow the closest wanderer? (and again, if it would help, it is probably a good idea to take a series of screenshots to illustrate your results.

#### Process Letter
Now that you have implemented and evaluated a number of algorithms, be sure to draft a process letter to talk about your implementation and learning process throughout development. We strongly recommend that you do not limit yourself to only answering those questions posed in this assignment. Think creatively about what you have done. What other parameters can you tweak and what effect do they have on the results? 

> [!TIP]
> The most successful write-ups will contain evidence that you have thought deeply about these algorithms and have gone beyond what is written in the assignment: comment not on what you have done, instead comment on what you have learned and how you have learned it!

Place a PDF of your letter in the assignment folder within `apps/myApps/`. That is, if your assignment folder is called `gameAI`, then place your letter at `apps/myApps/gameAI/letter.pdf`


##### About Ungrading and Process Letters
This class is [ungraded](https://www.jessestommel.com/ungrading-an-faq/).

Classes that use the ungrading technique ask students to write about their learning process *as it happens*, and instructors offer feedback focused on meeting course learning goals. Your learning journey is unique to you, and un-grading allows us as a class to decouple grades from what ultimately matters in this class: that you actually *learn*.

A process letter is a letter you will write to the teaching staff where you will reflect on your own progress and learning as it has happened for the respective assignment. 

To help you draft one, imagine someone is creating a documentary of you as you complete the tasks in this assignment. Now, imagine that you're looking at this documentary of yourself and you have to answer the following questions:
- what would you say about yourself? 
- what would you say that you knew at the end that you didn't know at the beginning?
- would you say that you had fun?
- did you find the assignment challenging?
- did you find the assingment useful? not useful? and for either one: why?
- have you become curious about anything new?
- did you feel what you did was related to the class content?
- do you think what you did is relevant to your class project?
- what have you not done yet that you have seen in other games?

##### Formatting for your Process Letter
Your letter should be 1-2 pages long (2 pages max), formatted as a PDF. You are not required to adhere to any style. To make it a bit easier on drafting, the screenshots you include in your letter do not count toward your 2 page limit.

If you would still like a suggested style, here is a (completely optional) style you could follow: 1-inch margins, 12-point Times New Roman or Arial font, 1.15inch spacing. 

## Rubric
> [!IMPORTANT]
> As mentioned in the class syllabus, this class is entirely based on the process letters. However, to help you get a sense of your own mastery within the assignment, all assignments will be *virtually* graded according to a rubric. Your virtual grade has **nothing** to do with your official standing or grade in the course; it is simply a reflection of your proficiency within this assignment, and you should use it to calibrate how close you are to meeting the learning objectives of this course, which is what we truly care about.

### Kinematic Motion (1 Point).
- (0.25) Rigidbody data structure created.
- (0.25) Leaves breadcrumbs as the shape traverses the screen.
- (0.50) Moves in a circuit path around the screen. 

### Dynamic Steering Behaviors (3 Points).
- (1) Seek algorithm created.
- (0.5) Shape seeks location of mouse clicks. 
- (1) Shape is oriented in the direction of travel. 
- (0.5) Two methods of arriving are implemented.

### Wander Steering Behaviors (4 Points).
- (1) Wander algorithm created.
- (1) Boundary violations are handled gracefully (e.g., Toroidal world implemented). 
- (1) Shape is oriented in the direction of travel.
- (1) Two methods for changing orientation.

### Flocking Behavior and Blending (7 Points).
- (0.5) Leader Boid is distinguished. 
- (0.5) Leader Boid wanders correctly. 
- (2) Flock is cohesive.
- (2) Flock follows center of mass. 
- (2) Flock “looks good.”

### Process Letter (10 Points)
- (0.5) Dynamic Steering Behavior questions posed in the assignment are answered.
- (0.5) Dynamic Steering Behavior is illustrated with screenshots.
- (2) Dynamic Steering Behavior discussion contains metacognitive reflection (beyond what the assignment asks).
- (0.5) Wander Steering Behavior questions posed in the assignment are answered.
- (0.5) Wander Steering Behavior is illustrated with screenshots.
- (2) Wander Steering Behavior discussion contains metacognitive reflection (beyond what the assignment asks).
- (1) Flocking and Blending questions posed in the assignment are answered.
- (1) Flocking and Blending is illustrated with screenshots.
- (2) Flocking and Blending discussion contains metacognitive reflection (beyond what the assignment asks).

#### Multipliers
- Does Not Compile / Build: (×0) multiplier
- Contains style/polish comparable to [openFrameworks examples](https://openframeworks.cc/examples/): (x1.5) multipler
