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

    ##opens excel files
    ##
    for f in variables.file:
        loc = (f)
        wb = xlrd.open_workbook(loc) 

    ##goes through each worksheet in workbook
    ##
        for sheet_num in range(0, wb.nsheets):

            sheet = wb.sheet_by_index(sheet_num)
            sheet.cell_value(0, 0) 

            ##goes through all rows in 3rd column
            ##
            for i in range(sheet.nrows): 
                print(sheet.cell_value(i, 2))
                names.append(sheet.cell_value(i, 2))

    ##sorts last name then first
    ##
    names = sorted(names, key=lambda x: (x.split(" ")[-1], x.split(" ")[0]))

    for n in names:
        print n
