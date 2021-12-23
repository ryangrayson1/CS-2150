; Ryan Grayson
; rtg5xkh
; PreLab 8
; 4/9/2021
; mathlib.s
; *Note: This is for macOS. For linux compilation, the _ before product and power needs to be removed  

	global _product

	global _power

	section .text

_product:
	;; compute product of 2 ints, a (rdi) and b (rsi)
	;; prologue
	xor	rax, rax	;zero the return register
	xor	r10, r10	;zero i
	inc	r10		;set i to 1

start:
	cmp	rdi, r10	;is a < i?
	jl	done		;if so, done with loop
	add	rax, rsi	;rax += b
	inc	r10		;i++
	jmp	start		;go back to start of loop

done:
	ret


_power:
	;; compute x^y, where x (rdi) and y (rsi) are ints
	mov	rax, rdi	;set return register to rdi

	cmp	rsi, 0		;does y == 0?
	je	bc		;if so, go to base case
	cmp	rsi, 1		;does y == 1?
	je	ret		;if so, return

mult:
	dec	rsi		;rsi--
	call	_power		;recursively call power(rdi, rsi - 1)
	mov	rsi, rax	;copy rax's value into rsi
	call 	_product		;compute rax * rax
ret:
	ret

bc:
	mov	rax, 1		;set rax to 1
	jmp	ret		;and return
	
			
