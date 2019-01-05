#include <iostream>
#include <fstream>
#include <conio.h>
#include <math.h>
#include <vector>
using namespace std;


struct point
{
	int i;
	int j;
};


struct s_top
{
	point atop;
	int prior;
};


struct top
{
	int prior;
	point pred;
	bool flag;
	s_top mas[4];
};


struct q
{
	point atop;
	int prior;
	point pred;
	int var;
};


struct result
{
	int prior;
	int num;
	vector <point> grani;
};


int n, m;
int kybik[24][6] = {
/*0*/{ 1,2,5,4,6,3 },
/*1*/{ 1,6,2,5,4,3 },
/*2*/{ 1,4,6,2,5,3 },
/*3*/{ 1,5,4,6,2,3 },
/*4*/{ 2,1,6,3,5,4 },
/*5*/{ 2,5,1,6,3,4 },
/*6*/{ 2,3,5,1,6,4 },
/*7*/{ 2,6,3,5,1,4 },
/*8*/{ 3,2,6,4,5,1 },
/*9*/{ 3,5,2,6,4,1 },
/*10*/{ 3,4,5,2,6,1 },
/*11*/{ 3,6,4,5,2,1 },
/*12*/{ 4,1,5,3,6,2 },
/*13*/{ 4,6,1,5,3,2 },
/*14*/{ 4,3,6,1,5,2 },
/*15*/{ 4,5,3,6,1,2 },
/*16*/{ 5,1,2,3,4,6 },
/*17*/{ 5,4,1,2,3,6 },
/*18*/{ 5,3,4,1,2,6 },
/*19*/{ 5,2,3,4,1,6 },
/*20*/{ 6,1,4,3,2,5 },
/*21*/{ 6,2,1,4,3,5 },
/*22*/{ 6,3,2,1,4,5 },
/*23*/{ 6,4,3,2,1,5 } };


int step[24][4] = {
/*0*/{ 6,19,12,21 },
/*1*/{ 22,7,16,13 },
/*2*/{ 14,23,4,17 },
/*3*/{ 18,15,20,5 },
/*4*/{ 2,20,8,16 },
/*5*/{ 17,3,21,9 },
/*6*/{ 10,18,0,22 },
/*7*/{ 23,11,19,1 },
/*8*/{ 4,21,14,19 },
/*9*/{ 16,5,22,15 },
/*10*/{ 12,17,6,23 },
/*11*/{ 20,13,18,7 },
/*12*/{ 0,16,10,20 },
/*13*/{ 21,1,17,11 },
/*14*/{ 8,22,2,18 },
/*15*/{ 19,9,23,3 },
/*16*/{ 1,4,9,12 },
/*17*/{ 13,2,5,10 },
/*18*/{ 11,14,3,6 },
/*19*/{ 7,8,15,0 },
/*20*/{ 3,12,11,4 },
/*21*/{ 5,0,13,8 },
/*22*/{ 9,6,1,14 },
/*23*/{ 15,10,7,2 } };


int** matr;
int** curmatr;
point start, end;
top* graph;
int work[6];
int anum;


class PQueue
{
public:
	q* pqueue;
	int amount;
	int num;
	PQueue(int k);
	~PQueue();
	void Add(q);
	void Delete_min(q &avalue);
};


PQueue::PQueue(int k)
{
	amount = k;
	pqueue = new q[amount];
	num = 0;
}


void PQueue::Add(q work)
{
	if (num<amount)
	{
		num = num + 1;
		int i = num;
		pqueue[i - 1].var = work.var;
		pqueue[i - 1].atop.i = work.atop.i;
		pqueue[i - 1].atop.j = work.atop.j;
		pqueue[i - 1].pred.i = work.pred.i;
		pqueue[i - 1].pred.j = work.pred.j;
		pqueue[i - 1].prior = work.prior;
		while ((work.prior<pqueue[i / 2 - 1].prior) && (i / 2 >= 1))
		{
			pqueue[i - 1].var = pqueue[i / 2 - 1].var;
			pqueue[i - 1].atop.i = pqueue[i / 2 - 1].atop.i;
			pqueue[i - 1].atop.j = pqueue[i / 2 - 1].atop.j;
			pqueue[i - 1].pred.i = pqueue[i / 2 - 1].pred.i;
			pqueue[i - 1].pred.j = pqueue[i / 2 - 1].pred.j;
			pqueue[i - 1].prior = pqueue[i / 2 - 1].prior;
			i = i / 2;
			pqueue[i - 1].var = work.var;
			pqueue[i - 1].atop.i = work.atop.i;
			pqueue[i - 1].atop.j = work.atop.j;
			pqueue[i - 1].pred.i = work.pred.i;
			pqueue[i - 1].pred.j = work.pred.j;
			pqueue[i - 1].prior = work.prior;
		}
	}
}


void PQueue::Delete_min(q &avalue)
{
	if (num>0)
	{
		avalue.var = pqueue[0].var;
		avalue.atop.i = pqueue[0].atop.i;
		avalue.atop.j = pqueue[0].atop.j;
		avalue.pred.i = pqueue[0].pred.i;
		avalue.pred.j = pqueue[0].pred.j;
		avalue.prior = pqueue[0].prior;
		q last;
		int i, child;
		bool stop;
		last.var = pqueue[num - 1].var;
		last.atop.i = pqueue[num - 1].atop.i;
		last.atop.j = pqueue[num - 1].atop.j;
		last.pred.i = pqueue[num - 1].pred.i;
		last.pred.j = pqueue[num - 1].pred.j;
		last.prior = pqueue[num - 1].prior;
		num--;
		i = 1;
		stop = false;
		while ((2 * i <= num) && (!stop))
		{
			child = 2 * i;
			if (child<num)
				if (pqueue[child].prior<pqueue[child - 1].prior)
					child++;
			if (last.prior>pqueue[child - 1].prior)
			{
				pqueue[i - 1].var = pqueue[child - 1].var;
				pqueue[i - 1].atop.i = pqueue[child - 1].atop.i;
				pqueue[i - 1].atop.j = pqueue[child - 1].atop.j;
				pqueue[i - 1].pred.i = pqueue[child - 1].pred.i;
				pqueue[i - 1].pred.j = pqueue[child - 1].pred.j;
				pqueue[i - 1].prior = pqueue[child - 1].prior;
				i = child;
			}
			else
				stop = true;
		}
		pqueue[i - 1].var = last.var;
		pqueue[i - 1].atop.i = last.atop.i;
		pqueue[i - 1].atop.j = last.atop.j;
		pqueue[i - 1].pred.i = last.pred.i;
		pqueue[i - 1].pred.j = last.pred.j;
		pqueue[i - 1].prior = last.prior;
	}
}


PQueue::~PQueue()
{
	delete[]pqueue;
}


class RQueue
{
public:
	result* rqueue;
	int amount;
	int num;
	RQueue(int k);
	~RQueue();
	void Add(result);
};

RQueue::RQueue(int k)
{
	amount = k;
	rqueue = new result[amount];
	num = 0;
}

void RQueue::Add(result work)
{
	if (num != amount)
	{
		num = num + 1;
		int i = num;
		rqueue[i - 1].grani.clear();
		for (int j = 0; j<work.grani.size(); j++)
		{

			rqueue[i - 1].grani.push_back(work.grani[j]);
		}
		rqueue[i - 1].prior = work.prior;
		rqueue[i - 1].num = work.num;
		while ((work.prior<rqueue[(i / 2) - 1].prior) && (i / 2 >= 1))
		{
			rqueue[i - 1].grani.clear();
			for (int j = 0; j<work.grani.size(); j++)
			{

				rqueue[i - 1].grani.push_back(rqueue[(i / 2) - 1].grani[j]);
			}

			rqueue[i - 1].prior = rqueue[(i / 2) - 1].prior;
			rqueue[i - 1].num = rqueue[(i / 2) - 1].num;
			i = i / 2;
			rqueue[i - 1].grani.clear();
			for (j = 0; j<work.grani.size(); j++)
			{

				rqueue[i - 1].grani.push_back(work.grani[j]);
			}
			rqueue[i - 1].prior = work.prior;
			rqueue[i - 1].num = work.num;
		}
	}
}

RQueue::~RQueue()
{
	delete[]rqueue;
}



void in_graph()
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
		{
			graph[m*i + j].prior = matr[i][j];
			graph[m*i + j].flag = 0;
			if (i + 1<n)
			{
				graph[m*i + j].mas[2].prior = matr[i + 1][j];
				graph[m*i + j].mas[2].atop.i = i + 1;
				graph[m*i + j].mas[2].atop.j = j;
			}
			else
			{
				graph[m*i + j].mas[2].prior = 0;
				graph[m*i + j].mas[2].atop.i = -1;
				graph[m*i + j].mas[2].atop.j = -1;
			}
			if (j - 1 >= 0)
			{
				graph[m*i + j].mas[1].prior = matr[i][j - 1];
				graph[m*i + j].mas[1].atop.i = i;
				graph[m*i + j].mas[1].atop.j = j - 1;
			}
			else
			{
				graph[m*i + j].mas[1].atop.i = -1;
				graph[m*i + j].mas[1].atop.j = -1;
				graph[m*i + j].mas[1].prior = 0;
			}
			if (j + 1<m)
			{
				graph[m*i + j].mas[3].prior = matr[i][j + 1];
				graph[m*i + j].mas[3].atop.i = i;
				graph[m*i + j].mas[3].atop.j = j + 1;
			}
			else
			{
				graph[m*i + j].mas[3].atop.i = -1;
				graph[m*i + j].mas[3].atop.j = -1;
				graph[m*i + j].mas[3].prior = 0;
			}
			if (i - 1 >= 0)
			{
				graph[m*i + j].mas[0].prior = matr[i - 1][j];
				graph[m*i + j].mas[0].atop.i = i - 1;
				graph[m*i + j].mas[0].atop.j = j;
			}
			else
			{
				graph[m*i + j].mas[0].atop.i = -1;
				graph[m*i + j].mas[0].atop.j = -1;
				graph[m*i + j].mas[0].prior = 0;
			}
		}
}

void mfind(PQueue &PQ, RQueue &RQ)
{
	q w1, w2;
	for (int j = 0; j<24; j++)
	{
		anum = j;
		in_graph();
		for (int i = 0; i<n; i++)
			for (int h = 0; h<m; h++)
				curmatr[i][h] = matr[i][h];
		//	graph[m*start.i+start.j].pred.i=-1;
		//	graph[m*start.i+start.j].pred.j=-1;
		graph[m*start.i + start.j].prior = abs(graph[m*start.i + start.j].prior - work[kybik[j][0] - 1]);
		curmatr[start.i][start.j] = graph[m*start.i + start.j].prior;
		while (PQ.num != 0)
			PQ.Delete_min(w1);
		w1.atop.i = start.i;
		w1.atop.j = start.j;
		w1.pred.i = -1;
		w1.pred.j = -1;
		w1.var = j;
		w1.prior = graph[m*start.i + start.j].prior;//abs(graph[m*start.i+start.j].prior-work[kybik[j][0]-1]);
		PQ.Add(w1);
		while ((PQ.num != 0) && (graph[m*end.i + end.j].flag != 1))
		{
			PQ.Delete_min(w2);
			int tw2 = m*w2.atop.i + w2.atop.j;
			if (!graph[tw2].flag)
			{
				graph[tw2].flag = 1;
				if ((w2.pred.i != -1) && (w2.pred.j != -1))
				{
					if ((w2.pred.i - 1 == w2.atop.i) && (w2.pred.j == w2.atop.j))
						graph[tw2].prior = curmatr[w2.pred.i][w2.pred.j] + abs(matr[w2.atop.i][w2.atop.j] - work[kybik[w2.var][0] - 1]);
					if ((w2.pred.i + 1 == w2.atop.i) && (w2.pred.j == w2.atop.j))
						graph[tw2].prior = curmatr[w2.pred.i][w2.pred.j] + abs(matr[w2.atop.i][w2.atop.j] - work[kybik[w2.var][0] - 1]);
					if ((w2.pred.i == w2.atop.i) && (w2.pred.j - 1 == w2.atop.j))
						graph[tw2].prior = curmatr[w2.pred.i][w2.pred.j] + abs(matr[w2.atop.i][w2.atop.j] - work[kybik[w2.var][0] - 1]);
					if ((w2.pred.i == w2.atop.i) && (w2.pred.j + 1 == w2.atop.j))
						graph[tw2].prior = curmatr[w2.pred.i][w2.pred.j] + abs(matr[w2.atop.i][w2.atop.j] - work[kybik[w2.var][0] - 1]);
				}
				curmatr[w2.atop.i][w2.atop.j] = graph[tw2].prior;
				graph[tw2].pred.i = w2.pred.i;
				graph[tw2].pred.j = w2.pred.j;

				for (int i = 0; i<4; i++)
					if (m*graph[tw2].mas[i].atop.i + graph[tw2].mas[i].atop.j >= 0)
						if (graph[m*graph[tw2].mas[i].atop.i + graph[tw2].mas[i].atop.j].flag == 0)
						{
							//graph[m*graph[tw2].mas[i].atop.i+graph[tw2].mas[i].atop.j].pred.i=w2.atop.i;
							//graph[m*graph[tw2].mas[i].atop.i+graph[tw2].mas[i].atop.j].pred.j=w2.atop.j;
							w1.atop.i = graph[tw2].mas[i].atop.i;
							w1.atop.j = graph[tw2].mas[i].atop.j;
							w1.pred.i = w2.atop.i;
							w1.pred.j = w2.atop.j;
							w1.var = step[w2.var][i];
							w1.prior = w2.prior + abs(graph[tw2].mas[i].prior - work[kybik[w1.var][0] - 1]);
							PQ.Add(w1);
						}
			}
		}
		result rwork;
		rwork.grani.clear();
		rwork.prior = graph[m*end.i + end.j].prior;
		rwork.num = anum;
		point a;
		a.i = end.i;
		a.j = end.j;
		int k = m*end.i + end.j;
		while (k != m*start.i + start.j)
		{
			rwork.grani.push_back(a);
			a.i = graph[k].pred.i;
			a.j = graph[k].pred.j;
			k = (m*graph[k].pred.i) + graph[k].pred.j;
		}
		a.i = start.i;
		a.j = start.j;
		rwork.grani.push_back(a);
		RQ.Add(rwork);
	}
}


int main()
{
	fstream fin("input.txt");
	fstream fout("output.txt", ios::out | ios::trunc);
	fin >> n >> m;
	matr = new int*[n];
	for (int i = 0; i<n; i++)
		matr[i] = new int[m];
	for (i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			fin >> matr[i][j];
	curmatr = new int*[n];
	for (i = 0; i<n; i++)
		curmatr[i] = new int[m];
	for (i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			curmatr[i][j] = matr[i][j];

	for (i = 0; i<6; i++)
		fin >> work[i];
	fin >> start.i >> start.j >> end.i >> end.j;
	graph = new top[n*m];
	//in_graph();
	int k = (n - 2)*(m - 2) * 4 + 8 + (n - 2) * 2 * 3 + (m - 2) * 2 * 3;
	PQueue PQ(k);
	RQueue RQ(24);
	mfind(PQ, RQ);
	fout << RQ.rqueue[0].prior << endl;
	cout << RQ.rqueue[0].prior << endl;
	cout << RQ.rqueue[0].num << endl;
	cout << anum << endl;
	for (i = RQ.rqueue[0].grani.size() - 1; i >= 0; i--)
	{
		if (i != 0)
			fout << RQ.rqueue[0].grani[i].i << " " << RQ.rqueue[0].grani[i].j << endl;
		else
			fout << RQ.rqueue[0].grani[i].i << " " << RQ.rqueue[0].grani[i].j;
	}

	/*int j=n*m-1;
	for(j=RQ.rqueue[0].grani.size()-1; j>=0;j--)
	{
	//	{
	fout<<RQ.rqueue[0].grani[j].i<<" "<<RQ.rqueue[0].grani[j].j<<endl;

	//	}
	cout<<" "<<RQ.rqueue[0].prior<<endl;
	/*	for(j=n*m-1; j>=0; j--)
	{

	cout<<graph[j].pred.i<<"  "<<graph[j].pred.j<<endl;
	}*/

	//cout<<RQ.rqueue[0].grani[j].i<<"  "<<RQ.rqueue[0].grani[j].j<<endl;
	//	}
	//	}
	//	cout<<endl;

	fin.close();
	fout.close();
	for (i = 0; i<n; i++)
		delete[]matr[i];
	delete[]matr;
	for (i = 0; i<n; i++)
		delete[]curmatr[i];
	delete[]curmatr;
	return 0;
}