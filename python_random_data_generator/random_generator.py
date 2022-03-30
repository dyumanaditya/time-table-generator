import csv
import random
# import random_name_generator as rng
from students import k3_students
from courses import courses


class RandomGenerator:
    def __init__(self):
        self.courses = courses
        self.k3_students = k3_students

#     def generate_teacher_csv(self):
#         with open('datafile.csv', 'w', newline='') as f:
#             writer = csv.writer(f, delimiter=' ',
#                                     quotechar='|', quoting=csv.QUOTE_MINIMAL)
            
#             for i in self.courses :
#                 name = rng.generate_one(
#     descent=(rng.Descent.ITALIAN, rng.Descent.ENGLISH),
#     sex=rng.Sex.MALE
# )
#                 writer.writerow([i, name])

    def generate_teacher_csv(self):
        pass

    def generate_student_csv(self):
        with open('datafile.csv', 'w', newline='') as f:
            writer = csv.writer(f, 
                                quotechar=',', quoting=csv.QUOTE_MINIMAL)

            writer.writerow(["Name","Section","Email","Phone","Number of Courses","Course_1","Course_2","Course_3","Course_4","Course_5","Course_6","Course_7"])
            
            for student in self.k3_students:
                writer.writerow([student, "K3", student.split()[0].lower() + ".email@poop.com"])


random_generator = RandomGenerator()
random_generator.generate_student_csv()
random_generator.generate_teacher_csv()

# print(rng.generate(descent=rng.Descent.ENGLISH, sex=rng.Sex.MALE, limit=2))