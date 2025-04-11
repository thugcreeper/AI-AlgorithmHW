package ntou.cs.java2025;
import java.util.ArrayList;

public class CourseManager {
    private static final ArrayList<Course> courses = new ArrayList<>();

    public static void addCourse(Course course) {
        courses.add(course);
    }

    public static Course findCourse(String courseName) {
        int i=0;
        for(i=0;i<courses.size();i++) {
        	if(courseName==courses.get(i).getCourseName()) {//found target course
        		return courses.get(i);
        		//System.out.println(courses.toString());
        	}
        }
        return null;
    }

    public static void printAllCoursesInfo() {
        System.out.println("\nCourses Information:");
        for (Course course : courses) {
            System.out.println(course.toString());
        }
    }
}
