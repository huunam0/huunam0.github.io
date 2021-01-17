#!/usr/bin/python
import glob
from bs4 import BeautifulSoup

def get_file_content(filename):
	f = open(filename, 'r',encoding="utf8")
	contents = f.read()
	f.close()
	return contents
def put_file_content(filename, contents):
	f = open(filename,"w",encoding="utf8")
	f.write(contents)
	f.close()
img = ""
for fn in glob.glob('*.html'):
	soup = BeautifulSoup(get_file_content(fn), 'lxml')
	for i in soup.find_all("img"):
		img+= i['src']+'\n'
put_file_content("hinh.txt",img)
    