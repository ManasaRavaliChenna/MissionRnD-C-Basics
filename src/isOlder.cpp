/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int checkDate(char *d, int *dt, int *m, int *y);
int isOlder(char *dob1, char *dob2)
{
	int i, d1 = 0, m1 = 0, y1 = 0, d2 = 0, m2 = 0, y2 = 0;
	i = checkDate(dob1, &d1, &m1, &y1);
	if (i == -1)
		return -1;
	i = checkDate(dob2, &d2, &m2, &y2);
	if (i == -1)
		return -1;
	if (y1 < y2)
		return 1;
	else if (y2 < y1)
		return 2;
	else
	{
		if (m1 < m2)
			return 1;
		else if (m2 < m1)
			return 2;
		else
		{
			if (d1 < d2)
				return 1;
			else if (d2 < d1)
				return 2;
			else
				return 0;
		}
	}
}
int checkDate(char *d, int *dt, int *m, int *y)
{
	int i = 0, c = 0;
	while (d[i] != '\0')
	{
		if (c == 0)
		{
			while (d[i] != '-')
			{
				if (d[i] == '\0')
					return -1;
				*dt = *dt * 10 + (d[i] - '0');
				i++;
			}
			c++;
			i++;
			if (*dt > 31)
				return -1;

		}
		else if (c == 1)
		{
			while (d[i] != '-')
			{
				if (d[i] == '\0')
					return -1;
				*m = *m * 10 + (d[i] - '0');
				i++;
			}
			c++; i++;
			if (*m > 12)
				return -1;
			if ((*m == 2) && (*dt > 29))
				return -1;
			if ((*m == 4 || *m == 6 || *m == 7 || *m == 9 || *m == 11) && (*dt > 30))
				return -1;

		}
		else if (c == 2)
		{
			while (d[i] != '\0')
			{
				if (d[i] == '-')
					return -1;
				*y = *y * 10 + (d[i] - '0');
				i++;
			}
			c++;
			if (*m == 2)
				if (!(((*y % 4 == 0) && (*y % 100 != 0)) || (*y % 400 == 0)))
					if (*m == 2 && *dt > 28)
						return -1;
		}
		else
			return -1;
	}
	return 1;
}