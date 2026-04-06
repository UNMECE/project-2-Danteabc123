#include<iostream>
#include<vector>
#include<string>
#include<fstream>


class Student //This is the Base class
{
 	protected:
		std::string first_name;
		std::string last_name;
		double gpa;
		int graduation_year;
		std::string graduation_semester;
		int enrolled_year;
		std::string enrolled_semester;
		std::string undergrad_grad;
	public:
		Student() //This is the default constructor
		{
			first_name = "John";
			last_name = "Doe";
			gpa = 0.0;
			graduation_semester = "N/A";
			enrolled_year = 0;
			enrolled_semester = "N/A";
			undergrad_grad = "N/A";
		}
		~Student() {}//This is the destructor
	void setfirstName(std::string first)
	{
		first_name = first;
	}
	void setlastName(std::string last)
	{
		last_name = last;
	}
	void setGPA(double g)
	{
		gpa = g;
	}
	void setGraduationYear(int gy)
	{
		graduation_year = gy;
	}
	void setGraduationSemester(std::string gs)
	{
		graduation_semester = gs;
	}
	void setEnrolledYear(int ey)
	{
		enrolled_year = ey;
	}
	void setEnrolledSemester(std::string es)
	{
		enrolled_semester = es;
	}
	void setUnderGrad(std::string ug)
	{
		undergrad_grad = ug;
	}

	void print(std::ostream out)
	{
//		out <<"Student Name: " << first_name , " " << last_name << endl;
	}
};

class Art_Student : public Student //This is the first derived Class of Student
{
	private:
		std::string art_emphasis;
	public:
		Art_Student()
		{
			art_emphasis = "Art Education";
		}
};

class Physics_Student : public Student //This is the seoconded derived class of Student
{
	private:
		std::string concentration1;
		std::string concentration2;
	public:
		Physics_Student()
		{
			concentration1 = "Biophysics";
			concentration2 = "Earth and Planetary Sciences";
		}
};

int main() //This is the main function of the program :)
{
	std::vector<Art_Student *> art_student;
	std::vector<Physics_Student*> physics_student;
	std::ofstream outfile;

	art_student.push_back(new Art_Student());
	art_student[0] -> setfirstName("Dante");
	art_student[0] -> setGPA(3.0);
	art_student[0] -> setGraduationYear(2027);
	art_student[0] -> setGraduationSemester("Spring Semester");
	art_student[0] -> setEnrolledYear(2022);
	art_student[0] -> setEnrolledSemester("Fall Semester");
	art_student[0] -> setUnderGrad("Undergraduate");
	
	outfile.open("student_info.dat", std::ios::out);
	//art_student.print(outfile);

	outfile.close();
	return 0;
}
