#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct student{
	string name;	
	int id;
	char gender;
	float gpa;
};

struct course{
	string name;
	int id;
	vector<string> lecture_list;
	vector<student *> student_list;
};

student * findstudent(vector<student> &allstudents,int key){ //Correct this line
	for(unsigned int i = 0; i < allstudents.size(); i++){
		if(allstudents[i].id  == key) return &allstudents[i];
	}
}

void printreport(vector<course> allcourses){
	for(unsigned int i = 0;i < allcourses.size(); i++){
		cout << "-----------------------------------------------------------------------------\n";
		cout << "Course:\t\t" << allcourses[i].name << " ("<< allcourses[i].id << ")\n\n";
		cout << "Lecturers:\t";
		for(unsigned int j = 0; j < allcourses[i].lecture_list.size();j++){
			if(j != 0) cout << ", ";
			cout << allcourses[i].lecture_list[j];
		} 
		cout << "\n\nStudents:\t";
		for(unsigned int j = 0; j < allcourses[i].student_list.size();j++){
			if(j != 0) cout << "\t\t";
			cout << setw(15) << left << allcourses[i].student_list[j]->name << "\t";
			cout << allcourses[i].student_list[j]->id << "\t";
			cout << allcourses[i].student_list[j]->gender << "\t";
			cout << allcourses[i].student_list[j]->gpa << "\n";
		} 
		
	}
	cout << "-----------------------------------------------------------------------------\n";
}

int main(){

	ifstream student_file("C:\\Users\\acer\\Documents\\GitHub\\lab18-2562-2-arclxngth\\students.txt");
	ifstream course_file("C:\\Users\\acer\\Documents\\GitHub\\lab18-2562-2-arclxngth\\courses.txt");
	vector<student> allstudents;
	vector<course> allcourses;
	
	string textline;
	
	while(getline(student_file,textline)){

		char name[100];
		char gender;
		float gpa;
		int id;

		sscanf(textline.c_str(),"%[^,],%d,%c,%f",name,&id,&gender,&gpa);

		student s = {name,id,gender,gpa};
	
		allstudents.push_back(s); 		
	}

	int state = 1;
	course c;

	while(getline(course_file,textline)){
		if(state == 1){
			int loc = textline.find_first_of('(');
			c.name = textline.substr(0,loc-1);
			c.id = atof(textline.substr(loc+1,5).c_str());
			getline(course_file,textline);
			state = 2;			
		}else if(state == 2){
			if(textline == "> Students"){
				state = 3;
			}else{
				c.lecture_list.push_back(textline);
			}			
		}else{
			if(textline == "---------------------------------------"){
				state = 1;
				allcourses.push_back(c);
				c.lecture_list = {};
			}else{
				student *p = findstudent(allstudents,atoi(textline.c_str()));
				c.student_list.push_back(p);
			}
		}
	}
	printreport(allcourses);
	
}
