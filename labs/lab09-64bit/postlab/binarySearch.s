; Joshua Tapp

global _binarySearch
section .text

;   rdi : arr pointer   (64 bit pointer)
;   rsi : low           (32 bit integer)
;   rdx : high          (32 bit integer)
;   rcx : target        (32 bit integer)
;   List is sorted, low = index[start], high = index[size - 1], target = search value 

; NOTE: we are using a boundless binary search algorithm. Source: https://github.com/scandum/binary_search/blob/master/binary_search.c
;       I DID NOT DUMP THIS INTO GODBOLT! This is my code alone.

_binarySearch:
        push    rcx             ; we will be modding these, so push to stack for safety.
        push    rdx
        push    rsi
        push    rdi
        push    rbx

        mov     rax, -1         ; This section will test if the input data is bad.
        cmp     edx, -1         ; Which means that size = 0
        je      end             ; if, so, we reject and return -1.
        xor     rax, rax        ; zero out return register

_search_loop:
        cmp     edx, 1          ; 
        jl      _skip2         ; condition(high > 1)

        xor     rbx, rbx
        mov     ebx, edx        ; rbx = high
        shr     ebx, 1          ; rbx = high / 2
        add     ebx, esi        ; rbx += low
        
        cmp     ecx, DWORD [rdi + rbx*4]  ; load array[low+]
        jl      _skip1          ; skip

        lea     ebx, [ebx + 1]  ; this is eqv to
        shr     ebx, 1          ; low += (high + 1) / 2
        add     esi, ebx 

        
_skip1:
        mov     rbx, rdx
        shr     edx, 31
        add     edx, ebx
        shr     edx, 1
        jmp     _search_loop
_skip2:
        lea     rbx, [rdi+rsi]
        cmp     ecx, DWORD [rbx]
        je      _found
        mov     rax, -1
        jmp     end

_found:
        mov     rax, rsi        ; return index of low
end:
        pop     rbx
        pop     rdi
        pop     rsi
        pop     rdx
        pop     rcx
        ret                     ; otherwise return eax, which is the current count, which equals the index.
