; linearSearch.s
;
;       
; Parameter 1 (in rdi) is the Array Pointer.
; Parameter 2 (in rsi) is the size.
; Parameter 3 (in rdx) is the target.
; Return value is either -1 (unsucessful) or an integer [0, size) 
; 

global linearSearch
    
section .text

linearSearch:
    ;int = 4 bytes 
    push rdi            ; save array pointer
    mov     rbx, rsi    ; set counter to array size
    xor     rax, rax    ; 0 out return register

for_loop:
    cmp     rbx, 0      ; are we done with loop? (rbx = size - 1) ; like a for loop
    je      not_found   ; if so, we didnt find the target
    mov     eax, dword [rdi]  ; 32 bits - rax = the data at *arr[i]
    cmp     eax, edx  ; compare arr[i] to target
    je      found       ; if arr[i] = target, jmp to found

    add     rdi, 4     ; otherwise, go to arr[i++]
    sub     rbx, 1
    jmp     for_loop        ; continue loop if not found
    
not_found:
    mov     rax, -1     ; return -1
    pop     rdi
    ret     

found:
    mov     rax, rdi    ; rax = &arr[i] where found
    pop     rdi         ; get original arr*
    sub     rax, rdi    ; *arr[i] - *arr[0]
    shr     rax, 2      ; rax / 4 = i
    ret
