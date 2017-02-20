#!/bin/python3

import sys

# February is marked with 28, but can be swapped out as needed
days_in_month_non_leap  = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
days_in_month_leap      = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
days_in_month_1919      = [31, 15, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def is_julian_leap_year(year):
    return year % 4 == 0

def is_gregorian_leap_year(year):
    return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)

def format_month_or_day(number):
    if number < 10:
        return '0{}'.format(str(number))
    
    return number;

def get_256th_day_full_date(days_in_months, year):
    accumulative_days = 0
    months_elapsed = 0
    while accumulative_days + days_in_months[months_elapsed] < 256:
        accumulative_days += days_in_months[months_elapsed]
        months_elapsed += 1

    formatted_day = format_month_or_day(256 - accumulative_days)
    formatted_month = format_month_or_day(months_elapsed + 1)
    return '{}.{}.{}'.format(formatted_day, formatted_month, year)

y = int(input().strip())
# your code goes here

# Julian calendar
if y < 1918:
    if is_julian_leap_year(y):
        date_256 = get_256th_day_full_date(days_in_month_leap, y)
    else:
        date_256 = get_256th_day_full_date(days_in_month_non_leap, y)

# Year transitioned to Gregorian calendar
elif y == 1918:
    date_256 = get_256th_day_full_date(days_in_month_1919, y)

# Gregorian calendar
elif y > 1918:
    if is_gregorian_leap_year(y):
        date_256 = get_256th_day_full_date(days_in_month_leap, y)
    else:
        date_256 = get_256th_day_full_date(days_in_month_non_leap, y)

print(date_256)
