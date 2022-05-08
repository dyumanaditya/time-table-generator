import csv
import random
import string

# My imports
import students
import courses
import parameters


class RandomGenerator:        
    def generate_teacher_csv(self):
        pass

    def generate_student_csv(self, section: string) -> None:
        if section == "K1": self.students = students.k1_students
        elif section == "K2": self.students = students.k2_students
        else: self.students = students.k3_students

        self.max_courses_of_student = 0
        all_students_data = []
        # 1. Generating data for each student in a list
        for student in self.students:
            phone = self.__generate_phone()
            number_of_courses = 0
            remaining_periods = random.randint(parameters.min_periods, parameters.max_periods)
            self.courses = courses.courses.copy()
            student_data = [ student, section, student.split()[0].lower() + ".email@poop.com", phone ]
            courses_data = []

            while(remaining_periods):
                # Selecting a random course from the list
                course = self.courses[random.randint(0, len(self.courses)-1)]
                number_of_periods = 0
                if course in courses.courses_fixed_periods:
                    number_of_periods = courses.courses_fixed_periods_with_periods[course]
                else:
                    number_of_periods = random.randint(parameters.min_periods_per_subject, parameters.max_periods_per_subject)
                
                course_tuple = self.check_remaining_periods(remaining_periods, number_of_periods, course, section)
                course = course_tuple[0]
                remaining_periods = int(course_tuple[1])
                number_of_courses += 1
                courses_data.append(course)

            self.max_courses_of_student = max(self.max_courses_of_student, number_of_courses)
            student_data.append(number_of_courses)
            for c in courses_data: student_data.append(c)
            # One student's data is ready
            all_students_data.append(student_data)
        # -------------------- All students' data in a particular section is ready --------------------
        # 2. Finally, writing all the data to .csv file
        with open(section + "_" + 'students_data.csv', 'w', newline='') as f:
            writer = csv.writer(f, quotechar=',', quoting=csv.QUOTE_MINIMAL)
            # Generating the column titles
            column_titles = ["Name","Section","Email","Phone","Number of Courses"]
            for i in range(self.max_courses_of_student) :
                column_titles.append("Course_" + str(i))

            writer.writerow(column_titles)
            # Writing student data
            for student_data in all_students_data: writer.writerow(student_data)
        # 2.--------------------
    
    def check_remaining_periods(self, remaining_periods: int, number_of_periods: int, course: string, section: str) -> tuple:
        if number_of_periods > remaining_periods:
            if course in courses.courses_fixed_periods:
                return self.select_a_different_course(remaining_periods, number_of_periods, course, section)
            else:
                if remaining_periods > parameters.max_periods_per_subject:
                    number_of_periods = random.randint(parameters.min_periods_per_subject, parameters.max_periods_per_subject)
                else: number_of_periods = remaining_periods
                
                return (self.__add_number_of_periods_after_colon(self.courses.pop(self.courses.index(course)), number_of_periods), remaining_periods - number_of_periods)
        else:
            return (self.__add_number_of_periods_after_colon(self.__check_if_section_specific_course(self.courses.pop(self.courses.index(course)), section), number_of_periods), remaining_periods - number_of_periods)

    def select_a_different_course(self, remaining_periods: int, number_of_periods: int, course: string, section: str) -> tuple:
        while (number_of_periods > remaining_periods):
            # If the new course is not a one with fixed periods, 
            #     we have the flexible option of choosing the number of periods of the new course
            #     equal to the remaining periods iff the remaining number of periods is within
            #     the range of the max number of periods that a normal course can have.
            course = self.courses[random.randint(0, len(self.courses)-1)]
            if course in courses.courses_fixed_periods:
                # If the number of periods of the newly chosen course is greater 
                #     than remaining periods, then the code in the loop will rerun.
                number_of_periods = courses.courses_fixed_periods_with_periods[course]
                if remaining_periods >= number_of_periods:
                    return (self.__add_number_of_periods_after_colon(self.__check_if_section_specific_course(self.courses.pop(self.courses.index(course)), section), number_of_periods), remaining_periods - number_of_periods)
            else:
                if remaining_periods > parameters.max_periods_per_subject:
                    number_of_periods = random.randint(parameters.min_periods_per_subject, parameters.max_periods_per_subject)
                else: number_of_periods = remaining_periods
                
                return (self.__add_number_of_periods_after_colon(self.courses.pop(self.courses.index(course)), number_of_periods), remaining_periods - number_of_periods)

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