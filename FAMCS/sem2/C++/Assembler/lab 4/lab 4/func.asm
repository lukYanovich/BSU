.386

public sort1
public _sort2@8
public @sort3@8

.model flat
.data

n dd 0
count dd 0
maxCount dd 0
k dd 0
temp dd 0
p1 dd 0
p2 dd 0

.code


; -----------------------  1. extern "C" int _cdecl sort1(int*, int)  -------------------------


sort1 proc c, arr: dword, n_: dword	
		
		mov		eax, arr
		mov		edi, n_
		mov		n, edi

		add		edi, edi
		add		edi, edi	; в edi лежит размер массива в байтах

		push	ebp
		mov		ebp, esp
		sub		esp, edi
		mov		ebx, esp	; в ebx лежит второй массив с счётчиками

		sub		esp, edi
		mov		edx, esp	; в edx лежит третий массив - сортированный согласно с заданием
		

		xor		ecx, ecx
		m1001:
			mov		edi, 1
			mov		[ebx][4*ecx], edi
			inc		ecx
			cmp		ecx, n
			jb		m1001


		xor		ecx, ecx
		mov		temp, edx
		m1002:	;forOut
			mov		esi, [ebx][4 * ecx]
			cmp		esi, 0
			je		m1003

			mov		edx, ecx
			inc		edx
			m1004:	;forIn
				mov		edi, [eax][4 * ecx]
				cmp		edi, [eax][4 * edx]
				jne		m1005
					xor		edi, edi
					mov		[ebx + 4 * edx], edi
					mov		edi, [ebx][4 * ecx]
					inc		edi
					mov		[ebx + 4 * ecx], edi
				m1005:	;falseCompare
				inc		edx
				cmp		edx, n
				jl		m1004

		m1003:	;checkForOut
			inc		ecx
			mov		edi, n
			dec		edi
			cmp		ecx, edi
			jl		m1002


		xor		ecx, ecx
		mov		count, ecx
		mov		edx, temp
		m1006:	;forever
			xor		ecx, ecx
			mov		maxCount, ecx
			mov		k, ecx

			m1007:	;for
				mov		esi, maxCount
				cmp		[ebx][4 * ecx], esi
				jle		m1008		 
					mov		esi, [ebx][4 * ecx]
					mov		maxCount, esi
					mov		k, ecx
				m1008:	;false
				inc		ecx
				cmp		ecx, n
				jl		m1007

			cmp		maxCount, 0
			je	m1009

			mov		edi, count
			mov		esi, k
			mov		temp, ebx
			mov		ebx, [eax][4 * esi]
			mov		[edx][4 * edi], ebx
			mov		ebx, temp
			inc		edi
			mov		count, edi
			xor		edi, edi
			mov		[ebx][4 * esi], edi

			jmp		m1006

		m1009:	;endForever

		xor		ecx, ecx
		m1010:	;for
			mov		ebx, [edx][4 * ecx]
			mov		[eax][4 * ecx], ebx
			inc		ecx
			cmp		ecx, count
			jl		m1010
		
		mov		eax, count

	leave
	ret
sort1 endp


; -----------------------  2. extern "C" int _stdcall sort2(int*, int)  -------------------------


_sort2@8 proc	
		
		push	ebp
		mov		ebp, esp

		mov		eax, [ebp + 8]
		mov		edi, [ebp + 12]
		mov		n, edi

		add		edi, edi
		add		edi, edi	; в edi лежит размер массива в байтах

		sub		esp, edi
		mov		ebx, esp	; в ebx лежит второй массив с счётчиками

		sub		esp, edi
		mov		edx, esp	; в edx лежит третий массив - сортированный согласно с заданием
		

		xor		ecx, ecx
		m2001:
			mov		edi, 1
			mov		[ebx][4*ecx], edi
			inc		ecx
			cmp		ecx, n
			jb		m2001


		xor		ecx, ecx
		mov		temp, edx
		m2002:	;forOut
			mov		esi, [ebx][4 * ecx]
			cmp		esi, 0
			je		m2003

			mov		edx, ecx
			inc		edx
			m2004:	;forIn
				mov		edi, [eax][4 * ecx]
				cmp		edi, [eax][4 * edx]
				jne		m2005
					xor		edi, edi
					mov		[ebx + 4 * edx], edi
					mov		edi, [ebx][4 * ecx]
					inc		edi
					mov		[ebx + 4 * ecx], edi
				m2005:	;falseCompare
				inc		edx
				cmp		edx, n
				jl		m2004

		m2003:	;checkForOut
			inc		ecx
			mov		edi, n
			dec		edi
			cmp		ecx, edi
			jl		m2002


		xor		ecx, ecx
		mov		count, ecx
		mov		edx, temp
		m2006:	;forever
			xor		ecx, ecx
			mov		maxCount, ecx
			mov		k, ecx

			m2007:	;for
				mov		esi, maxCount
				cmp		[ebx][4 * ecx], esi
				jle		m2008		 
					mov		esi, [ebx][4 * ecx]
					mov		maxCount, esi
					mov		k, ecx
				m2008:	;false
				inc		ecx
				cmp		ecx, n
				jl		m2007

			cmp		maxCount, 0
			je	m2009

			mov		edi, count
			mov		esi, k
			mov		temp, ebx
			mov		ebx, [eax][4 * esi]
			mov		[edx][4 * edi], ebx
			mov		ebx, temp
			inc		edi
			mov		count, edi
			xor		edi, edi
			mov		[ebx][4 * esi], edi

			jmp		m2006

		m2009:	;endForever

		xor		ecx, ecx
		m2010:	;for
			mov		ebx, [edx][4 * ecx]
			mov		[eax][4 * ecx], ebx
			inc		ecx
			cmp		ecx, count
			jl		m2010
		
		mov		eax, count

	leave
	ret 8 
_sort2@8 endp


; -----------------------  3. extern "C" int _fastcall sort3(int*, int)  -------------------------


@sort3@8 proc	
		
		mov		eax, ecx
		mov		edi, edx
		mov		n, edi

		add		edi, edi
		add		edi, edi	; в edi лежит размер массива в байтах

		push	ebp
		mov		ebp, esp
		sub		esp, edi
		mov		ebx, esp	; в ebx лежит второй массив с счётчиками

		sub		esp, edi
		mov		edx, esp	; в edx лежит третий массив - сортированный согласно с заданием
		

		xor		ecx, ecx
		m1001:
			mov		edi, 1
			mov		[ebx][4*ecx], edi
			inc		ecx
			cmp		ecx, n
			jb		m1001


		xor		ecx, ecx
		mov		temp, edx
		m1002:	;forOut
			mov		esi, [ebx][4 * ecx]
			cmp		esi, 0
			je		m1003

			mov		edx, ecx
			inc		edx
			m1004:	;forIn
				mov		edi, [eax][4 * ecx]
				cmp		edi, [eax][4 * edx]
				jne		m1005
					xor		edi, edi
					mov		[ebx + 4 * edx], edi
					mov		edi, [ebx][4 * ecx]
					inc		edi
					mov		[ebx + 4 * ecx], edi
				m1005:	;falseCompare
				inc		edx
				cmp		edx, n
				jl		m1004

		m1003:	;checkForOut
			inc		ecx
			mov		edi, n
			dec		edi
			cmp		ecx, edi
			jl		m1002


		xor		ecx, ecx
		mov		count, ecx
		mov		edx, temp
		m1006:	;forever
			xor		ecx, ecx
			mov		maxCount, ecx
			mov		k, ecx

			m1007:	;for
				mov		esi, maxCount
				cmp		[ebx][4 * ecx], esi
				jle		m1008		 
					mov		esi, [ebx][4 * ecx]
					mov		maxCount, esi
					mov		k, ecx
				m1008:	;false
				inc		ecx
				cmp		ecx, n
				jl		m1007

			cmp		maxCount, 0
			je	m1009

			mov		edi, count
			mov		esi, k
			mov		temp, ebx
			mov		ebx, [eax][4 * esi]
			mov		[edx][4 * edi], ebx
			mov		ebx, temp
			inc		edi
			mov		count, edi
			xor		edi, edi
			mov		[ebx][4 * esi], edi

			jmp		m1006

		m1009:	;endForever

		xor		ecx, ecx
		m1010:	;for
			mov		ebx, [edx][4 * ecx]
			mov		[eax][4 * ecx], ebx
			inc		ecx
			cmp		ecx, count
			jl		m1010
		
		mov		eax, count

	leave
	ret
@sort3@8 endp

end