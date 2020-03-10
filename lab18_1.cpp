#include<iostream>
#include<cmath>

using namespace std;
struct Rect{
	double x,y,w,h;
};

double overlap(Rect , Rect );

int main(){

	float x,y,w,h;

	cout << "Please input Rect 1 (x y w h): ";
	cin>>x>>y>>w>>h;
	
	Rect rect1 = {x,y,w,h};

	cout << "Please input Rect 2 (x y w h): ";
	cin>>x>>y>>w>>h;

	Rect rect2 = {x,y,w,h};
	
	cout << "Overlap area = "<<overlap(rect1,rect2);	

	return 0;
}

double overlap(Rect rect1, Rect rect2) {
    double overlapW, overlapH;
    
    // swap X
    if (rect1.x > rect2.x) {
        double t = rect2.x;
        rect2.x = rect1.x;
        rect1.x = t;
        
        t = rect2.w;
        rect2.w = rect1.w;
        rect1.w = t;
        
        t = rect2.y;
        rect2.y = rect1.y;
        rect1.y = t;
        
        t = rect2.h;
        rect2.h = rect1.h;
        rect1.h = t;
    }
    
    if (rect1.x + rect1.w > rect2.x) {
        overlapW = rect1.x + rect1.w - rect2.x;
        
        if (overlapW > rect2.w) overlapW = rect2.w;
    }
    else return 0;
    
    if (rect1.y + rect1.h > rect2.y) {
        overlapH = rect1.y + rect1.h - rect2.y;
        
        if (overlapH > rect2.h) overlapH = rect2.h;
    }
    else return 0;

	return overlapW * overlapH;
}

