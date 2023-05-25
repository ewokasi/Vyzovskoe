#include "myr.h"
# define NO_OF_CHARS 256

int maxx(int a, int b)
{
	return (a > b) ? a : b;
}

bool search_myr(std::string txt, std::string pat)
{

	int n = txt.length();
	int m = pat.length();
	int badchar[NO_OF_CHARS];

	int s = 0; 
	while (s <= (n - m))
	{
		int j = m - 1;
		while (j >= 0 && pat[j] == txt[s + j])
			j--;
		if (j < 0)
		{
			return 1;
		}
		else
			s += maxx(1, j - badchar[txt[s + j]]);
	}
	return 0;
}