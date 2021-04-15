; University of Virginia
; CS 2150 In-Lab 8
; Spring 2018
; mergeSort.s	

	global _mergeSort
	global _merge

	section .text


; Parameter 1 (rdi) is a pointer to the int array 
; Parameter 2 (rsi) is the left index in the array 
; Parameter 3 (rdx) is the right index in the array
; Return type is void 
_mergeSort:

	; Implement mergeSort here

	; start-up (caller convention)
	push 	rdi
	push	rsi
	push 	rdx

	; Base Case
	cmp		rsi, rdx				; left == right ?
	je		base_case				; if so, jump to base_case
	; Calculate middle value								
	mov		rax, rsi				; rax = left
	add     rax, rdx				; rax = left + right 
    sar		rax, 1					; rax >> 1 === eax / 2, [floored]

	push	rax						; save local middle value
	sub     rsp, 32	 				; 3 pointers and our mid value = 8*4=32

	; LEFT SIDE	
	pop		rdx						; middle value
	pop		rax						; hold on to old right value
	pop		rsi						; left index
	pop		rdi						; arr*
	push	rdi						; restore arr*
	push	rsi						; restore left index			
	push	rax						; restore right index
	push	rdx						; restore middle index
    call    _mergeSort				; recursive call down left sice of array
	
	; RIGHT SIDE
	pop		rsi						; new left index = middle value
	inc		rsi						; new left index = middle + 1
	pop		rdx						; new right index = old right index
	pop		rax						; save left index
	pop		rdi						; arr*

	push	rdi						; restore arr*
	push	rax						; restore left index
	push	rdx						; restore right index
	push 	rsi						; restore new middle index
    call    _mergeSort
	; MERGE
	pop		rdx						; middle
	pop		rcx						; right
	pop		rsi						; left
	pop		rdi						; arr*

	push 	r10						; callee safe
	push 	r11
    call    _merge
	pop 	r11
	pop		r10
base_case:								; we only have 1 element in arr.
	add		rsp, 32					; add back spacer
	ret								; do nothing, just return out.





; Parameter 1 is a pointer to the int array 
; Parameter 2 is the left index in the array
; Parameter 3 is the middle index in the array 
; Parameter 4 is the right index in the array
; Return type is void 
_merge:
	; Save callee-save registers
	; Store local variables 
	push rbx			; int i
	push r12			; int j
	push r13			; int k
	push r14			; int n1
	push r15			; int n2
	
	mov r14, rdx			; n1 = mid - left + 1
	sub r14, rsi
	inc r14

	mov r15, rcx			; n2 = right - mid 
	sub r15, rdx

	lea r11, [r14+r15]		; r11 = rsp offset = 4(n1 + n2)
	lea r11, [4*r11]		
	sub rsp, r11			; allocate space for temp arrays

	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	
; Copy elements of arr[] into L[]	
copyLloop:
	cmp rbx, r14			; is i >= n1?
	jge copyRloop
					; L[i] = arr[left + i]
	lea r10, [rsi+rbx]		
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[left + i]
	mov DWORD [rsp+4*rbx], r10d	; L[i] = r10
	inc rbx				; i++
	jmp copyLloop

; Copy elements of arr[] into R[]
copyRloop:
	cmp r12, r15			; is j >= n2?
	jge endcopyR
 					; R[j] = arr[mid + 1 + j]
	lea r10, [rdx+r12+1]	
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[mid + 1 + j]
	lea rax, [r12+r14]		
	mov DWORD [rsp+4*rax], r10d	; R[j] = r10
	inc r12				; j++
	jmp copyRloop

endcopyR:	
	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	mov r13, rsi			; k = left

; Merge L[] and R[] into arr[]
mergeLoop:
	cmp rbx, r14			; is i >= n1 or j >= n2?
	jge loopL
	cmp r12, r15
	jge loopL
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	; r10d = R[j]
	cmp DWORD [rsp+4*rbx], r10d	; is L[i] <= R[j]?
	jle if
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]
	inc r12				; j++
	jmp endif 
if:
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i] 
	inc rbx				; i++
endif:	
	inc r13				; k++	
	jmp mergeLoop
	
; Copy elements of L[] into arr[]
loopL:				
	cmp rbx, r14			; is i >= n1?
	jge loopR
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i]
	inc rbx				; i++
	inc r13				; k++
	jmp loopL

; Copy elements of R[] into arr[]
loopR:	
	cmp r12, r15			; is j >= n2?
	jge endR
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]

	inc r12				; j++
	inc r13				; k++
	jmp loopR
	
endR:
	; deallocate temp arrays
	; restore callee-save registers
	add rsp, r11	
	pop r15			
	pop r14
	pop r13
	pop r12
	pop rbx
	ret
