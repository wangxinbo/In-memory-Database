import os
import sys
import subprocess

exe_file = './../bin/simpleDB'

if not os.path.exists(exe_file):
    print 'no executable files, please compile first...'
    sys.exit(0)

test_case = 1

while True:
    input_file  = os.path.join('./', 'input.%d' % test_case)
    output_file = os.path.join('./', 'output.%d' % test_case)

    if not os.path.exists(input_file) or not os.path.exists(output_file):
        break

    p = subprocess.Popen(exe_file, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    with open(input_file) as input_stream:
        p.stdin.write(input_stream.read())
        p.stdin.close()
        output = p.stdout.read()

    with open(output_file) as output_stream:
        asserts = output_stream.read()
        if output != asserts:
            print "Test case %d is not OK!" % test_case
        else:
            print "Test case %d is OK!" % test_case

    test_case += 1


