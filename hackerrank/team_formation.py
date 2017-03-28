import sys
MAX_GROUP_SIZE = int(10e100 + 1)

def check_if_same_group(prev_num, cur_num):
    return prev_num + 1 == cur_num

def at_last_list_item(index, num_list):
    return index == len(num_list)-1

def build_list_of_team_sets(skill_list):
    list_of_teams = []
    for cur_skill in skill_list:
        add_to_first_available_team(cur_skill, list_of_teams)
    return list_of_teams

def add_to_first_available_team(cur_skill, list_of_teams):
    for team in list_of_teams:
        if len(team) > 0 and check_if_same_group(team[-1], cur_skill):
            team.append(cur_skill)
            return
    list_of_teams.append([cur_skill])

def find_smallest_consecutive_sublist(skill_list):
    skill_list.sort()
    if len(skill_list) == 0:
        return 0

    smallest_group = MAX_GROUP_SIZE
    optimal_list_of_teams = build_list_of_team_sets(skill_list)
    for team in optimal_list_of_teams:
        if len(team) < smallest_group:
            smallest_group = len(team)
    return smallest_group

num_of_test_cases = int(input())
for test_case in range(num_of_test_cases):
    numbers = list(map(int, input().split(' ')))[1:]
    smallest_group = find_smallest_consecutive_sublist(numbers)
    print(smallest_group)
