import sys
import os
def main():
	if len(sys.argv) != 3:
		print("usage: generate_link_file.py [Easy/Medium/Hard] <filename.md>")
		return
	difficulty = sys.argv[1]
	filename = sys.argv[2]
	try:
		with open("./"+difficulty+"/"+filename,'w+') as f:
			f.write("[Click Here](../../Practice/"+filename+")")
	except Exception as e:
		print(e)
if __name__ == '__main__':
	main()