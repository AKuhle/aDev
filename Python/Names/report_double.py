arFile = ["names_female.txt", "names_male.txt", "names_uni.txt", "ignore_list.txt"]

arIgnoreList = []
arMale = []
arFemale = []
arUni = []


###################################################################
# read_files
###################################################################
def read_files():
	global arIgnoreList, arMale, arFemale, arUni

	# read ignore list
	try:
		with open("ignore_list.txt", "r") as file:
			arIgnoreList = [line.strip() for line in file if line.strip()]
	except FileNotFoundError:
		pass

	# read female names
	try:
		with open("names_female.txt", "r") as file:
			arFemale = [line.strip() for line in file if line.strip()]
	except FileNotFoundError:
		pass

	# read male names
	try:
		with open("names_male.txt", "r") as file:
			arMale = [line.strip() for line in file if line.strip()]
	except FileNotFoundError:
		pass
		
	# read uni names
	try:
		with open("names_uni.txt", "r") as file:
			arUni = [line.strip() for line in file if line.strip()]
	except FileNotFoundError:
		pass


###################################################################
# main
###################################################################
if __name__ == "__main__":
	# read the name files from the filesystem
	read_files()

	arToken = [arIgnoreList, arMale, arFemale, arUni] 
	arNames = ["arIgnoreList", "arMale", "arFemale", "arUni"] 

	# check for duplicates
	for i1 in range(0, 4):
		for i2 in range(0, 4):
			if (i1 != i2):
				for w1 in arToken[i1]:
					for w2 in arToken[i2]:
						if (w1 == w2):
							print(f"Duplicate found: {w1} in {arNames[i1]} and {arNames[i2]}")
