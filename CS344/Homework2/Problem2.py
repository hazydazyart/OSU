#Megan Conley
#conleyme@onid.oregonstate.edu
#CS344-400
#Homework 2

import os
import sys
import getopt

def createFolders(argv):
	term_folder = ''
	class_folder = ''

	#Parse and test command line arguments
	#GetoptError usage found on https://docs.python.org/2/library/getopt.html	
	try:
		opts, args = getopt.getopt(sys.argv[1:], 't:c:', ['term=', 'class='])
	except getopt.GetoptError:
		print 'Error: both options require arguments. Usage: python Problem2 -t <term> -c <class>'
		sys.exit(2)
	# GetoptError doesn't test for having the right number of arguments
	# so I added this additional test
        if len(argv) != 4 :
                print 'Usage: python Problem2.py -t <term> -c <class>'
		sys.exit(2)

	# Loops through arguments and assigns appropriate name to variables
	for opt, arg in opts:
		if opt in ('-t', '--term'):
			term_folder = arg
		elif opt in ('-c', '--class'):
			class_folder = arg

	# Defining the path for each new folder
	path = term_folder + '/' + class_folder
	assign_folder = path + '/assignments'
	ex_folder = path + '/examples'
	exam_folder = path + '/exams'
	lec_folder = path + '/lecture_notes'
	sub_folder = path + '/submissions'
	
	# Try to create new directory; if it already exists, exit with error message
	newDir = os.path.dirname(path)
	if os.path.exists(newDir):
		print 'Error: Directory already exists.'
		sys.exit(2)

	# Otherwise, make each new folder
	else:
		os.makedirs(path)
		os.makedirs(assign_folder)
		os.makedirs(ex_folder)
		os.makedirs(exam_folder)
		os.makedirs(lec_folder)
		os.makedirs(sub_folder)
		print 'Created directories'

	#Create symbolic links
	link1 = '/usr/local/classes/eecs/' + term_folder + '/' + class_folder + '/README'
	link2 = '/usr/local/classes/eecs/' + term_folder + '/' + class_folder + '/src'
	os.symlink(link1, 'README')
	os.symlink(link2, 'src')
	print 'Created links README and src'

if __name__ == '__main__':
	createFolders(sys.argv[1:])	
