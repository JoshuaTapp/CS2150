; mathlib.s
;
; Purpose : This file contains the implementation of the function
;           product amd power. These respective functions take in
;           two integers (64bit) and perform multiplication (x*y) and 
;           exponent (x^y) operations.
;
; Parameter 1 (in rdi) is the first integer.
; Parameter 2 (in rsi) is the second integer.
; Return value is a long that is the result of the expression (x*y).
; 
; Algorithm adopted from https://www.programiz.com/cpp-programming/examples/power-recursion
; Assembly code my own
;

    global product
	global power

	section .text


; This uses the loop 
product:
    ; Standard prologue:
	xor	rax, rax	    ; zero out the return register.
	mov	rcx, rsi	    ; move "y" to counter register

start:
    add rax, rdi        ; sum+= x | where rax is 'sum' and 'x' is rdi.
    loop start          ; keep looping until rcx = 0  
    ; when rcx = 0, return.
	ret


; Parameter 1 (in rdi) is the base.
; Parameter 2 (in rsi) is the exponent.

power:
    ; startup
    push    rdi                     ; save our parameters to prepare for call.
    push    rsi
    sub     rsp, 16                 ; 2 longs = 16 bytes, from https://uva-cs.github.io/pdr/book/x86-64bit-ccc-chapter.pdf

    cmp     rsi, 0                  ; test base case: exponent = 0
    je      base_case

    
    dec     rsi                     ; recursive call requires exponent be decremented. 
    ; This should have power(rdi = rdi, rsi = rsi - 1)
    call    power                   ; calculate power(x, y-1)

    mov     rsi, rax                ; move return value to our 2nd arguement for product call
    call    product                ; calculate x * x^(y-1)
    jmp     end                     ; jump over base case
base_case:
    mov     rax, 1                  ; return 1 
end:
    add     rsp, 16                 ; This follows calling convention in https://uva-cs.github.io/pdr/book/x86-64bit-ccc-chapter.pdf
    pop     rsi
    pop     rdi
    ret                             ; return the result (rax) for this respective call.