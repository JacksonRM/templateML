#!/usr/bin/python

"""
languageAnalyzer.py
Author: Jackson Marusarz

Analyzes all the files in a directory and counts the number of ;  {  [  <  :  (
in each file.  Classifies it as C++ is extension is .cpp or .h
Outputs to a temporary file for use by LanguageCollector.cpp
"""


import glob
import os
import sys
import getopt
import re
import random
"""
Function to parse command line arguments
"""
def main(argv):
	try:
		opts, args = getopt.getopt(argv, "hd:", ["help","dir="])
	except getopt.GetoptError:
		usage()
		sys.exit(2)
	for opt, arg in opts:
		if opt in ("-h", "--help"):
			usage()
			sys.exit()
		elif opt in ("-d", "--dir"):
			global directory
			directory = arg

		


def usage():
	print "-d to specify directory"
	print "-h for this help message"
	
	
	"""
Function to open a file
"""
def open_file(filename):
    try:
        file_in=open(filename, 'r')        # check if file exists
    except IOError:
	usage()
        print 'Can\'t open file ' + filename
        sys.exit()                              # if not, exit
    return file_in
    
    
    
"""
Function to locate item in an array
"""
def findInArray(item, myArray):
	arrayOffset = 0
	while(arrayOffset < len(myArray)):
		if (item == myArray[arrayOffset]):
			return arrayOffset
		arrayOffset += 1
	return -1
    
    
	
"""
main functon
"""
if __name__ == '__main__':
	
	main(sys.argv[1:])
	for inputfile in os.listdir(directory):
		#print inputfile
		cfile = 0
		
		semicolon = 0
		curly_brace = 0
		square_bracket = 0
		angle_bracket = 0
		colon = 0
		paren = 0
		
		parsed = inputfile.split('.')
		ext = parsed[-1]
		if ((ext == "h")or(ext == "cpp")):
			cfile = 1
		
		path = directory + "/" +inputfile
		file = open_file(path)
		line = file.readline()
		while(line):
			for j in range(len(line)):
				if(line[j] == ';'):
					semicolon += 1
				elif(line[j] == '{'):
					curly_brace += 1
				elif(line[j] == '['):
					square_bracket += 1
				elif(line[j] == '<'):
					angle_bracket += 1
				elif(line[j] == ':'):
					colon += 1
				elif(line[j] == '('):
					paren += 1
			line = file.readline()
	
		sum = 1 + semicolon + curly_brace + square_bracket + angle_bracket + colon + paren
		print str(float(semicolon)/sum) + " " + str(float(curly_brace)/sum) + " " + str(float(square_bracket)/sum) + " " + str(float(angle_bracket)/sum) + " " + str(float(colon)/sum) + " " + str(float(paren)/sum) + " " + str(cfile)

