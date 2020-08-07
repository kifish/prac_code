import random
from urllib import urlopen
import sys
WORD_URL="http://learncodethehardway.org/words.txt"
WORDS=[]

PHRASES={
	"class %%%(%%%):":
		"make a class named %%% that is-a %%%.",
	"class %%%(object):\n\tdef __init__(self,***)":
	"class %%% has-a __init__ that takes self and *** parameters.",
	"class %%%(object):\n\tdef ***(self,@@@)":
	"class %%% has-a funcition named ***that takes self and @@@ parameters.",
	"***=%%%()":
	"set *** to an insurance of class %%%.",
	"***.***(@@@)":
	"from *** get the *** function,and call it with parameters self,@@@.",
	"***.***='***'":
	"From *** get the *** attribute and set it to '***'."	
}
PHRASES_FIRST=False
if len(sys.argv)==2 and sys.argv[1]=="english":
	PHRASE_FIRST=True
for word in urlopen(WORD_URL).readlines() :
	WORDS.append(word.strip())
def convert(snippet,phrase):
	class_names=[w.capitalize()for w in 
						  random.sample(WORDS,snippet.count("%%%"))]
	other_names=random.sample(WORDS,snippet.count("***"))
	results=[]
	param_names=[]
	
	for i  in range(0,snippest.count("@@@")):
		param_count=random.randint(1,3)
		param_names.append(",".join(random.sample(WORDS,param_count)))
	for sentence in snippest,phrase:
		result=sentence[:]
		for word in class_names:
				result =result.replace("%%%",word,1)
		for word in other_names:
				result=result.replace("***",word,1)
		for word in param_names:
				result=result.replace("@@@",word,1)
		results.append(result)
	return results

try:
	while True:
		snippest=PHRASES.keys()
		random.shuffle(snippest)
		
		for snippest in snippest:
			phrase=PHRASES[snippest]
			question,answer=convert(snippest,phrase)
			if PHRASES_FIRST:
				question,answer=answer,question
			print(question)
			
			raw_input(">")
			print("answer:  %s\n\n"%answer)
except EOFError:
	print("\nBye")