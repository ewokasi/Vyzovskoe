#include "myr.h"


int maxx(int a, int b)
{
	return (a > b) ? a : b;
}

bool search_myr(std::string txt, std::string pat)
{

	int m = pat.length();
	int n = txt.length();
	int badchar[NO_OF_CHARS];

	int s = 0; // s is shift of the pattern with respect to text
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