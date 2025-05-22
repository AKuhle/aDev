import requests
import time
from bs4 import BeautifulSoup
import gender_guesser.detector as gender

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
# get_random_wikipedia_de_url
###################################################################
def get_random_wikipedia_de_url():
	url = "https://de.wikipedia.org/wiki/Spezial:Zuf%C3%A4llige_Seite"
	try:
		# Folge der Weiterleitung zur zufälligen Seite
		response = requests.get(url, allow_redirects=True, timeout=10)
		# Die endgültige URL ist die zufällige Wikipedia-Seite
		return response.url
	except Exception as e:
		print("Fehler beim Abrufen:", e)
		return None


###################################################################
# get_words_of_page
###################################################################
def get_words_of_page(url):
	# Webseite abrufen
	response = requests.get(url)
	response.raise_for_status()

	# HTML parsen und Text extrahieren
	soup = BeautifulSoup(response.text, "html.parser")
	text = soup.get_text(separator=' ')

	# Alle Wörter in ein Array schreiben
	words = text.split()

	return words


###################################################################
# is_word_unused
###################################################################
def is_word_unused(token):
	if token in arIgnoreList:
		return False

	if token in arUni:
		return False

	if token in arMale:
		return False

	if token in arFemale:
		return False

	return True


###################################################################
# check_name
###################################################################
def check_name(token):
	if len(token) > 3:
		d = gender.Detector()
		sex = d.get_gender(token)
		
		if sex in ('andy'):
			print (f"uni: {token}")
			# append the new name to the array and the file
			arUni.append(token)
			with open("names_uni.txt", "a") as file:
				file.write(token + "\n")
			return

		elif sex in ('female', 'mostly_female'):
			print (f"female: {token}")
			# append the new name to the array and the file
			arFemale.append(token)
			with open("names_female.txt", "a") as file:
				file.write(token + "\n")
			return

		elif sex in ('male', 'mostly_male'):
			print (f"male: {token}")
			# append the new name to the array and the file
			arMale.append(token)
			with open("names_male.txt", "a") as file:
				file.write(token + "\n")
			return


###################################################################
# main
###################################################################
if __name__ == "__main__":
	# read the name files from the filesystem
	read_files()

	# append marker for female names
	with open("names_female.txt", "a") as file:
		file.write("\n\n\nnew names\n")

	# append marker for male names
	with open("names_male.txt", "a") as file:
		file.write("\n\n\nnew names\n")
		
	# append marker for uni names
	with open("names_uni.txt", "a") as file:
		file.write("\n\n\nnew names\n")

	# find names until the job is canceled
	while True:
		url = get_random_wikipedia_de_url()
		print(f"\n****************************************\nnext url: {url}")
		words = get_words_of_page(url)

		# check all words for a valid name
		for token in words:
			if is_word_unused(token):
				check_name(token)

