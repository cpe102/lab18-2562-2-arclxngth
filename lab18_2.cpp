#include<iostream>
#include<cmath>

using namespace std;
struct Rect{
	double x,y,w,h;
};

double overlap(Rect *, Rect *);

int main(){

	float x,y,w,h;

	cout << "Please input Rect 1 (x y w h): ";
	cin>>x>>y>>w>>h;
	
	Rect r1 = {x,y,w,h};

	cout << "Please input Rect 2 (x y w h): ";
	cin>>x>>y>>w>>h;

	Rect r2 = {x,y,w,h};
	
	cout << "Overlap area = "<<overlap(&r1,&r2);	

	return 0;
}

double overlap(Rect *r1, Rect *r2){

	float x_min, y_min, x_diff, y_diff, w_max, h_max;

	x_diff = abs(r1->x-r2->x);
	y_diff = abs(r1->y-r2->y);

	if(r1->w>r2->w)	w_max = r1->w;
	else			w_max = r2->w;

	if(r1->h>r1->h)	h_max = r1->h;
	else 			h_max = r2->h;

	if(r1->x<r2->x){
		x_min=r1->x+r1->w;
		y_min=r1->y+r1->h;

		if(x_min < r2->x)	return 0;
		else if(y_min < r2->y)	return 0;
		else if(x_min > r2->x+r2->w && y_min > r2->y+r2->h)	return abs(r2->w*r2->h);
		else return abs((w_max-x_diff)*(h_max-y_diff));
	}
	else if(r1->x>r2->x){
		x_min = r2->x+r2->w;
		y_min = r2->y+r2->h;

		if(x_min < r1->x)	return 0;
		else if(y_min < r1->y)	return 0;
		else if(x_min > r1->x+r1->w && y_min > r1->y+r1->h)	return abs(r1->w*r1->h);
		else return abs((w_max-x_diff)*(h_max-y_diff));
	}
}

