import os
import subprocess
import glob

COMPILER = 'gcc'


def get_spec_files():
    return glob.glob('*.spec.c')


def get_bin_file(spec_file):
    return '{}-spec'.format(spec_file.split('.')[0])


def get_lib_file(spec_file):
    return '{}.c'.format(spec_file.split('.')[0])


def call_compile(spec_file, bin_file, lib_file):
    return subprocess.call([COMPILER, '-o', bin_file, spec_file, lib_file])


def call_spec(bin_file):
    return subprocess.call(['./{}'.format(bin_file)])

if __name__ == '__main__':
    for spec_file in get_spec_files():
        bin_file = get_bin_file(spec_file)
        lib_file = get_lib_file(spec_file)
        if call_compile(spec_file, bin_file, lib_file) == 0:
            if call_spec(bin_file) != 0:
                print('{}: FAIL'.format(spec_file))
            print('{}: OK'.format(spec_file))
        else:
            print('{}: NOT COMPILED'.format(spec_file))
