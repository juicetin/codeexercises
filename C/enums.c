#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *	User object
 */
struct user {
	int 	id;
	char	first_name[128];
	char	last_name[128];
	char 	fav_color[128];
} typedef User;

void set_user_colour (User *user, char * new_color) {
	strcpy((*user).fav_color, new_color);
}

void set_user_fn(User *user, char * first_name)
{
	strcpy((*user).first_name, first_name);
}

/*
 *	Days of the week
 */
enum day_name {
	Mon, Tue, Wed, Thu, Fri, Sat, Sun, day_undef
};

/*
 *	Months of the year
 */
enum month_name {
	Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec, month_undef
};

/*
 *	Date object
 */
struct date {
	enum day_name 	day;
	int 			day_num;
	enum month_name month;
	int 			year;
} typedef Date;

struct date moonlanding;
struct date deadline = {day_undef, 1, Jan, 2000};

struct date *completion;


int main()
{
	Date bigday = {Mon, 7, Jan, 1980};
	Date *mydate;
	int theyear;
	int theday;

	mydate = &bigday;

	theyear = mydate->year;
	theday = mydate->day;

	printf("%d\n", theday);

	User me = {1, "Justin", "Ting", "Blue"};
	set_user_colour(&me, "Red");
	printf("%s\n", me.fav_color);

	User * you = (User*)malloc(sizeof(User));
	set_user_fn(you, "Sammi");
	printf("%s\n", (*you).first_name);
	free(you);
}

