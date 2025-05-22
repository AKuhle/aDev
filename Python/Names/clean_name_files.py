arFile = ["names_female.txt", "names_uni.txt", "ignore_list.txt"]


###################################################################
# removeDouble
###################################################################
def removeDouble(fileName):
	einzigartige_zeilen = []
	gesehen = set()

	with open(fileName, "r") as file:
		zeilen = file.readlines()

	# Doppelte Zeilen entfernen, Reihenfolge beibehalten
	for zeile in zeilen:
		if zeile not in gesehen:
			einzigartige_zeilen.append(zeile)
			gesehen.add(zeile)
		else:
			print(f"doppelt: {zeile} in {fileName}")

	with open(fileName, "w") as file:
		file.writelines(einzigartige_zeilen)
				

###################################################################
# sortFiles
###################################################################
def sortFiles(fileName):
	with open(fileName, "r") as file:
		zeilen = [line.rstrip('\n') for line in file]

	zeilen.sort()

	with open(fileName, "w") as file:
		for zeile in zeilen:
			file.write(zeile + "\n")


###################################################################
# main
###################################################################
if __name__ == "__main__":
	for fileName in arFile:
		removeDouble(fileName)
		sortFiles(fileName)

