from dataclasses import replace
from os import system
from bs4 import BeautifulSoup
import requests

html_text = requests.get('https://www.ratatype.com/typing-test/test/').text
soup = BeautifulSoup(html_text, 'lxml')
content = soup.find_all('div', class_= 'mainTxt')
wpm = soup.find('span', id_= 'certificateSpeed')
system('cls')
print(content[0].text)
#print("\n\nWpm = ",wpm)
#print(f'''
#START TYPING : {content[0].text}
#WPM : {wpm}
#''')


#sentence = ''
wordcount = len(set(content.split()))
print(wordcount)
