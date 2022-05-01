import csv
import random
import string
from types import NoneType

# My imports
import students
import courses
import parameters


class RandomGenerator:
    def __init__(self):
        self.courses = courses.courses

    def generate_teacher_csv(self):
        pass

    def generate_student_csv(self, section: string) -> NoneType:
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
            # Generating data for each student in a list
            for student in self.students:
                phone = self.__generate_phone()
                number_of_courses = random.randint(parameters.min_courses, parameters.max_courses)
                remaining_periods = parameters.max_periods
                student_data = [ student, section, student.split()[0].lower() + ".email@poop.com", phone, number_of_courses ]

                for i in range(number_of_courses + 1):
                    if not remaining_periods: break
                    # Selecting a random course from the list
                    course = courses.courses[random.randint(0, len(courses.courses)-1)]
                    course = self.__check_if_section_specific_course(course, section)                            

                    number_of_periods = 0
                    if course.split("_")[0] in courses.courses_fixed_periods:
                        number_of_periods = courses.courses_fixed_periods_with_periods[course.split("_")[0]]
                    else:
                        number_of_periods = random.randint(parameters.min_periods_per_subject, parameters.max_periods_per_subject)
                    
                    course_tuple = self.check_remaining_periods(remaining_periods, number_of_periods, course)
                    course = course_tuple[0]
                    remaining_periods = int(course_tuple[1])
                    # --------------------
                    
                    student_data.append(course)
                
                writer.writerow(student_data)
    
    def check_remaining_periods(self, remaining_periods: int, number_of_periods: int, course: string) -> tuple:
        if number_of_periods > remaining_periods:
            return self.select_course(remaining_periods, number_of_periods, course)
        else:
            return (self.__add_number_of_periods_after_colon(course, number_of_periods), remaining_periods - number_of_periods)

    def select_course(self, remaining_periods: int, number_of_periods: int, course: string) -> tuple:
        if number_of_periods > remaining_periods:
            if course in courses.courses_fixed_periods:
                while (number_of_periods > remaining_periods):
                    course = courses.courses[random.randint(0, len(courses.courses)-1)]
                    if course in courses.courses_fixed_periods:
                        number_of_periods = courses.courses_fixed_periods_with_periods[course]
                        if remaining_periods >= number_of_periods:
                            remaining_periods -= number_of_periods
                            return (self.__add_number_of_periods_after_colon(self.__check_if_section_specific_course(course), number_of_periods), remaining_periods)
                    else:
                        while (number_of_periods > remaining_periods):
                            number_of_periods = random.randint(parameters.min_periods_per_subject, parameters.max_periods_per_subject)
                        
                        remaining_periods -= number_of_periods
                        return (self.__add_number_of_periods_after_colon(course, number_of_periods), remaining_periods)
            else:
                remaining_periods -= number_of_periods
                return (self.__add_number_of_periods_after_colon(course, number_of_periods), remaining_periods)
        else:
            remaining_periods -= number_of_periods
            return (course, remaining_periods)

    def __generate_phone(self) -> str:
        # Adding the first number (1-9) so that 0 is NOT the first number,
        #  so that the number appears to be 10 digit, and NOT 9 digit.
        _phone = str(random.randint(1,9))
        for i in range(0,9):
            _phone += str(random.randint(0, 9))
        return _phone

    def __check_if_section_specific_course(self, _course: str, section: str) -> str:
        # Adding the section name as a suffix to some specific courses
        if _course in courses.section_specific_course: return _course + "_" + section.lower()
        else: return _course

    def __add_number_of_periods_after_colon(self, _course: str, _number_of_periods: int) -> str:
        return _course + ";" + str(_number_of_periods)


random_generator = RandomGenerator()
random_generator.generate_student_csv("K1")
random_generator.generate_student_csv("K2")
random_generator.generate_student_csv("K3")