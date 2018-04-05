import codecs
from bs4 import BeautifulSoup
page = codecs.open("ukyallclasses.html", 'r')
out = codecs.open("output.txt","w")
soup = BeautifulSoup(page.read(), 'html5lib')
classList = soup.find(id='offering-results')
classListAvailable=classList.find_all('div', attrs={'data-offered-in-specified-term':'True'}, recursive=False)

for course in classListAvailable:
    name = course.div.div.div.div.h4.get_text()
    out.write(name)
    sectionData = [[]] #this is the problem, need to define a matrix differently
    i = 0
    for section in course.div.next_sibling.next_sibling.next_sibling.next_sibling.find_all('div', attrs={'class':'table-thin-row'}):
        sectionData[i][0] = section.div.div.get_text().strip() #here is where the error becomes apparent
        for times in section.find_all('div'):
            part=times.find(attrs={'style':'width: 140px'})
            sectionData[i].append(part.div.get_text()+' '+ part.div.next_sibling.next_sibling.get_text())
        i+=1
    out.write(' ' + len(sectionData)+'\n')
    for i in range(len(sectionData)):
        out.write(len(sectionData[i]+' '))
        for j in range(len(secitonData[i])):
            out.write(sectionData[i][j])
