#include "stdafx.h"
#include "vermet.h"
#include "ksdoc.h"
#include "anal.h"



UINT vermet(LPVOID pParam) {
	extern char* fa, * LpName;
	extern int l, nn, nhcf, nh;
	int lp, grsum, c11[32] = { 0x00000001,0x00000002,0x00000004,0x00000008,
					   0x00000010,0x00000020,0x00000040,0x00000080,
					   0x00000100,0x00000200,0x00000400,0x00000800,
					   0x00001000,0x00002000,0x00004000,0x00008000,
					   0x00010000,0x00020000,0x00040000,0x00080000,
					   0x00100000,0x00200000,0x00400000,0x00800000,
					   0x01000000,0x02000000,0x04000000,0x08000000,
					   0x10000000,0x20000000,0x40000000,0x80000000 };

	int* ch, NumPatGen = 0;
	extern char* fa;

	MPStruct* mps = (MPStruct*)pParam;
	//CUIntArray *M=(CUIntArray*)pParam;
	CUIntArray* M = &mps->M;

	lp = l / INT_SIZE;
	ch = new int[lp];
	fa = new char[l + 1];


	//srand(1);


	while (nn < nhcf) {
		SendMessage(mps->hw, M->GetAt(3), 0, NumPatGen);
		PatGener(ch, lp);
		NumPatGen++;
		if (nh < M->GetAt(0)) {
			grsum = 0;
			SendMessage(mps->hw, M->GetAt(3), 1, NumPatGen);
			for (int i = 0; i < M->GetAt(1); i++) {
				PatGener(ch, lp);
				NumPatGen++;
				SendMessage(mps->hw, M->GetAt(3), 5, NumPatGen);
				grsum += nh;
				if (nn == nhcf) { SendMessage(mps->hw, M->GetAt(3), 2, NumPatGen); return 1; }
			}
			if (grsum < M->GetAt(2)) { SendMessage(mps->hw, M->GetAt(3), 2, NumPatGen); return 1; }
		}
	}
	SendMessage(mps->hw, M->GetAt(3), 2, NumPatGen);
	delete[] ch;
	delete[] fa;
	return 1;
}

void PatGener(int* ch, int lp) {
	int c11[32] = { 0x00000001,0x00000002,0x00000004,0x00000008,
						   0x00000010,0x00000020,0x00000040,0x00000080,
						   0x00000100,0x00000200,0x00000400,0x00000800,
						   0x00001000,0x00002000,0x00004000,0x00008000,
						   0x00010000,0x00020000,0x00040000,0x00080000,
						   0x00100000,0x00200000,0x00400000,0x00800000,
						   0x01000000,0x02000000,0x04000000,0x08000000,
						   0x10000000,0x20000000,0x40000000,0x80000000 };
	extern int l;
	extern char* fa;


	for (int i = 0; i < lp + 1; i++) ch[i] = rand();//генерация вх. набора
	int k = 0;
	while (k < l) {
		if ((ch[k / INT_SIZE] & c11[((k + 1) % INT_SIZE) - 1]) == 0)
			fa[k + 1] = '0'; else fa[k + 1] = '1';
		k++;
	}
	anal(NULL);
	// delete [] fa;
}
