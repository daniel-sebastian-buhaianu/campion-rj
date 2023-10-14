#include <fstream>
#define NMAX 104
#define MMAX 104
#define ND 8
#define NP 2
using namespace std;
ifstream fin("rj.in");
ofstream fout("rj.out");
struct pozitie
{
	int i, j;
};
pozitie ps[NP], cd[NP][NMAX*MMAX], p, v;
int a[NP][NMAX][MMAX], inc[NP], sf[NP], tmin;
int dl[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main()
{
	int n, m, i, j, k, d, imin, jmin;
	char c;
	fin >> n >> m;
	fin.get(c);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			fin.get(c);
			if (c == 'X')
			{
				for (k = 0; k < NP; k++)
				{
					a[k][i][j] = -1;
				}
			}
			else if (c == 'R')
			{
				ps[0].i = i;
				ps[0].j = j;
			}
			else if (c == 'J')
			{
				ps[1].i = i;
				ps[1].j = j;
			}
		}
		fin.get(c);
	}
	fin.close();
	for (k = 0; k < NP; k++)
	{
		for (j = 0; j <= m+1; j++)
		{
			a[k][0][j] = a[k][n+1][j] = -1;
		}

		for (i = 0; i <= n+1; i++)
		{
			a[k][i][0] = a[k][i][m+1] = -1;
		}
	}
	for(k = 0; k < NP; k++)
	{
		cd[k][sf[k]] = ps[k];
		a[k][ps[k].i][ps[k].j] = 1;
		while (inc[k] <= sf[k])
		{
			p = cd[k][inc[k]++];
			for (d = 0; d < ND; d++)
			{
				v.i = p.i + dl[d];
				v.j = p.j + dc[d];
				if (a[k][v.i][v.j] == 0)
				{
					a[k][v.i][v.j] = 1 + a[k][p.i][p.j];
					cd[k][++sf[k]] = v;
					if (k == 1
						&& a[k][v.i][v.j] == a[k-1][v.i][v.j])
					{
						if (!tmin || a[k][v.i][v.j] < tmin)
						{
							tmin = a[k][v.i][v.j];
							imin = v.i, jmin = v.j;
						}
					}
				}
			}
		}
	}
	fout << tmin << ' ' << imin << ' ' << jmin;
	fout.close();
	return 0;
}
// scor 60
