; Ryan Grayson
; rtg5xkh
; PostLab 8			
; LinearSearch.s
; 4/12/2021
; *Note: This is for macOS. For linux compilation, the _ before linearSearch needs to be removed
	
	global _linearSearch

	section .text

_linearSearch:
	;; takes in 3 params: pointer to array(rdi), size of array(rsi), target element(rdx)
	xor	r10, r10	;i = 0

loop:
	cmp	r10, rsi	;does i == arraysize?
	je	notfound	;if so, goto notfound
	mov	eax, [rdi+4*r10];r11 = mem[arrayptr + 4 * i] (which is a[i])
	cmp	rax, rdx	;does a[i] == target?
	je	found		;if so, goto found
	inc	r10		;i++
	jmp	loop		;back to beginning of loop

notfound:
	mov	rax, -1
	ret

found:
	mov	rax, r10	;return i
	ret
