; Ryan Grayson
; rtg5xkh
; PostLab 9			
; binarySearch.s
; 4/18/2021
; *Note: This is for macOS. For linux compilation, the _ before binarySearch needs to be removed

	global _binarySearch

	section .text

_binarySearch:
	;; params: start of array (rdi), left index (rsi), right index (rdx), target (rcx)

loop:
	cmp	rsi, rdx	;is left > right?
	jg	notfound	;if so, goto notfound
	
	xor	r10, r10	;let r10 represent mid
	add	r10, rsi	;mid = (left + right) / 2
	add	r10, rdx	;
	shr	r10, 1		;

	mov	eax, [rdi+4*r10];let eax = a[mid]

	cmp	rax, rcx	;does a[mid] == target?
	je	found		;if so, goto found

less:	
	cmp	rax, rcx	;is a[mid] < target?
	jge	greater		;if not, skip the next statements
	mov	rsi, r10	;left = mid + 1
	inc	rsi

greater:	
	cmp	rax, rcx	;is a[mid] > target?
	jle	endloop		;if not, skip next statements
	mov	rdx, r10	;right = mid - 1
	dec	rdx

endloop:
	jmp	loop		;back to start of loop
	
notfound:
	mov	rax, -1		;return -1
	ret

found:
	mov	rax, r10	;return mid
	ret
