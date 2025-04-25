package ntou.cs.java2025;
import java.util.ArrayList;

public class Course {
    private final String courseName;
    private final ArrayList<Student> studentList;
    private final int maxStudents;
    
    public Course(String courseName, int maxStudents) {
        try {
        	if (courseName==null || courseName.isEmpty()) {
                throw new IllegalArgumentException("Course name cannot be null or empty");
            }
            if (maxStudents<0) {
                throw new IllegalArgumentException("Maximum students must be a positive integer");
            }
        	
        }
        catch(Exception e){
        	System.out.println(e.getMessage());
        }
        this.courseName=courseName;
        this.maxStudents=maxStudents;
        this.studentList=new ArrayList<>();
    }

    public String getCourseName() {
        return courseName;
    }

    public ArrayList<Student> getStudentList() {
        return studentList;
    }

    public int getMaxStudents() {
        return maxStudents;
    }

    public void addStudent(Student student) {
        if(studentList.size()<maxStudents) {
        	studentList.add(student);
        	System.out.printf("Student %s successfully added to course %s%n",student.getName(),getCourseName());
        }
        else {
        	System.out.printf("Cannot add student %s, course %s has reached maximum capacity%n"
        		,student.getName(),getCourseName());
        }
    }

    public void removeStudent(Student student) {
        if(!studentList.contains(student))
            System.out.printf("Student %s is not enrolled in course %s%n",student.getName(),getCourseName());
        else{
            studentList.remove(student);
            System.out.printf("Student %s successfully removed from course %s%n",student.getName(),getCourseName());
        }
    }

    @Override
    public String toString() {
        String result = "Course: " + courseName + "\n";
        result += "Maximum Students: " + maxStudents + "\n";
        result += "Students Enrolled:\n";

        for (Student student : studentList) {
            result += "- " + student.getName() + "\n";
        }

        return result;
    }
} 