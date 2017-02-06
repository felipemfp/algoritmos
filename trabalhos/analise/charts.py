import matplotlib.pyplot as plt
import csv
import glob
import os


def pow(value):
    x, y = map(int, value.split('^'))
    return y


if __name__ == '__main__':
    try:
        os.mkdir('charts')
    except:
        pass
    for csvfile in glob.glob('csv/*.csv'):
        with open(csvfile) as csvf:
            title = csvfile.split('/')[1].split('.')[0]
            data = [(pow(row[0]), float(row[1])) for row in csv.reader(csvf)]
            plt.plot(*zip(*data))
            plt.ylabel('tempo (ms)')
            plt.xlabel(title.title())
            plt.savefig('charts/{}.linux.png'.format(title))
