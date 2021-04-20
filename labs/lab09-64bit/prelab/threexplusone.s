; Joshua Tapp
; Optimizations:
;               + replaced imult with lea (line 23)
;               + jump straight to even after in odd to save a call (line 24)
;               + The FUNNEL IS COMPLETE! Use hamming weights (bsr) to catch any value that is a power of 2 and jump straight to the answer.
;               + use fast mod2 test (line 19) to decide case.
;               + use shr   rdi, cl (line 39) to handle funnel division so that recursion still works (it shifts until it equals 1)
;               + Im proud of this work, this stuff is very fast for my level of knowledge in x86 assembler.
	global threexplusone
 

	section .text

threexplusone:
        xor     rax, rax ;clean out return register.
        call    recursive
        jmp     done
recursive:
        cmp     rdi, 1  ; check if rdi = 1, if so, we are at base case and can return.
        je      done
        test    dil, 1  ; check if even/odd: got this from: https://stackoverflow.com/questions/49116747/assembly-check-if-number-is-even
        jz      even
odd:
        lea     rdi, [rdi + 2*rdi + 1] ; 3n+1
        inc     rax    ; counter++
even:                  ; we go here now, because we know its even now from odd.
        shr     rdi, 1 ; divide by 2
        inc     rax    ; counter++
        
        ; Source https://www.felixcloutier.com/x86/bsr, https://www.exploringbinary.com/ten-ways-to-check-if-an-integer-is-a-power-of-two-in-c/
        ; This is a 2^x funnel. This will catch the function when its equal to a power of 2 and get us straight to 1!
        mov     rcx, rdi    ; create duplicate rdi value
        neg     rcx         ; takes its 2comp.
        and     rcx, rdi    ; bitwise AND these two regs
        cmp     rcx, rdi    ; If they are equal, we have a power of two.
        jne     end    
        xor     rcx, rcx
        bsr     ebx, edi    ; cool little instruction. returns the sigbit indice to rcx. (log2(2^x) = x) where x = sigbit
        add     rax, rcx    ; add how many /2 it would take.
        shr     rdi, cl     ; using rcx, because of shr req. (i love these little requirements that make debugging an error message fun!)
end:
        call    recursive
done:
        ret
