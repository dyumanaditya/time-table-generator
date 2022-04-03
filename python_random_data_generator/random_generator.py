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
                for i in range(0,9):
                    phone += str(random.randint(0, 9))

                student_data = [
                        student, section, student.split()[0].lower() + ".email@poop.com", phone, number_of_courses
                    ]

                for i in range(number_of_courses + 1):
                    course = courses[random.randint(0, len(courses)-1)]

                    if course == "Mathematics" or course == "Physics" or \
                       course == "Chemistry" or course == "Biology":
                        course = course + "_" + section.lower()
                    
                    student_data.append(course)
                
                writer.writerow(student_data)


random_generator = RandomGenerator()
random_generator.generate_student_csv("K1")
random_generator.generate_student_csv("K2")
random_generator.generate_student_csv("K3")