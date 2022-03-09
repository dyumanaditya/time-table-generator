import csv

with open('eggs.csv', 'w', newline='') as f:
    writer = csv.writer(f, delimiter=' ',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
    writer.writerow(['Spam'] * 5 + ['Baked Beans'])
    writer.writerow(['Spam', 'Lovely Spam', 'Wonderful Spam'])