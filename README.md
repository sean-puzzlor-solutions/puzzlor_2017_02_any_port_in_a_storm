# README #

This is a Repository for a solution for the [February 2017 PuzzlOR : Any Port In A Storm](http://www.puzzlor.com/2017-02_PortInAStorm.html)

### Any Port In A Storm ###

There is significant danger to boats caught out in the open sea during a storm.  Ideally, boats will dock before the storm hits and wait it out. 

The map above shows 20 orange boats out at sea.  With a storm approaching, each boat needs to be directed to one of three docks.  Docks have a limited number of spaces available for boats (indicated by the rectangular spaces).  Altogether, there are 20 boat spaces available.  The boats are clustered into three areas and each area varies in distance to the docks (as indicated by the black arrows).  All boats must be assigned to one space in a dock.

![Image](http://www.puzzlor.com/images/portinastorm_JTv1.png)

**Question:  What is the minimum possible total distance traveled by all boats?**

### Solution ###

The solution is 31.  

#### Formulation ####

c be the cluster of boats c\in C=\left\{A,\ B,\ C\right\}
d be the dock d\in D
\delta_{cd} is the distance from cluster c to dock d
x_{cd} is the number of boats sent from cluster c to dock d
n_c is the number of boats in cluster c
q_d\ is the number of quays in dock d


\min{\left[\sum_{c\in C}\sum_{d\in D}{d_{cd}x_{cd}}\right]} 
\sum_{d\in D} x_{cd}=n_c
\sum_{c\in C} x_{cd}=q_d
x_{cd}\in\mathbb{Z}^+


### Notes ###

* 2017-09-06 : Added solution using Excel's built-in-solver
