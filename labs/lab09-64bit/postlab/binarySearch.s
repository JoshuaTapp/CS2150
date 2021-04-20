; Joshua Tapp 
; UVA CS2150 SPR21
; Lab09 Postlab
; This code was written without any reference besides this: https://www.hackerearth.com/practice/algorithms/searching/binary-search/tutorial/
; There was zero use of Godbolt. 

global binarySearch
section .text

;   rdi : arr pointer   (64 bit pointer)
;   rsi : low           (32 bit integer)
;   rdx : high          (32 bit integer)
;   rcx : target        (32 bit integer)
;   rbx : mid           (32 bit integer) - using this for variable of mid value.
;   List is sorted, low = index[start], high = index[size - 1], target = search value 


binarySearch:
        push    rcx             ; we will be modding these, so push to stack for safety.
        push    rdx
        push    rsi
        push    rdi
        push    rbx
        push    r8

        mov     rax, -1         ; This section will test if the input data is bad.
        cmp     edx, -1         ; Which means that size = 0
        je      end             ; if, so, we reject and return -1.
        xor     rax, rax        ; zero out return register

_search_loop:
        cmp     rsi, rdx        ; is low = size ? if so, we have exhausted our choices
        jg      _not_found      ; return -1
        
        ; CALCULATE MID
        lea     rbx, [rdx+rsi]  ; ebx = mid, mid = low + high / 2
        shr     rbx, 1          ; /2

        ; TEST where the target is: 3 cases - low, high, found
        lea     r8, [rdi+rbx*4] ; arr[mid]
        cmp     ecx, DWORD [r8] ; arr[mid] < target
        je      _found          ; arr[mid] == target
        jg      _high           ; arr[mid] > target
        ;LOW CASE
        lea     rdx, [rbx-1]    ; high = mid - 1
        jmp     _search_loop    ; repeat loop
        ;HIGH CASE
_high:
        lea     rsi, [rbx+1]     ; low = mid+1
        jmp     _search_loop    ; repeat loop
_not_found:
        mov     rax, -1         ; when low > high, we return -1, as the target was unfound.
        jmp     end
_found:
        mov     rax, rbx         ; rbx = mid, we will return this value if found
end:
        pop     r8
        pop     rbx
        pop     rdi
        pop     rsi
        pop     rdx
        pop     rcx
        ret                     