import codecs
from bs4 import BeautifulSoup
page = codecs.open('ukyallclasses.html', 'r')
out = codecs.open('output.txt','w')
soup = BeautifulSoup(page.read(), 'html5lib')
classList = soup.find(id='offering-results')
classListAvailable=classList.find_all('div', attrs={'data-offered-in-specified-term':'True'}, recursive=False)

for course in classListAvailable:
    name = course.div.div.div.div.h4.get_text()
    out.write(name)
    sectionData = [] #this is the problem, need to define a matrix differently
    i = 0
    for section in course.div.next_sibling.next_sibling.next_sibling.next_sibling.find_all('div', attrs={'class':'table-thin-row'}):
        sectionData.append([])
        sectionData[i].append(section.div.div.get_text().strip()) #here is where the error becomes apparent
        for times in section.find_all('div',attrs={'class':'clearfix'}):
            part=times.find('div',attrs={'style':'width: 140px;'})
            if 'course-cancelled' not in part['class'] and 'TBD' not in part.get_text():
                sectionData[i].append(part.div.get_text()+' '+ part.div.next_sibling.next_sibling.get_text())
        i+=1
    out.write(' ' + str(len(sectionData))+'\n')
    for e in range(len(sectionData)):
        out.write(str(len(sectionData[e]))+' ')
        for j in range(len(sectionData[e])):
            out.write(sectionData[e][j]+' ')
        out.write('\n')
