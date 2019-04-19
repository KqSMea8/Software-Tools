import xlrd 
import xlsxwriter
import json
import random
import string
import re

##was getting a weird encoding error, had to add sys below
##
import sys
reload(sys)  
sys.setdefaultencoding('utf8')

## Variables
##
first_name=[]
last_name=[]
location=[]
website=[]
bignum = 1000000
col = 0

## load files
##
with open('utility/names/first-names.json',"r") as json_file:  
    data = json.load(json_file)
    for p in data:
        first_name.append(p)

file = open('utility/names/surnames/all.txt')
for line in file:
    last_name.append(line)
file.close()

file = open('utility/locations/gistfile1.txt')
for line in file:
    location.append(line)
file.close()

file = open('utility/websites/csv')
for line in file:
    content = re.findall(r'"(.*?)"', line)
    website.append(content)
file.close()

## example skeleton
##
#print random.randint(0, bignum)
#print random.choice(first_name)
#print random.choice(string.ascii_uppercase)
#print random.choice(last_name)
#print random.choice(website)
#print random.choice(location)

## Create a workbook and add a worksheet.
##
workbook = xlsxwriter.Workbook('Persons.xlsx')
worksheet = workbook.add_worksheet()
worksheet2 = workbook.add_worksheet()
worksheet3 = workbook.add_worksheet()
work_name = 'Persons.xlsx'

for row in xrange(0,3):
    name = str(random.choice(first_name)) + " " + str(random.choice(string.ascii_uppercase)) + ". " + str(random.choice(last_name))
#    print name
    worksheet.write(row, col, random.randint(0, int(bignum)))
    worksheet.write(row, col + 1, str(random.choice(website)))
    worksheet.write(row, col + 2, name)
    worksheet.write(row, col + 3, str(random.choice(location)))


for row in xrange(0,101):
    name = str(random.choice(first_name)) + " " + str(random.choice(string.ascii_uppercase)) + ". " + str(random.choice(last_name))
#    print name
    worksheet2.write(row, col, random.randint(0, int(bignum)))
    worksheet2.write(row, col + 1, str(random.choice(website)))
    worksheet2.write(row, col + 2, name)
    worksheet2.write(row, col + 3, str(random.choice(location)))

for row in xrange(0,100,001):
    name = str(random.choice(first_name)) + " " + str(random.choice(string.ascii_uppercase)) + ". " + str(random.choice(last_name))
#    print name                                                                                                                              
    worksheet2.write(row, col, random.randint(0, int(bignum)))
    worksheet2.write(row, col + 1, str(random.choice(website)))
    worksheet2.write(row, col + 2, name)
    worksheet2.write(row, col + 3, str(random.choice(location)))

workbook.close()

## ways to read
##
wb = xlrd.open_workbook(work_name) 
sheet = wb.sheet_by_index(0) 
  
## For row 0 and column 0 
##
sheet.cell_value(0, 0) 
  
for i in range(sheet.nrows): 
#    print(sheet.cell_value(0, i)) 
    print(sheet.row_values(i)) 
