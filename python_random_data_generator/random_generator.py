import csv
import courses


class RandomGenerator:
    def __init__(self):
        self.courses = courses

    def generate_teacher_csv(self):
        with open('datafile.csv', 'w', newline='') as f:
            writer = csv.writer(f, delimiter=' ',
                                    quotechar='|', quoting=csv.QUOTE_MINIMAL)
            
            for i in self.courses :
                writer.writerow([i])

    def generate_student_csv(self):
        pass


random_generator = RandomGenerator()
random_generator.generate_student_csv()
random_generator.generate_teacher_csv()