#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
using namespace std;

#define TYPE 0
#define HEIGHT 1
#define MASS 2
#define EATEN 3

int find_lowest_valid_candy (int ** candies, int candy_count, int * cur_jump_height, int * cur_height)
{
	int lowest_valid_candy = INT_MAX; 
	cout << *cur_jump_height << " " << cur_height << endl;
	for (int i = 0; i < candy_count; ++i)
	{
		if (candies[i][HEIGHT] <= *cur_height + *cur_jump_height
			&& lowest_valid_candy > candies[i][HEIGHT]
			&& candies[i][EATEN] == 0)
		{

			// lowest_valid_candy = candies[i][HEIGHT];
			// lowest_valid_candy = 1;
		}
	}

	if (lowest_valid_candy == INT_MAX)
		return -1;
	return lowest_valid_candy;
}

int main ()
{
	int candy_count, initial_jump_height;
	cin >> candy_count >> initial_jump_height;
	int ** candies = (int**)calloc(candy_count, sizeof(int*));
	for (int i = 0; i < candy_count; ++i)
	{
		candies[i] = (int*)calloc(4, sizeof(int));
	}

	//Store all candies
	for (int i = 0; i < candy_count; ++i)
	{
		cin >> candies[i][TYPE] >> candies[i][HEIGHT] >> candies[i][MASS];
		candies[i][EATEN] = 0;	//0 incdicating not eaten
	}

	//Determine best candies
	int candies_eaten_one = 0;
	int candies_eaten_two = 0;
	int cur_jump_height = initial_jump_height;
	int cur_height = 0;
	
	{
		int cur_candy_type = 1;
		for (int i = 0; i < candy_count; ++i)
		{
		// int lowest_valid_candy = INT_MAX;
			int highest_available_mass_candy = -1;
			int highest_mass = -1; 
			for (int j = 0; j < candy_count; ++j)
			{
				if (candies[j][MASS] >= highest_mass
					&& candies[j][HEIGHT] <= cur_height + cur_jump_height
					&& candies[j][EATEN] == 0
					&& cur_candy_type != candies[j][TYPE])
				{
					highest_available_mass_candy = j;

				}
			}
			if (highest_available_mass_candy != -1) {
				cur_candy_type = candies[highest_available_mass_candy][TYPE];
				cur_height = candies[highest_available_mass_candy][HEIGHT];
				cur_jump_height += candies[highest_available_mass_candy][MASS];
				candies[highest_available_mass_candy][EATEN] = 1;
				candies_eaten_one++;
			}
		}
	}

	cur_jump_height = initial_jump_height;
	cur_height = 0;
	{
		int cur_candy_type = 0;
		for (int i = 0; i < candy_count; ++i)
		{
		// int lowest_valid_candy = INT_MAX;
			int highest_available_mass_candy = -1;
			int highest_mass = -1; 
			for (int j = 0; j < candy_count; ++j)
			{
				if (candies[j][MASS] >= highest_mass
					&& candies[j][HEIGHT] <= cur_height + cur_jump_height
					&& candies[j][EATEN] == 0
					&& cur_candy_type != candies[j][TYPE])
				{
					highest_available_mass_candy = j;

				}
			}
			if (highest_available_mass_candy != -1) {
				cur_candy_type = candies[highest_available_mass_candy][TYPE];
				cur_height = candies[highest_available_mass_candy][HEIGHT];
				cur_jump_height += candies[highest_available_mass_candy][MASS];
				candies[highest_available_mass_candy][EATEN] = 1;
				candies_eaten_two++;
			}
		}
	}

	if (candies_eaten_two > candies_eaten_one)
		cout << candies_eaten_two << endl;
	else
		cout << candies_eaten_one << endl;

	//Free all candies
	for (int i = 0; i < candy_count; ++i)
	{
		free(candies[i]);
	}
	free(candies);
	return 0;
}