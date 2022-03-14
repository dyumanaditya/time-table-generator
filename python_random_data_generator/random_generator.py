import csv
import random_name_generator as rng
from courses import courses


class RandomGenerator:
    def __init__(self):
        self.courses = courses

    def generate_teacher_csv(self):
        with open('datafile.csv', 'w', newline='') as f:
            writer = csv.writer(f, delimiter=' ',
                                    quotechar='|', quoting=csv.QUOTE_MINIMAL)
            
            for i in self.courses :
                name = rng.generate_one(
    descent=(rng.Descent.ITALIAN, rng.Descent.ENGLISH),
    sex=rng.Sex.MALE
)
                writer.writerow([i, name])

    def generate_student_csv(self):
        pass


random_generator = RandomGenerator()
random_generator.generate_student_csv()
random_generator.generate_teacher_csv()

# print(rng.generate(descent=rng.Descent.ENGLISH, sex=rng.Sex.MALE, limit=2))