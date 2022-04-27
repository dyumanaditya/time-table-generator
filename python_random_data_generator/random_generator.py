import csv
import random
import string

# my imports
import students
import courses
import parameters


class RandomGenerator:
    def __init__(self):
        self.courses = courses.courses

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
                remaining_periods = parameters.max_periods

                for i in range(0,9):
                    phone += str(random.randint(0, 9))

                student_data = [
                        student, section, student.split()[0].lower() + ".email@poop.com", phone, number_of_courses
                    ]

                for i in range(number_of_courses + 1):
                    if not remaining_periods: break
                    # Selecting a random course from the list
                    course = courses.courses[random.randint(0, len(courses.courses)-1)]

                    # Adding the section name as a suffix to some specific courses
                    if course in courses.section_specific_course:
                        for c in range(0, len(courses.section_specific_course)):
                            pass
                        course = course + "_" + section.lower()                            

                    for c in range(0, len(courses.courses_fixed_periods)):
                        if course.split("_")[0] in courses.courses_fixed_periods:
                            course_tuple = self.check_remaining_periods(remaining_periods, courses.courses_fixed_periods_with_periods[course.split("_")[0]], course)
                            course = course_tuple[0]
                            print(type(course_tuple[1]), course_tuple[1])
                            remaining_periods = int(course_tuple[1])
                            # print(course_tuple[1])
                        else:
                            number_of_periods = random.randint(parameters.min_periods_per_subject, parameters.max_periods_per_subject)
                            course_tuple = self.check_remaining_periods(remaining_periods, number_of_periods, course)
                            course = course_tuple[0]
                            # remaining_periods -= int(course.split(";")[1])
                            print(type(course_tuple[1]), course_tuple[1])
                            remaining_periods = int(course_tuple[1])
                            # print(course_tuple[1])
                    # --------------------
                    
                    student_data.append(course)
                
                # writer.writerow(student_data)
    
    def check_remaining_periods(self, remaining_periods, number_of_periods, course):
        # print(type(remaining_periods), remaining_periods)
        if number_of_periods > remaining_periods:
            return self.select_course(remaining_periods, number_of_periods, course)
        else:
            return course + ";" + str(number_of_periods)

    def select_course(self, remaining_periods, number_of_periods, course):
        if number_of_periods > remaining_periods:
            course = courses.courses[random.randint(0, len(courses.courses)-1)]
            
            if course in courses.courses_fixed_periods:
                number_of_periods = courses.courses_fixed_periods_with_periods[course]
                while (number_of_periods > remaining_periods):
                    course = courses.courses[random.randint(0, len(courses.courses)-1)]
                    if course in courses.courses_fixed_periods: 
                        if remaining_periods > courses.courses_fixed_periods_with_periods[course]:
                            remaining_periods -= courses.courses_fixed_periods_with_periods[course]
                            print(remaining_periods)
                            return (course, remaining_periods)
                    else:
                        number_of_periods = random.randint(parameters.min_periods_per_subject, parameters.max_periods_per_subject)
                        if number_of_periods <= number_of_periods: 
                            remaining_periods -= number_of_periods
                            print(remaining_periods)
                            return (course, remaining_periods)
                        elif remaining_periods > 0: 
                            remaining_periods -= number_of_periods
                            print(remaining_periods)
                            return (course, remaining_periods)

            remaining_periods -= number_of_periods
            print(remaining_periods)
            return (course, remaining_periods)

        else:
            remaining_periods -= number_of_periods
            print(remaining_periods)
            return (course, remaining_periods)


random_generator = RandomGenerator()
random_generator.generate_student_csv("K1")
random_generator.generate_student_csv("K2")
random_generator.generate_student_csv("K3")