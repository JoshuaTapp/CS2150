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
; 
; 
;

    global _product
	global _power

	section .text


; This uses the loop 
_product:
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

_power:

    ret                             ; 