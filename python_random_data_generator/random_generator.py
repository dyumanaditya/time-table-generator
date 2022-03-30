import csv
import random

# my imports
from students import k3_students
from courses import courses
import parameters


class RandomGenerator:
    def __init__(self):
        self.courses = courses
        self.k3_students = k3_students

    def generate_teacher_csv(self):
        pass

    def generate_student_csv(self):
        with open('datafile.csv', 'w', newline='') as f:
            writer = csv.writer(f, quotechar=',', quoting=csv.QUOTE_MINIMAL)
            
            # Generating the column titles
            column_titles = ["Name","Section","Email","Phone","Number of Courses"]
            for i in range(parameters.max_courses + 1) :
                column_titles.append("Course_" + str(i))

            writer.writerow(column_titles)
            # -----------------

            for student in self.k3_students:

                # adding the first number (1-9) so that 0 is not the first number,
                #  then all the ten numbers will appear when you preview the CSV file
                phone = str(random.randint(1,9))
                number_of_courses = random.randint(parameters.min_courses, parameters.max_courses)
                for i in range(0,9):
                    phone += str(random.randint(0, 9))

                student_data = [
                        student, "K3", student.split()[0].lower() + ".email@poop.com", phone, number_of_courses
                    ]

                for i in range(number_of_courses + 1):
                    student_data.append(courses[random.randint(0, len(courses)-1)])
                
                writer.writerow(student_data)


random_generator = RandomGenerator()
random_generator.generate_student_csv()