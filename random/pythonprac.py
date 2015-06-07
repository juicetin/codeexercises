from math import sqrt

def adj_distances_coords(coord_list):
    dist_list = []
    for i in range(1, len(coord_list)):
        x = coord_list[i][0] - coord_list[i-1][0]
        y = coord_list[i][1] - coord_list[i-1][1]
        dist_list.append(sqrt(x*x + y*y))
    return dist_list


a = [3, 4, 11, 9, 2, 17, 12]
b = [8, 3, 24, 35, 15, 63, 48]
c = [] 
coords = [[3,8], [4,3], [11,24], [9,35], [2,15], [17,63], [12,48]]
d = []

for i in range(1, len(a)):
    x = a[i] - a[i-1]
    y = b[i] - b[i-1]
    c.append(sqrt(x*x + y*y))

d = adj_distances_coords(coords)

print (c)
print (d)


