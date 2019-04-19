#!/usr/bin/env python

##used for help input
##
import argparse

##used to search directories?
##
import os
import xlrd


if __name__ == "__main__":
    names = []
    parser = argparse.ArgumentParser()
    parser.add_argument('file', nargs='*') 
    variables = parser.parse_args()

    for f in variables.file:
        loc = (f)
        wb = xlrd.open_workbook(loc) 
        for sheet_num in range(0, wb.nsheets-1):
            print wb.nsheets
            print sheet_num
            sheet = wb.sheet_by_index(sheet_num)
            sheet.cell_value(0, 0) 
  
            for i in range(sheet.nrows): 
                print(sheet.cell_value(i, 2))
                names = sheet.cell_value(i, 2)
            
    sorted(names, key=lambda x: x.split(" ")[-1])
#    print names
