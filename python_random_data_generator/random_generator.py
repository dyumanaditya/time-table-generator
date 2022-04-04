import csv
import random
import string

# my imports
import students
from courses import courses
import parameters


class RandomGenerator:
    def __init__(self):
        self.courses = courses

    def generate_teacher_csv(self):
        pass

    def generate_student_csv(self, section:string):
        if section == "K1": self.students = students.k1_students
        elif section == "K2": self.students = students.k2_students
        else: self.students = students.k3_students

        with open(section + "_" + 'students_data.csv', 'w', newline='') as f:
            writer = csv.writer(f, quotechar=',', quoting=csv.QUOTE_MINIMAL)
            
            # Generating the column titles
            column_titles = ["Name","Section","Email","Phone","Number of Courses"]
            for i in range(parameters.max_courses + 1) :
                column_titles.append("Course_" + str(i))

            writer.writerow(column_titles)
            # -----------------

            for student in self.students:

                # adding the first number (1-9) so that 0 is not the first number,
                #  then all the ten numbers will appear when you preview the CSV file
                phone = str(random.randint(1,9))
                number_of_courses = random.randint(parameters.min_courses, parameters.max_courses)
                max_periods = parameters.max_periods

                for i in range(0,9):
                    phone += str(random.randint(0, 9))

                student_data = [
                        student, section, student.split()[0].lower() + ".email@poop.com", phone, number_of_courses
                    ]

                for i in range(number_of_courses + 1):
                    # Selecting a random course from the list
                    course = courses[random.randint(0, len(courses)-1)]

                    # Adding the section name as a suffix to some specific courses
                    if course == "Mathematics" or course == "Physics" or \
                       course == "Chemistry" or course == "Biology":
                        course = course + "_" + section.lower()                            

                    # Adding number of periods to courses which need fixed number of periods
                    if course.split("_")[0] == "Mathematics":
                        course = course + ";" + str(parameters.Math)
                    elif course.split("_")[0] == "Physics":
                        course = course + ";" + str(parameters.Physics)
                    elif course.split("_")[0] == "Chemistry":
                        course = course + ";" + str(parameters.Chemistry)
                    elif course.split("_")[0] == "Biology":
                        course = course + ";" + str(parameters.Biology)
                    elif course == "Mathematical_Statistics":
                        course = course + ";" + str(parameters.Mathematical_Statistics)
                    elif course == "Elementary_Statistics":
                        course = course + ";" + str(parameters.Elementary_Statistics)
                    elif course == "Linear_Algebra":
                        course = course + ";" + str(parameters.Linear_Algebra)
                    elif course == "Numerical_Analysis":
                        course = course + ";" + str(parameters.Numerical_Analysis)
                    elif course == "Computer_Applications":
                        course = course + ";" + str(parameters.Computer_applications)
                    elif course == "Computer_Programming_In_CPP":
                        course = course + ";" + str(parameters.Computer_programming)
                    elif course == "Solar_Science":
                        course = course + ";" + str(parameters.Solar_Science)
                    # --------------------
                    
                    student_data.append(course)
                
                writer.writerow(student_data)
    
    def check_remaining_periods(self, remaining_periods):
        num_of_periods = random.randint(parameters.min_periods_per_subject, parameters.max_periods_per_subject)

        if (remaining_periods < num_of_periods) :
            pass



random_generator = RandomGenerator()
random_generator.generate_student_csv("K1")
random_generator.generate_student_csv("K2")
random_generator.generate_student_csv("K3")