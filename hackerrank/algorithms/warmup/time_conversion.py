def convert_twelve_to_twentyfour_hour_time(timestamp):
    hours = int(timestamp[:2])
    if timestamp[-2:] == 'PM' and hours != 12:
        return '{}{}'.format(hours+12, timestamp[2:-2])
    elif timestamp[-2:] == 'AM' and hours == 12:
        return '{}{}'.format('00', timestamp[2:-2])
    else:
        return timestamp[:-2]

twelve_hour_time = input()
twentyfour_hour_time \
    = convert_twelve_to_twentyfour_hour_time(twelve_hour_time)
print(twentyfour_hour_time)
